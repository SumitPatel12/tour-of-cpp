class Vector {
public:
  Vector(int s);
  ~Vector();
  double &operator[](int i);
  int size() const;

private:
  double *elem;
  int sz;
};
