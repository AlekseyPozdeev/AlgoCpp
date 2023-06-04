// Recinmult algoritm

#include <array>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

const int n = 4;
std::array<int, n> A;
std::array<int, n> B;
std::array<int, 2*n> C; 

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

  auto j = n;
  temp_ac = Recinmult(a_range.first, a_range.second, c_range.first, c_range.second);  //ac
  for (auto i = 2*n-1; i >= temp_ac; --i) {
    ac[j] = C[i];
    --j;
  }
  std::cout << '\n';
  std::cout << "ac ";
  for (auto j = 0; j <= n; ++j) {
    std::cout << ac[j] << " ";
  }
  std::cout << '\n';

  if (c_range.second - c_range.first > 0) {
    temp_ad = Recinmult(a_range.first, a_range.second, d_range.first, d_range.second);  //ad
    j = n;
    for (auto i = 2*n-1; i >= temp_ad; --i) {
      ad[j] = C[i];
      --j;
    }
    std::cout << "ad ";
    for (auto j = 0; j <= n; ++j){
      std::cout << ad[j] << " ";
    }
    std::cout << '\n';
  }
  else {
    std::cout << "- --" <<'\n';
  }

  if (a_range.second - a_range.first > 0) {
    temp_bc = Recinmult(b_range.first, b_range.second, c_range.first, c_range.second);  //bc
    j = n;
    for (auto i = 2*n-1; i >= temp_bc; --i) {
      bc[j] = C[i];
      --j;
    }
    std::cout << "bc ";
    for (auto j = 0; j <= n; ++j) {
      std::cout << bc[j] << " ";
    }
    std::cout << '\n';
    
    if (c_range.second - c_range.first > 0) {
      temp_bd = Recinmult(b_range.first, b_range.second, d_range.first, d_range.second);  //bd
      j = n;
      for (auto i = 2*n-1; i >= temp_bd; --i) {
        bd[j] = C[i];
        --j;
      }
      std::cout << "bd ";
      for (auto j = 0; j <= n; ++j) {
        std::cout << bd[j] << " ";
      }
      std::cout << '\n';
    }
    else {
      std::cout << "--- " << '\n';
    }
  }
  else {
    std::cout << "--  " <<'\n';
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
  if (temp_bd != -1) {
    j = n; 
    for (auto i = range.first; i >= range.second; --i) {
      if (j >= 0) {
        C[i] = bd[j];
      }
      --j;
    }
    range.first = range.first - len/2 - offset;
    range.second = range.first - len;

  }
  std::cout << "result ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i] << " ";  
  }
  std::cout << '\n';
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
  std::cout << "result ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i] << " ";  
  }
  std::cout << '\n';
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
  std::cout << "result ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i] << " ";  
  }
  std::cout << '\n';
  if (range.second > 0) {
    return range.second - 1;
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
