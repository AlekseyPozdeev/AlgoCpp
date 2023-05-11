#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 11;
int A[n];

void Merge(int* AA, int p, int q, int r) {
      
  
   /* std::cout << "Новый мерж" << '\n';
    for (auto i = 0; i < n; ++i) {
      std::cout << AA[i] << " ";
    }
    std::cout << '\n';
    std::cout << "p=" << p << " ";
    std::cout << "q=" << q << " ";
    std::cout << "r=" << r << '\n';*/
  int n1 = q - p + 2;
  int n2 = r - q + 1;
 /* std::cout << "n1=" << n1 << " ";
  std::cout << "n2=" << n2 << '\n';*/
  int L[n1];
  int R[n2];

  for (int i = 0; i < n1-1; ++i) {
    L[i] = AA[p+i];
  } 
  L[n1-1] = n*n;
  /*std::cout << "L" << '\n';
  for (auto i = 0; i < n1; ++i) {
      std::cout << L[i] << " ";
    }
  std::cout << '\n';*/
  for (auto i = 0; i < n2-1; ++i) {
    R[i] = AA[q + 1 + i];
  }
  R[n2-1] = n*n;
  /*std::cout << "R" << '\n';
  for (auto i = 0; i < n2; ++i) {
      std::cout << R[i] << " ";
    }
  std::cout << '\n';*/
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
  /*for (auto i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << '\n';*/
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
