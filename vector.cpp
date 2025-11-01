#include "vector.h"
#include <stdexcept>

Vector::Vector(int s) {
  if (s < 0) {
    throw std::length_error("Vector Constructor: negative size");
  }

  elem = new double[s];
  sz = s;
}

// When the object goes out of scope we delete the associated memory.
Vector::~Vector() { delete[] elem; }

double &Vector::operator[](int i) {
  if (!(0 <= i) < size()) {
    throw std::out_of_range{"Vector::operator[]"};
  }
  return elem[i];
}

int Vector::size() const { return sz; }
