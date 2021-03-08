// Work on Different Types, eliminate before and after
#include "init.h"

map<string, table>::iterator itrMOT;
map<string, table2>::iterator itrSymTab;
vector<table2>::iterator itrLitTab;
map<string, string>::iterator itrRegisters;

int LC = 0;
ofstream fout;

void handleLTORG() {
  for(auto itr = litTab.begin(); itr != litTab.end(); itr++) {
    if(itr->LOC == -1) {
      itr->LOC = ++LC;
      fout<< LC<< "\t-\t-\t(="<< itr->value<< ")"<< endl;
    }
  }
}

int search(string str) {
  for(auto itr = litTab.begin(); itr != litTab.end(); itr++) {
    if(itr->value == stoi(str.substr(2, str.length() - 1)) && itr->LOC != -1) {
      return 1;
    }
  }
  return 0;
}

int handleDL(vector<string> result) {

  itrSymTab = symTab.find(result[0]);
  if(itrSymTab == symTab.end()) {
    table2 row;
    row.LOC = LC;
    row.value = 0;
    symTab[result[0]] = row;
  }
  else {
    itrSymTab->second.LOC = LC;
  }

  itrMOT = MOT.find(result[1]);
  if(itrMOT != MOT.end() && itrMOT->second.operands == result.size() - 1) {
    fout<< "\t("<< itrMOT->second.tipe<< ","<< itrMOT->second.opcode<< ")";
  }
  else {
    return 0;
  }

  if(result[2].find("=") != string::npos) {
    if(!search(result[2])) {
      table2 row;
      row.LOC = -1;
      row.value = stoi(result[2].substr(2, result[2].length() - 1));
      symTab[result[0]].value = row.value;
      litTab.push_back(row);
    }
    fout<< "\t-\t(L,"<< result[2].substr(1)<< ")"<< endl;
  }
  else {
    itrSymTab = symTab.find(result[2]);
    if(itrSymTab != symTab.end()) {
      symTab[result[0]].value = symTab[result[2]].value;
      fout<< "\t-\t(S,"<< result[2]<< ")"<< endl;
    }
    else {
      symTab[result[0]].value = stoi(result[2]);
      fout<< "\t-\t(C,"<< result[2]<< ")"<< endl;
    }
  }
  if(itrMOT->first.compare("DS") == 0) {
    LC += symTab[result[0]].value;
  }
  else {
    LC += itrMOT->second.size;
  }

  return 1;
}

int handleSize1(vector<string> result) {
  itrMOT = MOT.find(result[0]);
  if(itrMOT != MOT.end() && itrMOT->second.operands == result.size() - 1) {
    fout<< "\t("<< itrMOT->second.tipe<< ","<< itrMOT->second.opcode<< ")"<< endl;
    if(itrMOT->first.compare("END") == 0) {
      handleLTORG();
    }
    LC += itrMOT->second.size;
    return 1;
  }
  return 0;
}

int handleSize2(vector<string> result) {
  itrMOT = MOT.find(result[0]);
  if(itrMOT != MOT.end() && itrMOT->second.operands == result.size() - 1) {
    fout<< "\t("<< itrMOT->second.tipe<< ","<< itrMOT->second.opcode<< ")"<< endl;
    LC += itrMOT->second.size;
    return 1;
  }
  return 0;
}

int handleSize3(vector<string> result) {

  itrMOT = MOT.find(result[1]);
  if(itrMOT != MOT.end() && itrMOT->second.operands == result.size() - 1 && itrMOT->second.tipe.compare("DL") == 0) {
    return handleDL(result);
  }

  itrMOT = MOT.find(result[0]);
  if(itrMOT != MOT.end() && itrMOT->second.operands == result.size() - 1) {
    fout<< "\t("<< itrMOT->second.tipe<< ","<< itrMOT->second.opcode<< ")";
    LC += itrMOT->second.size;
  }
  else {
    return 0;
  }

  itrRegisters = registers.find(result[1]);
  if(itrRegisters != registers.end()) {
    fout<< "\t("<< itrRegisters->second<< ")";
  }
  else {
    return 0;
  }

  if(result[2].find("=") != string::npos) {
    if(!search(result[2])) {
      table2 row;
      row.LOC = -1;
      row.value = stoi(result[2].substr(2, result[2].length() - 1));
      litTab.push_back(row);
    }
    fout<< "\t(L,"<< result[2].substr(1)<< ")"<< endl;
  }
  else {
    itrSymTab = symTab.find(result[2]);
    if(itrSymTab == symTab.end()) {
      table2 row;
      row.LOC = -1;
      row.value = 0;
      symTab[result[2]] = row;
    }
    fout<< "\t(S,"<< result[2]<< ")"<< endl;
  }
  return 1;
}

int handleSize4(vector<string> result) {

  itrMOT = MOT.find(result[0]);
  if(itrMOT != MOT.end()) {
    return 0;
  }

  itrSymTab = symTab.find(result[0]);
  if(itrSymTab == symTab.end()) {
    table2 row;
    row.LOC = LC;
    row.value = 0;
    symTab[result[0]] = row;
  }

  result.erase(result.begin());
  return handleSize3(result);
}

int genIntCode(string line) {

  static int flag = 0;
  int err;

  vector<string> result;
  boost::split(result, line, boost::is_any_of(" "));

  if(result[0].compare("START") == 0 && result.size() <= 2) {
    flag = 1;
    if(result.size() == 2) {
      LC = stoi(result[1]);
    }
    fout<< "\t\t("<< MOT.at("START").tipe<< ","<< MOT.at("START").opcode<< ")"<< endl;
    return 1;
  }

  if(flag) {
    fout<< LC;
    if(result.size() == 1) {
      return handleSize1(result);
    }
    else if(result.size() == 2) {
      return handleSize2(result);
    }
    else if(result.size() == 3) {
      return handleSize3(result);
    }
    else if(result.size() == 4) {
      return handleSize4(result);
    }
    else if(result.size() > 4) {
      return 0;
    }
  }
  return 0;
}

int main() {

  initMOT();
  initReg();

  string line = "";
  ifstream fin;
  fin.open("file.txt");
  fout.open("/Users/someshwargaikwad/MyFiles/PICT/SL5/GroupA/Assignment2/Pass1.txt");

  while(getline(fin, line)) {
    if(!genIntCode(line)) {
      break;
    }
  }
  generateTextFiles();

  fin.close();
  fout.close();
  return 0;
}
