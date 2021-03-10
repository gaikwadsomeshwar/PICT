#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int size = 50;

// vector<int>* arrangeTapes(vector<int> arr, int L) {
//
//
//   return tapes;
// }

float MRT(vector<int> arr, int L) {

  vector<int> tapes[L];

  int sum[L], i;
  for(i = 0; i < L; i++) {
    sum[i] = 0;
  }

  i = 0;
  for(auto itr = arr.begin(); itr != arr.end();) {
    if((sum[i] + *itr) <= size) {
      tapes[i].push_back(*itr);
      sum[i] += *itr;
      itr++;
    }
    i++;
    if(i == L) {
      i = 0;
    }
  }

  float Mrt, mrt;
  for(i = 0; i < L; i++) {
    mrt = 0;
    for(int j = 0; j < tapes[i].size(); j++) {
      mrt += (tapes[i].size() - j) * tapes[i][j];
    }
    Mrt += mrt/tapes[i].size();
  }

  return Mrt/L;
}

int main() {

  vector<int> arr;
  int L, x, n, ch = 0;

  cout<< endl<< "Number of Tapes: ";
  cin>> L;

  cout<< endl<< "Enter number of programs: ";
  cin>> n;
  cout<< "Enter programs: ";
  for(int i = 0; i < n; i++) {
    cin>> x;
    arr.push_back(x);
  }

  sort(arr.begin(), arr.end());
  float mrt = MRT(arr, L);
  cout<< endl<< mrt<< endl;

  return 0;
}
