#include <iostream> 
#include <chrono>
#include <utility>
#include <string>
#include <tuple>

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define DURATION(message) \
    Durationnn UNIQ_ID(__LINE__) {message};

class Durationnn {
  std::string message;
  std::chrono::steady_clock::time_point start;
public:
  explicit Durationnn (std::string&& msg = " ") 
  : message (std::move(msg))
  , start (std::chrono::steady_clock::now()) {
  }
  ~Durationnn () {
  auto finish = std::chrono::steady_clock::now();
  auto duration = finish - start;
  std::cerr << message << ": " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() 
            << " ms" << std::endl;
  } 
};

template <typename T> 
class Test {
public:
  T foo;
  Test(T foo): foo(foo) { 
  }
  template <typename ... Args>
  auto test(Args&& ... args) {
    return foo(args ...);
  }
};

  //std::cerr << "Assertion feiled: " << t << " != " << u << std::endl;
  
  int g(int) {
    std::cout << "1"<< std::endl;
    return 1;
  };
  
  auto f (bool x, double y) {
    std::cout << "2"<< std::endl;
    return 1.2;
  }

int main() {
  Test G(g);
  G.test(1);
  Test F(f);
  auto t = F.test(1, 6.1);
  std::cout << t; 
} 
