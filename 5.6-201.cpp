#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 11;
std::array<int,n> A;

void ChoosePivot(auto &A, auto begin, auto end) {
  auto pivot = begin + rand() % (end - begin + 1);
  auto temp = A[pivot];
  A[pivot] = A[begin];
  A[begin] = temp;
}

auto Partition (auto &A, auto begin, auto end) {
  auto pivot = begin;
  for (auto i = begin + 1; i <= end; ++i) {
    if (A[i] < A[pivot]) {
      auto temp = A[pivot];
      A[pivot] = A[i];
      A[i] = A[pivot+1];
      A[pivot+1] = temp;
      pivot += 1;
    }
  }
return pivot;
}

void QuickSort (auto &A, auto begin, auto end) {
  if (begin >= end) {
    return;
  }
  ChoosePivot(A, begin, end);
  auto x = Partition(A, begin, end);
  QuickSort(A, begin, x - 1);
  QuickSort(A, x + 1, end);
}

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] = {(rand() % 10)};
    std::cout <<  A[i] << " ";
  }
  std::cout << '\n';
  
  QuickSort(A, 0, n-1);

  for (auto i = 0; i < n; ++i){
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
}
