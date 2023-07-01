//RSelect algorithm

#include <array>
#include <stdlib.h>
#include <time.h>
#include <iostream>

const int n = 10;
std::array<int,n> A;
std::array<int,n> B;

auto Partition(auto &A, auto begin, auto end, auto pivot) {
  auto temp = A[pivot];
  A[pivot] = A[begin];
  A[begin] = temp;
  pivot = begin;
  auto x = begin;
  for (auto i = begin + 1; i <= end; ++i) {
    if (A[i] < A[pivot]) {
      auto temp = A[pivot];
      A[pivot] = A[i];
      A[i] = A[pivot + 1];
      A[pivot + 1] = temp;
      pivot += 1;
    }
  }
  for (auto i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
  return pivot;
}

auto RSelect (auto &A, auto begin, auto end, auto select) {
  if (begin >= end) {
    return select;
  }
  auto pivot = begin + rand() % (end - begin + 1);
  std::cout << "pivot=" << pivot << '\n';
  auto selected = Partition(A, begin, end, pivot);
  std::cout << "selected=" << selected << '\n';
  if (selected == select) {
    return selected;
  }
  if (select < selected) {
    return RSelect(A, begin, selected - 1, select);
  }
  return RSelect(A, selected + 1, end, select - selected);
}

int main() {
  std::srand(time(NULL));
  for (auto i = 0; i < n; ++i) {
    A[i] = (rand()%10);
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
 //TODO remove duplicates 
  auto select = 1; //rand() % n;
  std::cout << select << '\n' << A[RSelect(A, 0, n-1, select)] << '\n';

  for (auto i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
}
