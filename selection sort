#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 10;
int A[n];

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] ={(rand() % n)};
    std::cout <<  A[i] << " ";
  }
  std::cout << '\n';

  for (auto i = 0; i < n -1; ++i) {
    auto temp1 = i;
    for (auto j = i+1; j < n; ++j) {
      if (A[j] < A[temp1]) {
        temp1 = j;
      }
    }
    if (temp1 != i) {
      auto temp2 = A[i];
      A[i] = A[temp1];
      A[temp1] = temp2;
    }
  }

  for (auto i = 0; i < n; ++i){
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
}
