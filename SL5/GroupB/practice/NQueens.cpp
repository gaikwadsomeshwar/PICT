#include <iostream>
#include <cstdlib>
using namespace std;

int N;

void Solution(int arr[N]) {

  for(int i = 0; i < N; i++) {

    for(int j = 0; j < N; j++) {

      if(arr[i] == j)
        cout<<"Q"<<i+1<<" ";
      else
        cout<<" * ";
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

int NQueens(int arr[N], int i) {

    static int count = 0;
    for(int j = 0; j < N; j++) {

      if(Place(arr, i, j)) {

        arr[i] = j;
        if(i == N-1) {
          cout<<endl<<"******************"<<endl;
          cout<<"\nFinal Solution:\n\n";
          Solution(arr);
          cout<<endl<<"******************"<<endl<<endl;
          count++;
        }
        else {
          NQueens(arr, i + 1);
          for(int m = 0; m < N; m++) {
            cout<<m+1<<", "<<arr[m]+1<<"; ";
          }
          cout<<endl;
        }
      }
    }
  return count;
}

int main() {

  cout<<"\nHow many Queens troubling the King? ";
  cin>>N;

  int arr[N];

  for(int i = 0; i < N; i++) {
    arr[i] = -1;
  }

  if(N >= 3) {
    cout<<endl;
    int count = NQueens(arr, 0);
    cout<<endl<<"******************"<<endl;
    if(!count) {
      cout<<"\nSorry King, No Solution\n";
    }
    else if(count > 0) {
      cout<<"\nPossible Solutions: "<<count<<endl;
    }
    cout<<endl<<"******************"<<endl<<endl;
  }
  cout<<endl;
}
