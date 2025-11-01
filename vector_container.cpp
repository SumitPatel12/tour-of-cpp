#include "vector.h"

class Container {
public:
  virtual double &operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
};

class Vector_Container : public Container {
public:
  Vector_Container(int s) : v(s) {}
  ~Vector_Container() {}

  double &operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }

private:
  Vector v;
};
