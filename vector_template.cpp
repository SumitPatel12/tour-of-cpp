#include <concepts>
#include <iostream>
#include <stdexcept>

// I see how a lot of similarities with Rust. A lot of people still like C++
// better because it gives you more control. Rightfully so, I'll form my own
// opinion when I understand both languages better.
// I can say one thing, linked lists in Rust is like dancing with the devil.
template <typename T>
concept Element = std::copyable<T>;

// Vector for generic type T.
template <Element T> class Vector_Template {
private:
  T *elem;
  int sz;

public:
  explicit Vector_Template(int s);
  ~Vector_Template() { delete[] elem; }

  // Code for copy and move was creted by AMP Code, was testing some things out
  // with it. Copy operations
  Vector_Template(const Vector_Template &v);
  Vector_Template &operator=(const Vector_Template &v);

  // Move operations
  Vector_Template(Vector_Template &&v) noexcept;
  Vector_Template &operator=(Vector_Template &&v) noexcept;

  T &operator[](int i);
  const T &operator[](int i) const;
  int size() const { return sz; }
};

template <Element T> Vector_Template<T>::Vector_Template(int s) {
  if (s < 0)
    throw std::length_error{"Vector constructor: negative size"};
  elem = new T[s];
  sz = s;
}

// Non-const version
template <Element T> T &Vector_Template<T>::operator[](int i) {
  if (i < 0 || size() <= i)
    throw std::out_of_range{"Vector::operator[]"};
  return elem[i];
}

// Const version
template <Element T> const T &Vector_Template<T>::operator[](int i) const {
  if (i < 0 || size() <= i)
    throw std::out_of_range{"Vector::operator[]"};
  return elem[i];
}

// Copy constructor
template <Element T>
Vector_Template<T>::Vector_Template(const Vector_Template &v)
    : elem{new T[v.sz]}, sz{v.sz} {
  for (int i = 0; i < sz; ++i)
    elem[i] = v.elem[i];
}

// Copy assignment
template <Element T>
Vector_Template<T> &Vector_Template<T>::operator=(const Vector_Template &v) {
  if (this == &v)
    return *this;
  T *p = new T[v.sz];
  for (int i = 0; i < v.sz; ++i)
    p[i] = v.elem[i];
  delete[] elem;
  elem = p;
  sz = v.sz;
  return *this;
}

// Move constructor
template <Element T>
Vector_Template<T>::Vector_Template(Vector_Template &&v) noexcept
    : elem{v.elem}, sz{v.sz} {
  v.elem = nullptr;
  v.sz = 0;
}

// Move assignment
template <Element T>
Vector_Template<T> &
Vector_Template<T>::operator=(Vector_Template &&v) noexcept {
  if (this == &v)
    return *this;
  delete[] elem;
  elem = v.elem;
  sz = v.sz;
  v.elem = nullptr;
  v.sz = 0;
  return *this;
}

template <Element T> T *begin(Vector_Template<T> &x) { return &x[0]; }

template <Element T> T *end(Vector_Template<T> &x) { return &x[0] + x.size(); }

void write_vector_template(Vector_Template<std::string> &vs) {
  for (auto &s : vs) {
    std::cout << s << '\n';
  }
}

int main() {
  Vector_Template<std::string> vs(3);
  vs[0] = "Hello";
  vs[1] = "World";
  vs[2] = "!";

  write_vector_template(vs);

  return 0;
}
