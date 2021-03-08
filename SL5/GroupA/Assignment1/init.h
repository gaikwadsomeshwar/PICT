#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace std;

typedef struct table {
  string opcode;
  int size;
  string tipe;
  int operands;
} table;

typedef struct table2 {
  int LOC;
  int value;
} table2;

map<string, table> MOT;
map<string, table2> symTab;
vector<table2> litTab;
map<string, string> registers;

void initMOT() {

  table row;

  row.opcode = "00";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 0;
  MOT["STOP"] = row;

  row.opcode = "01";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["ADD"] = row;

  row.opcode = "02";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["SUB"] = row;

  row.opcode = "03";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["MULT"] = row;

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

  row.opcode = "06";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["DIV"] = row;

  row.opcode = "07";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 1;
  MOT["BC"] = row;

  row.opcode = "08";
  row.size = 2;
  row.tipe = "IS";
  row.operands = 2;
  MOT["COMP"] = row;

  row.opcode = "09";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 1;
  MOT["READ"] = row;

  row.opcode = "10";
  row.size = 1;
  row.tipe = "IS";
  row.operands = 1;
  MOT["PRINT"] = row;

  row.opcode = "06";
  row.size = 2;
  row.tipe = "DL";
  row.operands = 2;
  MOT["DS"] = row;

  row.opcode = "07";
  row.size = 2;
  row.tipe = "DL";
  row.operands = 2;
  MOT["DC"] = row;

  row.opcode = "01";
  row.size = 1;
  row.tipe = "AD";
  row.operands = 0;
  MOT["START"] = row;

  row.opcode = "02";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 1;
  MOT["ORIGIN"] = row;

  row.opcode = "03";
  row.size = 0;
  row.tipe = "AD";
  row.operands = 0;
  MOT["LTORG"] = row;

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
}

void initReg() {
  registers["AREG"] = "01";
  registers["BREG"] = "02";
  registers["CREG"] = "03";
  registers["DREG"] = "04";
}

void generateTextFiles() {

  ofstream fout;
  fout.open("/Users/someshwargaikwad/MyFiles/PICT/SL5/GroupA/Assignment2/symTab.txt");
  for(auto itr = symTab.begin(); itr != symTab.end(); itr++) {
    fout<< itr->first<< ","<< itr->second.LOC<< ","<<itr->second.value<< endl;
  }
  fout.close();

  fout.open("/Users/someshwargaikwad/MyFiles/PICT/SL5/GroupA/Assignment2/litTab.txt");
  for(auto itr = litTab.begin(); itr != litTab.end(); itr++) {
    fout<< itr->value<< ","<< itr->LOC<< endl;;
  }
  fout.close();
}
