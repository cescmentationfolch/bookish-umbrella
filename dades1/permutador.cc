#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int NUM_PAR = 50;
const int NUM_PER = 20;

int main() {
  ifstream stream;
  stream.open("documentA.txt");
  vector <string> paraules(NUM_PAR);
  for (int i = 0; i < NUM_PAR; i++)
    stream >> paraules[i];
  stream.close();

  for (int i = 0; i < NUM_PER; i++) {
    random_shuffle(paraules.begin(), paraules.end());

    string fitxer = "document";
    fitxer += 'B' + i;
    fitxer += ".txt";
    ofstream stream2;
    stream2.open(fitxer);
    for (int j = 0; j < NUM_PAR; j++) {
      if (j > 0)
        stream2 << ' ';
      stream2 << paraules[j];
    }
    stream2.close();
  }
}
