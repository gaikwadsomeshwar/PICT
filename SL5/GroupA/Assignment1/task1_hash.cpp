#include <iostream>
#include <fstream>
using namespace std;

typedef struct table {

  string mnemonic = "";
  string opcode = "";
  int size = 0;
  string tipe = "";
  int operands = 0;
  int nextAddr = -1;
} table;

table MOT[18];

void init() {

  MOT[0].mnemonic =
  MOT[0].opcode =
  MOT[0].size =
  MOT[0].tipe =
  MOT[]


   = {
    { "ADD", "01", 2, "IS", 2, -1 },
    { "BC", "07", 2, "IS", 1, -1 },
    { "COMP", "06", 2, "IS", 2, -1 },
    { "DC", "01", 2, "DL", 2, 4 },
    { "DIV", "08", 2, "IS", 2, 5 },
    { "DS", "02", 2, "DL", 2, -1 },
    { "END", "04", 0, "AD", 0, 7 },
    { "EQU", "05", 0, "AD", 1, -1 },
    { "LTORG", "03", 0, "AD", 0, -1 },
    { "MOVER", "04", 3, "IS", 2, 10 },
    { "MOVERM", "05", 4, "IS", 2, 11 },
    { "MULT", "03", 2, "IS", 2, -1 },
    { "ORIGIN", "02", 0, "AD", 1, -1 },
    { "PRINT", "10", 1, "IS", 1, -1 },
    { "READ", "09", 1, "IS", 1, -1 },
    { "START", "01", 0, "AD", 0, 16 },
    { "STOP", "00", 1, "IS", 0, 17 },
    { "SUB", "02", 2, "IS", 2, -1 }
  }
}

int hashing(char ch) {

  switch(ch) {

    case 'A': return 0;
    case 'B': return 1;
    case 'C': return 2;
    case 'D': return 3;
    case 'E': return 6;
    case 'L': return 8;
    case 'M': return 9;
    case 'O': return 12;
    case 'P': return 13;
    case 'R': return 14;
    case 'S': return 15;
    default: return -1;
  }
}

int handleHash(string mnemonic, int i) {

  while(i != -1) {
    if(MOT[i].mnemonic.compare(mnemonic) == 0) {
      return i;
    }
    i = MOT[i].nextAddr;
  }
  return i;
}

int main() {

  cout<< endl;
  init();
  ifstream fin;
  string line;

  fin.open("file.txt");
  int i = 0;

  //Separating individual words
  while(getline(fin, line)) {

    int count = 0;
    string word = "";

    cout<< "========================"<< endl;
    cout<< ++i<< "] "<< line<< endl<< endl;
    cout<< "+-+-+-+-+-+-+-+"<< endl;
    cout<< "Opcodes:"<< endl<< endl;
    for(auto ch: line) {

      if(ch == ' ') {
        count++;
        //finding the word in the opcode table
        int index = handleHash(word, hashing(word.at(0)));
        if(index != -1) {
          cout<< MOT[index].mnemonic<< MOT[index].opcode<< endl;
        }
        word = "";
      }
      else {
        word = word + ch;
      }
    }

    //Last Word Handling
    if(word.length() > 0) {
      count++;
      //finding the word in the opcode table
      int index = handleHash(word, hashing(word.at(0)));
      if(index != -1) {
        cout<< MOT[index].mnemonic<< MOT[index].opcode<< endl;
      }
      word = "";
    }

    cout<< "+-+-+-+-+-+-+-+"<< endl;
    cout<< endl<< "Number of Words: "<< count <<endl;
  }
  cout<< "========================"<< endl;
  fin.close();
  return 0;
}
