#include "parser.h"
#include <fstream>

//O(n)
string text(string fitxer) {
  ifstream stream;
  stream.open(fitxer);
  string text;
  string paraula;
  char c = 'a';
  while (stream >> paraula) {
    if (c != ' ')
      text += ' ';
    for (int i = 0; i < int(paraula.size()); i++) {
      c = paraula[i];
      int canvi = 'A' - 'a';
      if (c >= 'a' and c <= 'z')
        text += c;
      else if (c >= 'A' and c <= 'Z')
        text += c - canvi;
      else if (c >= '0' and c <= '9')
        text += c;
    }
  }
  stream.close();
  return text;
}

