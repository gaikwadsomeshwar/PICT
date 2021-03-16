#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int size = 50;

void merge(vector<int> &arr, int l, int m, int r) {

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int l, int r) {

  if (l < r) {
    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

float MRT(vector<int> arr, int L) {

  vector<int> tapes[L];
  int sum[L], i;
  for(i = 0; i < L; i++) {
    sum[i] = 0;
  }

  //Arranging the Tapes
  i = 0;
  for(auto itr = arr.begin(); itr != arr.end();) {
    if((sum[i] + *itr) <= size) {
      tapes[i].push_back(*itr);
      sum[i] += *itr;
      itr++;
    }
    else if((sum[i] + *itr) > size) {
      cout<< "Size Exceeds";
      return -1;
    }
    i++;
    if(i == L) {
      i = 0;
    }
  }

  //MRT Calculation
  float Mrt, mrt;
  for(i = 0; i < L; i++) {
    mrt = 0;
    cout<< "Tape "<< (i + 1)<< " : [ ";
    //MRT per Tape
    for(int j = 0; j < tapes[i].size(); j++) {
      mrt += (tapes[i].size() - j) * tapes[i][j];
      cout<< tapes[i][j]<< " ";
    }
    cout<< "] ( MRT: "<< mrt/tapes[i].size()<< " )"<< endl;
    Mrt += mrt/tapes[i].size();
  }

  //Returning the Average MRT of All Tapes
  return Mrt/L;
}

int main() {

  vector<int> arr;
  int L, x, n, ch = 0;

  cout<< endl<< "Number of Tapes: ";
  cin>> L;

  cout<< endl<< "Enter number of programs: ";
  cin>> n;
  cout<< "Enter programs          : ";
  for(int i = 0; i < n; i++) {
    cin>> x;
    if(x < 0) {
      i--;
    }
    else {
      arr.push_back(x);
    }
  }

  //Sorting using Merge Sort Algorithm
  mergeSort(arr, 0, n - 1);

  cout<< endl;
  float mrt = MRT(arr, L);
  if(mrt != -1) {
    cout<< endl<< "Average MRT: "<< float(mrt);
  }
  cout<< endl<< endl;

  return 0;
}
