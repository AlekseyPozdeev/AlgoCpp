// Recinmult algoritm

#include <array>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 3;
std::array<int, n> A;
std::array<int, n> B;
std::array<int, 2*n> C; 

int Recinmult (int l_begin, int l_end, int r_begin, int r_end) {
  std::array<int, n> ac {};
  std::array<int, n> ad {};
  std::array<int, n> bc {};
  std::array<int, n> bd {};
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

  auto j = n - 1;
  auto temp_ac = Recinmult(a_range.first, a_range.second, c_range.first, c_range.second);  //ac
  for (auto i = 2*n-1; i >= temp_ac; --i) {
    ac[j] = C[i];
    --j;
  }
  auto temp_ad = Recinmult(a_range.first, a_range.second, d_range.first, d_range.second);  //ad
  j = n - 1;
  for (auto i = 2*n-1; i >= temp_ad; --i) {
    ad[j] = C[i];
    --j;
  }
  auto temp_bc = Recinmult(b_range.first, b_range.second, c_range.first, c_range.second);  //bc
  j = n - 1;
  for (auto i = 2*n-1; i >= temp_bc; --i) {
    bc[j] = C[i];
    --j;
  }
  auto temp_bd = Recinmult(b_range.first, b_range.second, d_range.first, d_range.second);  //bd
  j = n - 1;
  for (auto i = 2*n-1; i >= temp_bd; --i) {
    bd[j] = C[i];
    --j;
  }
  
  std::cout << "bd ";
  for (auto j = 0; j < n; ++j){
    std::cout << bd[j] << " ";
  }
  std::cout << '\n';
  std::cout << "ad ";
  for (auto j = 0; j < n; ++j){
    std::cout << ad[j] << " ";
  }
  std::cout << '\n';
  std::cout << "bc ";
  for (auto j = 0; j < n; ++j){
    std::cout << bc[j] << " ";
  }
  std::cout << '\n';
  std::cout << "ac ";
  for (auto j = 0; j < n; ++j) {
    std::cout << ac[j] << " ";
  }
  std::cout << '\n';
  std::cout << '\n';
  
  for (auto i = 0; i < 2*n; ++i) { //clear
    C[i] = 0;
  }
   
  //10^n * ac + 10^n/2 * (ad + bc) + bd
  auto range = std::make_pair(2*n - 1, 2*n - 1 - 2*(a_range.second - a_range.first));
  j = n - 1; 
  for (auto i = range.first; i >= range.second; --i) {
    C[i] = bd[j];
    --j;
  }
  range.first = 2*n-1 - a_range.second - a_range.first;
  range.second = range.first - d_range.second - d_range.first;
  j = n - 1;
  for (auto i = range.first; i >= range.second; --i) {
    auto temp = 0;
    if (j >= 0) {
      temp = ad[j] + bc[j] + C[i];
      C[i] = temp % 10;
    }
    if (temp > 9) {
      C[i - 1] = (temp - C[i]) / 10;
    }
    --j;
  }
  range.first = 2*n-1 - 2*(a_range.second - a_range.first);
  range.second = range.first - 2*(a_range.second - a_range.first) + 1;
  j = n - 1;
  for (auto i = range.first; i >= range.second; --i) {
    auto temp = C[i] + ac[j]; 
    C[i] = temp % 10;
    if (temp > 9) {
      C[i - 1] = (temp - C[i]) / 10;
    }
    --j;
  }
    return range.first - temp_ac;
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
  auto x = Recinmult(0, n, 0, n); 
  std::cout << "result number is ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i] << " ";  
  }
  std::cout << '\n';
}
