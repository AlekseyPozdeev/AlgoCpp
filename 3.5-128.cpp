#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 10;
std::array<int,n> A;
std::array<int,n> L;
std::array<int,n> R;

template <typename T>
int Sort(T& A, auto beg, auto mid, auto end) {
  auto l_end = mid - beg + 2;
  auto r_end = end - mid + 1;
  for (auto i = 0; i < l_end - 1; ++i) {
    L[i] = A[beg + i];
  }
  L[l_end - 1] = 10;
  for (auto i = 0; i < r_end - 1; ++i) {
    R[i] = A[mid + 1 + i];
  }
  R[r_end - 1] = 10;
  auto i = 0;
  auto j = 0;
  auto count = 0;
  for (auto k = beg; k <= end; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    }
    else {
      count = count + l_end - i - 1;
      A[k] = R[j];
      ++j;
    }
  }
  return count;
}

template <typename T>
int Count_Inv(T& A, auto beg, auto end) {
  if (end > beg)  {
    auto mid = (end + beg) / 2;
    auto left = Count_Inv(A, beg, mid);
    auto right = Count_Inv(A, mid + 1, end);
    return left + right + Sort(A, beg, mid, end);
  }
  else {
    return 0;
  }
}

template <typename T>
int CountInv(T& A) {
  return Count_Inv(A, 0, A.size() - 1);
}

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] ={(rand() % 10)};
    std::cout <<  A[i] << " ";
  }
  std::cout << '\n';
  
  auto x = CountInv(A);

  std::cout << x << '\n';
  for (auto i = 0; i < n; ++i) {
    std::cout <<  A[i] << " ";
  }
  std::cout << '\n';
}
