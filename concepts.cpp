#include <string>

// Concept for number works for single type and multiple ones as well.
#include <concepts>
#include <iostream>
#include <iterator>
#include <ranges>
template <typename T, typename U = T>
concept Number = requires(T x, U y) {
  x + y;
  x - y;
  x *y;
  x / y;
  x += y;
  x -= y;
  x *= y;
  x /= y;
  x = x;
  x = 0;
};

template <typename T, typename U = T>
concept Arithmetic = Number<T, U> && Number<U, T>;

template <typename S>
concept Sequence = requires(S a) {
  // S must have a value type
  typename std::ranges::range_value_t<S>;
  // S must have an iterator type
  typename std::ranges::iterator_t<S>;
  // S must have a begin() method that returns an iterator.
  { a.begin() } -> std::same_as<std::ranges::iterator_t<S>>;
  // S must have an end() method that returns and iterator
  { a.end() } -> std::same_as<std::ranges::iterator_t<S>>;
  // S's iterator must be an input_iterator
  requires std::input_iterator<std::ranges::iterator_t<S>>;
  requires std::same_as<std::ranges::range_value_t<S>, std::iter_value_t<S>>;
};

template <typename T>
concept Printable = requires(T t) { std::cout << t; }; // just one operation!

template <Printable T, Printable... Tail> void print(T head, Tail... tail) {
  std::cout << head << ' ';
  // Only print if we got any arguments.
  if constexpr (sizeof...(tail) > 0)
    print(tail...);
};

int main() {
  // Interesting that you can do this. It does avoid polluting the whole file
  // with the using statement but this does look quite ugly imo.
  using namespace std::string_literals;
  print("first", 1, 2.2, "hello\n"s);
  return 0;
};
