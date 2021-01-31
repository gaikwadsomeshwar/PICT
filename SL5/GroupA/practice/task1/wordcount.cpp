#include <iostream>
# include <fstream>
using namespace std;

int main() {

  cout<< endl;
  ifstream fin;
  string line;

  fin.open("file.txt");

  while(fin) {

    getline(fin, line);
    int count = 0;
    string word = "";

    string firstword = line.substr(0, line.find(" "));
    count ++;
    cout<< firstword;

    ifstream opcode;
    opcode.open("opcode.txt");

    while(opcode) {

      string mne;
      getline(opcode, mne);

      if(firstword.compare(mne.substr(0, line.find(" "))) == 0) {

        int firstSpace = mne.find(" ");

        cout<< " (Opcode: "<< mne.substr(firstSpace + 1)<< ")";
      }
    }

    cout<< endl;
    opcode.close();

    for(int x = line.find(" ") + 1; x < line.length(); x++) {

      if(line.at(x) == ' ') {
        cout<< word<< endl;
        word = "";
        count++;
      }
      else {
        word = word + line.at(x);
      }
    }
    cout<< word<< endl;
    count++;

    cout<< "Count of Words: "<< count<< endl<< endl;
  }

  fin.close();
  return 0;
}
