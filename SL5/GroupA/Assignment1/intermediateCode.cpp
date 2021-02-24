#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
using namespace std;

typedef struct table {

  string opcode;
  int size;
  string tipe;
  int operands;
} table;

typedef struct table2 {

  string symbol;
  int LOC;
  int value;
} table2;

map<string, table> MOT;
map<string, table2> symTab;
map<string, table2> litTab;
map<string, table2> registers;
int LC = 0;

// MOT table

void initMOT() {

//Initializtion of MOT table
  table row;

  row.opcode = "01";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["ADD"] = row;

  row.opcode = "07";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 1;
  MOT["BC"] = row;

  row.opcode = "06";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["COMP"] = row;

  row.opcode = "01";
  row.size = 2;
  row.tipe = "DL";
  row.operands = 2;
  MOT["DC"] = row;

  row.opcode = "08";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["DIV"] = row;

  row.opcode = "02";
  row.size = 2;
  row.tipe = "DL";
  row.operands = 2;
  MOT["DS"] = row;

  row.opcode = "04";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 0;
  MOT["END"] = row;

  row.opcode = "05";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 1;
  MOT["EQU"] = row;

  row.opcode = "03";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 0;
  MOT["LTORG"] = row;

  row.opcode = "04";
  row.size = 3;
  row.tipe = "IS";
  row.operands = 2;
  MOT["MOVER"] = row;

  row.opcode = "05";
  row.size = 4;
  row.tipe = "IS";
  row.operands = 2;
  MOT["MOVERM"] = row;

  row.opcode = "03";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["MULT"] = row;

  row.opcode = "02";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 1;
  MOT["ORIGIN"] = row;

  row.opcode = "10";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 1;
  MOT["PRINT"] = row;

  row.opcode = "09";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 1;
  MOT["READ"] = row;

  row.opcode = "01";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 0;
  MOT["START"] = row;

  row.opcode = "00";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 0;
  MOT["STOP"] = row;

  row.opcode = "02";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["SUB"] = row;
}

void initReg() {

  table2 row;

  row.symbol = "AREG";
  row.value = 1;
  registers["AREG"] = row;

  row.symbol = "BREG";
  row.value = 2;
  registers["BREG"] = row;

  row.symbol = "CREG";
  row.value = 3;
  registers["CREG"] = row;

  row.symbol = "DREG";
  row.value = 4;
  registers["DREG"] = row;
}

bool findRegisters(string word) {

  map<string, table2>::iterator itrReg = registers.find(word);
  if(itrReg != registers.end()) {
    cout<< " \t ( "<< itrReg->second.value<< " ) \t ";
    return true;
  }
  return false;
}

bool findInsts(string word) {

  map<string, table>::iterator itrMOT = MOT.find(word);
  if(itrMOT != MOT.end()) {
    LC = LC + itrMOT->second.size;
    cout<< LC<< " \t ( "<< itrMOT->second.tipe<< ", "<< itrMOT->second.opcode<< " ) \t ";
    return true;
  }
  return false;
}

bool findLabels(string word) {

  map<string, table2>::iterator itrSymTab = symTab.find(word);
  if(itrSymTab != symTab.end()) {
    return true;
  }
  return false;
}

bool findSymbols(string word) {

  map<string, table2>::iterator itrSymTab = symTab.find(word);
  if(itrSymTab != symTab.end()) {
    cout<< " \t ( S, "<< itrSymTab->first<< " ) \t ";
    return true;
  }
  return false;
}

bool findLiterals(string word) {

  map<string, table2>::iterator itrLitTab = litTab.find(word);
  return true;
}

int main() {

  cout<< endl;
  initMOT();
  initReg();

  ifstream fin;
  string line, word = "";

  fin.open("file.txt");
  cout<< "LC \t Opcode \t Operand 1 \t Operand 2"<< endl<< endl;

  getline(fin, line);
  if((line.substr(0,5)).compare("START") == 0) {
    cout<< " \t ( "<< MOT.at("START").tipe<< ", "<< MOT.at("START").opcode<< " ) \t";
    if(line.length() > 6) {
      LC += stoi(line.substr(6));
    }
  }
  else {
    cout<< "Error"<< endl<< endl;
    return 0;
  }

  if(word.length() > 0) {
    LC += stoi(word);
  }
  cout<< endl;

  //Separating individual words
  while(getline(fin, line) && line.compare("STOP") != 0) {

    word = line.substr(0, line.find(' '));
    if(!findInsts(word)) {
      if(!findLabels(word)) {
        table2 row;
        row.symbol = word;
        symTab[word] = row;
      }
    }

    word = "";
    line = line.substr(line.find(' ') + 1);
    for(auto ch: line) {

      if(ch == ' ') {
        if(!findRegisters(word)) {
          if(!findInsts(word)) {
            if(!findSymbols(word)) {
              table2 row;
              row.symbol = word;
              symTab[word] = row;
              cout<< " \t ( S, "<< word<< " ) \t ";
            }
          }
        }
        word = "";
      }
      else {
        word = word + ch;
      }
    }

    //Last Word Handling
    if(word.length() > 0) {
      if(!findRegisters(word)) {
        if(!findInsts(word)) {
          if(!findSymbols(word)) {
            table2 row;
            row.symbol = word;
            symTab[word] = row;
            cout<< " \t ( S, "<< word<< " ) \t ";
          }
        }
      }
    }
    cout<<endl;
  }
  cout<< endl<< endl;
  fin.close();
  return 0;
}
