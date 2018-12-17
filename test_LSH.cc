#include "hash.h"
#include "parser.h"
#include "LSH.h"
#include<iostream>
#include<iomanip>


using namespace std;

int main(int argc, char *argv[]) {
  int n = 52;
  int val = 0;
  cout << "Quines dades voleu fer servir? (1 o 2): ";
  cin >> val;
  if (val == 1) n = 20;
  vector<string> V1(n);
  if (val == 2) {
    for (int i = 0; i < n/2; ++i) {
      string name = "dades2/document" + string(1,char('A' + i)) + ".txt";
      V1[i] = text(name);
    }
    for (int i = 0; i < n/2; ++i) {
      string name = "dades2/document" + string(1,char('a' + i)) + ".txt";
      V1[n/2 + i] = text(name);
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      string name = "dades1/document" + string(1,char('A' + i)) + ".txt";
      V1[i] = text(name);
    }
  }
  cout << "Test de l'algorism LSH fent servir els documents de dades" << val << endl;
  int h, k, b;
  double threshold;
  cout << "Indica el nombre h de files de la taula de minhash: ";
  cin >> h;
  cout << "Indica el valor k de la longitud dels shingles: ";
  cin >> k;
  cout << "Indica el nombre b de seccions en les que es divideixen les columnes de la taula de minhash: ";
  cin >> b;
  cout << "Indica el valor (entre 0 i 1) de threshold a partir del qual dos textos es consideren similars: ";
  cin >> threshold;
  cout << "Indiqueu quines funcions de hash voleu fer servir linear=1, quadratic=2, bit_permutation=3: ";
  int func_hash;
  long long mod;
  cin >> func_hash;
  if (func_hash == 1 or func_hash == 2) {
    cout << "Quin valor de mod voleu per la funcio de hash? ";
    cin >> mod;
  }
  vector<function<long long(long long)> > H1;
  if (func_hash == 1) H1 = linear_hash(h, mod);
  else if (func_hash == 2) H1 = quadratic_hash(h, mod);
  else H1 = bit_permutation_hash(h);
  clock_t time1 = clock();
  set<pair<int,int> > D = LSH(n,k,h,b,threshold,V1,H1);
  clock_t time2 = clock();
  cout << "L'algorisme ha tardat " << fixed << setprecision(10) << (long double)(time2 - time1)/CLOCKS_PER_SEC << " segons\n";
  cout << "Parelles de textos similars:\n";
  for (auto p : D) {
    cout << "document";
    if (p.first < 26) cout << char('A' + p.first);
    else cout << char('a' + p.first- 26);
    cout << " document";
    if (p.second < 26) cout << char('A' + p.second);
    else cout << char('a' + p.second -26);
    cout << endl;
  }
}
