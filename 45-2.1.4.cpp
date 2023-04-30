#include <array>
#include <iostream>

const int n = 10;

int main() {
        //  1 0 1 0 1 1 0 0 0 1 0
  int A[n] = {1,0,1,0,1,1,0,0,0,1};
  int B[n] = {1,0,1,0,1,1,0,0,0,1};
  int C[n+1] = {0,0,0,0,0,0,0,0,0,0,0};
  for (auto i = n-1; i >= 0; --i) {
    auto temp = A[i] + B[i];
    if (temp == 0) {
      C[i+1] += 0;
    }
    if (temp == 1) {
      C[i+1] += 1;
    }
     if (temp == 2) {
      C[i+1] += 0;
      C[i] += 1;
    }
  }
  for (auto i = 0; i < n+1; ++i){
    std::cout << C[i] << '\n';
  }
}
