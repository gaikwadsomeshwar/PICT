#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
using namespace std;

typedef struct table {

  string opcode = "";
  int size = 0;
  string tipe = "";
  int operands = 0;
} table;

map<string, table> MOT;
//sample MOT table

void init() {

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
        map<string, table>::iterator itr = MOT.find(word);
        if(itr != MOT.end()) {
          cout<< itr->first<< ": "<< itr->second.opcode<< endl;
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
      map<string, table>::iterator itr = MOT.find(word);
      if(itr != MOT.end()) {
        cout<< itr->first<< ": "<< itr->second.opcode << endl;
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
