#include "/Users/someshwargaikwad/MyFiles/PICT/SL5/GroupA/Assignment1/init.h"

ofstream fout;

int readLitTab(string str) {

  int memAddr = -1;
  string line;
  ifstream fin;

  fin.open("litTab.txt");
  while(getline(fin, line)) {
    if(line.find(str) != string::npos) {
      int flag = line.find(',');
      memAddr = stoi(line.substr(flag + 1));
      return memAddr;
    }
  }
  fin.close();
  return memAddr;
}

int readSymTab(string str) {

  int memAddr = -1;
  string line;
  ifstream fin;

  fin.open("symTab.txt");
  while(getline(fin, line)) {
    if(line.find(str) != string::npos) {
      int flag = line.find(',');
      memAddr = stoi(line.substr(flag + 1, line.find(',', flag + 1) - 1));
      return memAddr;
    }
  }
  fin.close();
  return memAddr;
}

int handleAD_DL(vector<string> str) {

  fout<< "+00\t00\t";
  if(str[3].find("(S,") != string::npos) {
    fout<< readSymTab(str[3].substr(str[3].find(",") + 1, str[3].length() - 5))<< endl;
  }
  if(str[3].find("(S,") != string::npos) {
    fout<< readSymTab(str[3].substr(str[3].find(",") + 1, str[3].length() - 4))<< endl;
  }
  else if(str[3].find("(L,") != string::npos) {
    fout<< readLitTab(str[3].substr(str[3].find(",") + 2, str[3].length() - 6))<< endl;
  }
  else if(str[3].find("(C,") != string::npos) {
    fout<< readSymTab(str[3].substr(str[3].find(",") + 2, str[3].length() - 6))<< endl;
  }
  return 1;
}

int handleIS(vector<string> str) {

  fout<< "+"<< str[1].substr(str[1].find(",") + 1, str[1].length() - 5)<< "\t"<< str[2].substr(1, 2)<< "\t";
  if(str[3].find("(S,") != string::npos) {
    fout<< readSymTab(str[3].substr(str[3].find(",") + 1, str[3].length() - 4))<< endl;
  }
  else if(str[3].find("(L,") != string::npos) {
    fout<< readLitTab(str[3].substr(str[3].find(",") + 2, str[3].length() - 6))<< endl;
  }
  else if(str[3].find("(C,") != string::npos) {
    fout<< readSymTab(str[3].substr(str[3].find(",") + 2, str[3].length() - 6))<< endl;
  }
  return 1;
}

int genIntCode(string line) {

  static int flag = 0;
  if(line.find("(AD,01)") != string::npos) {
    flag = 1;
    return 1;
  }
  if(flag == 1) {
    vector<string> result;
    boost::split(result, line, boost::is_any_of("\t"));

    fout<< result[0]<< "\t";
    if(line.find("(IS,00)") != string::npos) {
      fout<< "+00\t00\t00"<< endl;
      return 1;
    }
    else if(line.find("AD,04") != string::npos) {
      fout<< "+00\t00\t00"<< endl;
      return 1;
    }
    else {
      if(result[1].find("AD") != string::npos) {
        return handleAD_DL(result);
      }
      else if(result[1].find("IS") != string::npos) {
        return handleIS(result);
      }
      else if(result[1].find("DL") != string::npos) {
        return handleAD_DL(result);
      }
      else if(result[3].find("=") != string::npos) {
        fout<< "+00\t00\t"<< result[0]<< endl;
        return 1;
      }
    }
  }
  return 0;
}

int main() {

  initMOT();
  initReg();

  string line = "";
  ifstream fin;
  fin.open("Pass1.txt");
  fout.open("Pass2.txt");

  while(getline(fin, line)) {
    if(!genIntCode(line)) {
      break;
    }
  }

  fin.close();
  fout.close();
  return 0;
}
