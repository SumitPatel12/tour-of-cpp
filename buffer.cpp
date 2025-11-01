// This is just a barebones interface kind of thing to knwo what can be done.

// Just a buffer of some generic type T that is stack allocated.
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
template <typename T, int N> struct Buffer {
  constexpr int size() { return N; }
  T elem[N];
  // You can have some more things here.
  // Since this is just an example I won't bother with the implementation.
};

// Blanket implementation of sum
template <typename Sequence, typename Value> Value sum(Sequence &s, Value v) {
  for (const auto &x : s) {
    v += x;
  }
  return v;
};

template <typename T> class Less_Than {
  const T val;

public:
  Less_Than(const T &v) : val{v} {}
  // The call operator
  bool operator()(const T &x) const { return x < val; }
};

void fn_test_less_than(int n, const std::string &str) {
  Less_Than lti{42};
  bool b1 = lti(n);

  Less_Than<std::string> lts{"Something"};
  bool b2 = lts(str);
}

void lambda_function(const std::vector<int> &vec,
                     const std::list<std::string> &lst, int x,
                     const std::string &s) {
  std::cout << "Number of values less than " << x << ": "
            << std::count_if(vec.begin(), vec.end(),
                             [&](int a) { return a < x; })
            << '\n';
}
