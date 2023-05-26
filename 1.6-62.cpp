// Recinmult algoritm

#include <array>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int n = 4;
std::array<int, n> A;
std::array<int, n> B;
std::array<int, 2*n> C; 

auto Recinmult (unsigned int l_begin, unsigned int l_end, unsigned int r_begin, unsigned int r_end) {
  std::array<int, n> ac, ad, bc, bd;
  if ((l_end - l_begin >= 0) or (r_end - r_begin >= 0)) { //base case
    C[2*n - 1] = A[l_begin] * B[r_begin];
    if (C[2*n - 1] > 10) {
      C[2*n - 2] = (C[2*n - 1] - (C[2*n - 1] % 10)) / 10;
      return 2*n-2;
    }
    return 2*n-1;   
  }
  auto a_range = std::make_pair(l_begin, l_begin + ((l_end - l_begin) / 2));  // define ranges of numbers
  auto b_range = std::make_pair(a_range.second, l_end);
  auto c_range = std::make_pair(r_begin, r_begin + ((r_end - r_begin) / 2));
  auto d_range = std::make_pair(b_range.second, r_end);
  auto temp_ac = Recinmult(a_range.first, a_range.second, c_range.first, c_range.second);  //ac
  auto j = n - 1;
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
  j = n - 1;  //10^n * ac + 10^n/2 * (ad + bc) + bd
  //TODO ranges of C array
  auto final_range = 2*n - 1;
  for (auto i = final_range; i >= final_range - n; --i) {
    C[i] = bd[j];
    --j;
  }
  final_range = final_range - final_range - temp_bd;
  j = n - 1;
  for (auto i = final_range; i >= final_range - n; --i) {
    auto temp = C[i] + ad[j] + bc[j];
    C[i] = temp % 10;
    if (temp > 10) {
      C[i - 1] = (temp - C[i]) / 10;
    }
    --j;
  }
  final_range = final_range - temp_bc;
  j = n - 1;
  for (auto i = temp_bc; i >= 0; --i) {
    auto temp = C[i] + ac[j]; 
    C[i] = temp % 10;
    if (temp > 10) {
      C[i - 1] = (temp - C[i]) / 10;
    }
    --j;
  }
  //TODO what should i return?
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
  Recinmult(0, n, 0, n); 
  std::cout << '\n';
  std::cout << "result number is ";
  for (int i = 0; i < 2*n; ++i) {
    std::cout << C[i];  
  }
  std::cout << '\n';
}
