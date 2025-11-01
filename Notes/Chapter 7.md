## Templates
- For blanket implementations or generic types you can use templates. Things like vector or array do that.
- Templates can be parameterized as well, so something like Buffer<Type, N>, where N would be the parameter.
- The parameter can be among the following three things:
  1. Function Template
  2. Function Object: And object that can carry data and be called like a function.
  3. A Lambda Expression: A shorthand notation for a function object.

The function objects are especially useful since they let you define methods on the class itself. So you can do things like `page.get_block()` and the like. They can carry a certain amount of context with them which in turn prevents the compiler or user from having to create a separate function for each call.

### Lambda Expressions
Man these were a bit difficult to grok despite me knowing the syntax of it.
```c++
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
        cout << "number of values less than " << x
             << ": " << count(vec,[&](int a){ return a<x; })
             << '\n';

        cout << "number of values less than " << s
             << ": " << count(lst,[&](const string& a){ return a<s; })
             << '\n';
}
```

The notation [&](int a){ return a<x; } is called a lambda expression. It generates a function object similar to Less_than<int>{x}. The [&] is a capture list specifying that all local names used in the lambda body (such as x) will be accessed through references. Had we wanted to ‘‘capture’’ only x, we could have said so: [&x]. Had we wanted to give the generated object a copy of x, we could have said so: [x]. Capture nothing is [ ], capture all local names used by reference is [&], and capture all local names used by value is [=].

For a lambda defined within a member function, [this] captures the current object by reference so that we can refer to class members. If we want a copy of the current object, we say [∗this]. If we want to capture several specific objects, we can list them. The use of [i,this] in the use of expect() is an example.

- Lambdas can be generic as well.

## Advice
- Use templates to express algorithms that apply to many argument types.
- Use templates to express containers.
- Templates are typre safe, but for unconstrained templates checking happens too late.
- Use function objects as arguments to algorithms.
- Use a lambda if you need a simple function objct in one place only.
- A virtual function member cannot be a template member function.
- Use finally() to provide RAII for types without destructors that require "cleanup operations".
- Use template aliases to simplify notation and hide implementation details.
- Use if constexpr to provide alternative implementations without run-time overhead.
