#include "parser.h"
#include <iostream>
#include <set>
#include <vector>

const int P = (1 << 20) - 3; //un primer proper al milio
const int B = 27; //26 lletres i l'espai

//O(nklogn)
set <string> shinglesString(string text, int k) {
  set <string> shingles;
  int n = text.size();
  for (int i = 0; i < n-k; i++) {
    string paraula;
    for (int j = 0; j < k; j++)
      paraula += text[i+j];
    shingles.insert(paraula);
  }
  return shingles;
}

//O(nk)
double jaccard(set <string> a, set <string> b) {
  double interseccio = 0;

  set <string>::iterator ita, itb;
  ita = a.begin();
  itb = b.begin();
  while (ita != a.end() and itb != b.end()) {
    if (*ita == *itb) {
      interseccio++;
      ita++;
      itb++;
    } else if (*ita < *itb) {
      ita++;
    } else {
      itb++;
    }
  }
  
  double unio = a.size() + b.size() - interseccio;

  if (unio == 0)
    return NULL;
  return interseccio/unio;
}

int valor(char c) {
  if (c == ' ')
    return 26;
  else
    return c - 'a';
}

int hasha(string s) {
  int hash = 0;
  for (int i = 0; i < int(s.size()); i++)
    hash = (hash*B + valor(s[i])) % P;
  return hash;
}

//O(nkE) = O(nkn/p)
double jaccard(string a, string b, int k) {
  double unio = 0;
  double interseccio = 0;

  vector < vector <string> > shinglesA = vector < vector <string> >(P);
  int nA = a.size();
  for (int i = 0; i < nA-k; i++) {
    string paraula;
    for (int j = 0; j < k; j++)
      paraula += a[i+j];
    int hashParaula = hasha(paraula);

    bool present = false;
    for (int j = 0; j < int(shinglesA[hashParaula].size()); j++) {
      if (shinglesA[hashParaula][j] == paraula) {
        present = true;
        break;
      }
    }

    if (not present) {
      shinglesA[hashParaula].push_back(paraula); 
      unio++;
    }
  }

  vector < vector <string> > shinglesB = vector < vector <string> >(P);
  int nB = b.size();
  for (int i = 0; i < nB-k; i++) {
    string paraula;
    for (int j = 0; j < k; j++)
      paraula += b[i+j];
    int hashParaula = hasha(paraula);

    bool present = false;
    for (int j = 0; j < int(shinglesB[hashParaula].size()); j++) {
      if (shinglesB[hashParaula][j] == paraula) {
        present = true;
        break;
      }
    }

    if (not present) {
      shinglesB[hashParaula].push_back(paraula);

      bool presentA = false;
      for (int j = 0; j <int(shinglesA[hashParaula].size()); j++) {
        if (shinglesA[hashParaula][j] == paraula) {
          presentA = true;
          break;
        }
      }

      if (presentA) {
        interseccio++;
      } else
        unio++;
    }
  }

  if (unio == 0)
    return NULL;
  return interseccio/unio;
}

int main() {
  int k = 5;

  string entrada1 = "dades2/documentA.txt";
  string text1 = text(entrada1);
  string entrada2 = "dades2/documentB.txt";
  string text2 = text(entrada2);

  set <string> a = shinglesString(text1, k);
  set <string> b = shinglesString(text2, k);

  cout << jaccard(a, b) << endl;
  cout << jaccard(text1, text2, k) << endl;
}

