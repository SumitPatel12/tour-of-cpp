#include <string>
#include <variant>

// This takes more memory since both ptr, and num are assigned, but they're
// never used together.
enum class Type { ptr, num };

struct Entry {
  std::string name;
  Type t;
  int *p;
  int i;
};

// Union on the other hand states that all values live in the same address and
// take up space equal to the one that takes maximum space among them.
// Guaranteeing that we never take space for variables that we don't intent to
// use simulatn.
union Value {
  int *p;
  int i;
};

// Better Yet you can use the std::variant instead of a naked union. This helps
// reduce friction and errors around checks relating to what value the union is
// holding.
struct EntryVariant {
  std::string name;
  std::variant<int *, int> v;
};
