// Recinmult algoritm

#include <array>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

const int n = 5;
std::array<int, n> A;
std::array<int, n> B;
std::array<int, 2*n> C; 

void WR(std::array<int, n + 1> &arr, int end) {
  auto j = n;
  for (auto i = 2*n - 1; i >= end; --i) {
    arr[j] = C[i];
    --j;
  }
}

int Recinmult (int l_begin, int l_end, int r_begin, int r_end) {
  std::array<int, n + 1> ac {};
  std::array<int, n + 1> ad {};
  std::array<int, n + 1> bc {};
  std::array<int, n + 1> bd {};
  if ((l_end - l_begin <= 1) and (r_end - r_begin <= 1)) { //base case
    auto temp = A[l_begin] * B[r_begin];
    C[2*n-1] = 0;
    C[2*n-2] = 0;
    C[2*n-1] = temp % 10;
    if (temp > 9) {
      C[2*n-2] = (temp - C[2*n-1]) / 10;
      return 2*n-2;
    }
    return 2*n-1;   
  }
  auto a_range = std::make_pair(l_begin, l_begin + ((l_end - l_begin) / 2));  // define ranges of numbers
  auto b_range = std::make_pair(a_range.second, l_end);
  auto c_range = std::make_pair(r_begin, r_begin + ((r_end - r_begin) / 2));
  auto d_range = std::make_pair(c_range.second, r_end);
  auto temp_ad = -1;
  auto temp_ac = -1;
  auto temp_bc = -1;
  auto temp_bd = -1;

  if (l_end - l_begin > r_end - r_begin) {
    temp_ad = Recinmult(a_range.first, a_range.second, c_range.first, d_range.second);  //ad
    WR(ad, temp_ad);
    temp_bd = Recinmult(b_range.first, b_range.second, c_range.first, d_range.second);  //bd
    WR(bd, temp_bd); 
  }
  
  if (l_end - l_begin < r_end - r_begin) {
    temp_bc = Recinmult(a_range.first, b_range.second, c_range.first, c_range.second);  //bc
    WR(bc, temp_bc);
    temp_bd = Recinmult(a_range.first, b_range.second, d_range.first, d_range.second);  //bd
    WR(bd, temp_bd);
  }

  if (l_end - l_begin == r_end - r_begin) {
    temp_ac = Recinmult(a_range.first, a_range.second, c_range.first, c_range.second);  //ac
    WR(ac, temp_ac); 
    temp_ad = Recinmult(a_range.first, a_range.second, d_range.first, d_range.second);  //ad
    WR(ad, temp_ad);
    temp_bc = Recinmult(b_range.first, b_range.second, c_range.first, c_range.second);  //bc
    WR(bc, temp_bc);
    temp_bd = Recinmult(b_range.first, b_range.second, d_range.first, d_range.second);  //bd
    WR(bd, temp_bd);
  }

  for (auto i = 0; i < 2*n; ++i) { //clear
    C[i] = 0;
  }
  
  //10^n * ac + 10^n/2 * (ad + bc) + bd
  auto len = std::max(l_end - l_begin, r_end - r_begin);
  auto offset = 0;
  if ((len % 2) != 0) {
    offset = 1;
  }
  auto range = std::make_pair(2*n - 1, 2*n - 1 - len);
  auto j = n; 
  for (auto i = range.first; i >= range.second; --i) {
    if (j >= 0) {
      C[i] = bd[j];
    }
    --j;
  }
  range.first = range.first - len/2 - offset;
  range.second = range.first - len;
  j = n;
  for (auto i = range.first; i >= range.second; --i) {
    auto temp = 0;
    if (j >= 0) {
      temp = ad[j] + bc[j] + C[i];
      C[i] = temp % 10;
    }
    if (temp > 9) {
      C[i - 1] = C[i - 1] + (temp - C[i]) / 10;
    }
    --j;
  }
  if (temp_ac != -1) {
    range.first = range.first - len/2 - offset;
    range.second = range.first - len;
    j = n;
    for (auto i = range.first; ((i >= range.second) or (i = 0)); --i) {
      auto temp = C[i] + ac[j]; 
      C[i] = temp % 10;
      if (temp > 9) {
        C[i - 1] = (temp - C[i]) / 10;
      }
      --j;
    }
  }
  if (range.second > 0) {
    return range.second + 1;
  }
  else {
    return 0;
  }
}

int main() {
  std::srand(time(NULL));
  std::cout << "first number is  ";
  for (int i = 0; i < n; ++i) {
    A[i] = (rand()%10);
    std::cout << A[i];
  }
  std::cout << '\n';
  std::cout << "second number is ";
  for (int i = 0; i < n; ++i) {
    B[i] = (rand()%10);
    std::cout << B[i];  
  }
  std::cout << '\n';
  Recinmult(0, n, 0, n); 
  std::cout << "result number is ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i] << " ";  
  }
  std::cout << '\n';
}
