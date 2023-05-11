#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 11;
std::array<int,n> A;

template <typename T>
void Merge(T& A, auto p, auto q, auto r) {
  auto n1 = q - p + 2;
  auto n2 = r - q + 1;
  T L;
  T R;
  for (auto i = 0; i < n1-1; ++i) {
    L[i] = A[p+i];
  } 
  L[n1-1] = n*n;
  for (auto i = 0; i < n2-1; ++i) {
    R[i] = A[q + 1 + i];
  }
  R[n2-1] = n*n;
  auto i = 0;
  auto j = 0; 
  for (auto k = p; k <= r; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    }
    else {
      A[k] = R[j];
      ++j;
    }
  }
}

template <typename T>
void Merge_Sort(T& A, auto p, auto r) {
  if (p < r) {
    auto q = (p + r) / 2;
    Merge_Sort(A, p, q);
    Merge_Sort(A, q + 1, r);  
    Merge(A, p, q, r);
  }
}

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] ={(rand() % n)};
    std::cout <<  A[i] << " ";
  }
  std::cout << '\n';
  
  Merge_Sort(A, 0, n-1);

  for (auto i = 0; i < n; ++i){
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
}
