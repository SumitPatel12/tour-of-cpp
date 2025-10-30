// Won't compile for me but thats' what it'd be like if I had a working
// compiler.
export module Vector;

export class Vector {
public:
  Vector(int s);
  double &operator[](int i);
  const double &operator[](int i) const;
  int size() const;

private:
  double *elem;
  int sz;
};

Vector::Vector(int s) : elem{new double[s]}, sz{s} {}

double &Vector::operator[](int i) { return elem[i]; }

const double &Vector::operator[](int i) const { return elem[i]; }

int Vector::size() const { return sz; }

export bool operator==(const Vector &v1, const Vector &v2) {
  if (v1.size() != v2.size())
    return false;
  for (int i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i])
      return false;
  return true;
}
