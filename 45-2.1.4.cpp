#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 10;
int A[n];
int B[n];

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] ={(rand() % 2)};
    B[i] = {(rand() % 2)};
  }
  std::cout << " ";
  for (auto i = 0; i < n; ++i) {
    std::cout << " " <<  A[i];
  }
  std::cout << '\n';
  std::cout << " ";
  for (auto i = 0; i < n; ++i) {
    std::cout << " " <<  B[i];
  }
  std::cout << '\n';

  int C[n+1] = {0,0,0,0,0,0,0,0,0,0,0};
  for (auto i = n-1; i >= 0; --i) {
    auto temp = A[i] + B[i];
    if (temp == 1) {
      if (C[i+1] == 0) {
        C[i+1] = 1;
      }
      else {
        C[i+1] = 0;
        C[i] = 1;
      }
    }
     if (temp == 2) {
      C[i+1] += 0;
      C[i] += 1;
    }
  }

  for (auto i = 0; i < n+1; ++i){
    std::cout << C[i] << " ";
  }
  std::cout << '\n';
}
