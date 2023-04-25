#include <iostream> 
#include <chrono>
#include <utility>
#include <string>


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
    std::cout << message << ": " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() 
              << " ms" << std::endl;
    } 
};

template <typename T, typename U> 
void Asserttt(const T& t, const U& u) {
    if (t != u) {
        std::cout << "Assertion feiled: " << t << " != " << u << std::endl;
    }
}

int main() {
    DURATION("a");
    int a = 5;
    int b = 6;
    Asserttt(a,b);
}
