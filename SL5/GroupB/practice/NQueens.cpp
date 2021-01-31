#include <iostream>
#include <cstdlib>
using namespace std;

int N;

void Solution(int arr[N]) {

  cout<<"\n===========================\n\n";
  for(int i = 0; i < N; i++) {

    for(int j = 0; j < N; j++) {

      if(arr[i] == j)
        cout<<"Q ";
      else
        cout<<"* ";
    }
    cout<<endl;
  }
}

bool Place(int arr[N], int Qi, int Qj) {

  for(int i = 0; i < Qi ; i++) {
    if(arr[i] == Qj || abs(arr[i] - Qj) == abs(i - Qi)) {
      return false;
    }
  }
  return true;
}

void NQueens(int arr[N], int i) {

    for(int j = 0; j < N; j++) {

      if(Place(arr, i, j)) {

        arr[i] = j;
        if(i == N-1) {
          Solution(arr);
        }
        else {
          NQueens(arr, i + 1);
        }
      }
    }
}

int main() {

  cout<<"\nHow many Queens troubling the King? ";
  cin>>N;

  int arr[N];

  for(int i = 0; i < N; i++) {
    arr[i] = -1;
  }

  if(N >= 3) {
    NQueens(arr, 0);
  }
  cout<<endl;
}
