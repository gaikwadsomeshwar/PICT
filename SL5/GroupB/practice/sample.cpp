#include <iostream>
using namespace std;

int main() {

  int i = 200, n = 80, count = 0;

  while(i >= n) {
    i = i - 2;
    n = n + 1;
    count++;
  }
  count ++;
  cout<< count <<endl;

  return 0;
}
