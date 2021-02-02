#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
using namespace std;

int main() {

  map<string, string> opcode;

  //sample opcode table
  opcode["START"] = "00";
  opcode["ADD"] = "01";
  opcode["SUB"] = "02";
  opcode["DIV"] = "03";
  opcode["MOVER"] = "04";
  opcode["MOVEM"] = "05";
  opcode["JMP"] = "06";
  opcode["STOP"] = "07";
  opcode["END"] = "08";

  cout<< endl;
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
        map<string, string>::iterator itr = opcode.find(word);
        if(itr != opcode.end()) {
          cout<< itr->first<< ": "<< itr->second<< endl;
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
      map<string, string>::iterator itr = opcode.find(word);
      if(itr != opcode.end()) {
        cout<< itr->first<< ": "<< itr->second<< endl;
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
