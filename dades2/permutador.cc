#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int NUM_PER = 25;

void permuta(char c) {
  string fitxer = "document";
  fitxer += c;
  fitxer += ".txt";

  ifstream stream;
  stream.open(fitxer);
  vector <string> paraules;
  string paraula;
  while (getline(stream, paraula)) {
    paraules.push_back(paraula);;
  }
  stream.close();

  for (int i = 0; i < NUM_PER; i++) {
    random_shuffle(paraules.begin(), paraules.end());

    string fitxer2 = "document";
    fitxer2 += c + 1 + i;
    fitxer2 += ".txt";
    ofstream stream2;
    stream2.open(fitxer2);
    for (int j = 0; j < int(paraules.size()); j++) {
      if (j > 0)
        stream2 << endl;
      stream2 << paraules[j];
    }
    stream2.close();
  }
}

int main() {
  permuta('a');
  permuta('A');
}
