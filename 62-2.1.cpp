#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 7;
int A[n];
//TODO
void Merge(int* AA, int p, int q, int r) {
      
  
    std::cout << p << '\n';
    std::cout << q << '\n';
    std::cout << r << '\n';
    for (auto i = 0; i < n; ++i) {
      std::cout << A[i] << " ";
    }
    std::cout << '\n';
  int n1 = q-p+1;
  int n2 = r-q+1;
  int L[n1];
  int R[n2];
  for (auto i = 0; i < n1; ++i) {
    L[i] = AA[p+i];
  } 
  L[n1] = n*n;
  for (auto i = 0; i < n2; ++i) {
    R[i] = AA[q+i];
  }
  R[n2] = n*n;
  int i = 0;
  int j = 0; 
  for (int k = p; k <= r; ++k) {
    if (L[i] <= R[j]) {
      AA[k] = L[i];
      ++i;
    }
    else {
      AA[k] = R[j];
      ++j;
    }
  }
    for (auto i = 0; i < n; ++i) {
      std::cout << A[i] << " ";
    }
    std::cout << '\n';
}

void Merge_Sort(int* AA, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    Merge_Sort(AA, p, q);
    Merge_Sort(AA, q + 1, r);  
    Merge(AA, p, q, r);
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
