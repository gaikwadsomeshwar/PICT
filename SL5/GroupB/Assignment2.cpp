#include <iostream>
using namespace std;

typedef struct {
  int min;
  int max;
} Pair;

//find maximum between 2 numbers
int max(int x, int y) {
  if(x > y) {
    return x;
  }
  return y;
}

//find minimumum between 2 numbers
int min(int x, int y) {
  if(x > y) {
    return y;
  }
  return x;
}

Pair minmax(int arr[], int left, int right) {

  Pair minMax, leftArr, rightArr;

  //one element
  if(left == right) {
    minMax.min = arr[left];
    minMax.max = arr[left];

    for(int i = left; i <= right; i++) {
      cout<< arr[i]<< " ";
    }
    cout<< endl<< minMax.min<< ", "<< minMax.max<< endl<< endl;

    return minMax;
  }

  //2 elements
  if(left + 1 == right) {
    minMax.min = min(arr[left], arr[right]);
    minMax.max = max(arr[left], arr[right]);

    for(int i = left; i <= right; i++) {
      cout<< arr[i]<< " ";
    }
    cout<< endl<< minMax.min<< ", "<< minMax.max<< endl<< endl;

    return minMax;
  }

  //more than 2 elements
  int mid = (left + right)/2;

  //recursive calls to find min and max
  leftArr = minmax(arr, left, mid);
  rightArr = minmax(arr, mid + 1, right);

  //find the min and max from the divided arrays
  minMax.min = min(leftArr.min, rightArr.min);
  minMax.max = max(leftArr.max, rightArr.max);

  for(int i = left; i <= right; i++) {
    cout<< arr[i]<< " ";
  }
  cout<< endl<< minMax.min<< ", "<< minMax.max<< endl<< endl;

  return minMax;
}

int main() {

  int arr[10];
  cout<< endl<< "Enter 10 numbers: ";
  //accepting 10 elements
  for(int i = 0; i < 10; i++) {
    cin>>arr[i];
  }
  cout<< endl<< "************************"<< endl<< "Working: "<< endl<< endl;
  Pair minMax = minmax(arr, 0, 9);
  cout<< "************************"<< endl<< "Final Output: "<< minMax.min<< ", "<< minMax.max<< endl<< "************************"<< endl<< endl;
  return 0;
}
