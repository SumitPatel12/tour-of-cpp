## Concrete Types
- The representation of the object is a part of its definition.
- Refer to objects directly.
- Initialize objects immeditely and completely.
- Copy and move objects.
- **Functions defined in a class are inline by default.**
- You can use the inline keyword to explicitly request inlining.
- By providing a default constructor you eliminate the possibility of uninitialized variables of that type.

## Virtual Functions
- Since there can be a lot of virutal function implementations, to get the correct one to call at runtime the compiler has a hastable *vtbl (virtual function table)*. The usual implementation technique is for the compiler to convert the name of a virtual function into an index into a table of pointers to functions.
 - Each class with virtual functions has its own vtbl.
 - This enables any caller that knows the pointer to the vtbl to call the correct methods irrespective of it's data layout or the size of the object.
- `dynamic_cast` can be used to check the type of an object at runtime.

## Advice
- Make a function a direct member only if it needs direct access to the representation of the class.
- Define operators to primarily mimic conventional usage.
- Use nonmember functions for symmetric operators
- Declare a member function that does not modify the state of its object const
- Avoid ‘‘naked’’ new and delete operations
- A class with a virtual function should have a virtual destructor
- Use dynamic_cast where class hierarchy navigation is unavoidable
- Use dynamic_cast to a reference type when failure to find the required class is considered a failure
- Use dynamic_cast to a pointer type when failure to find the required class is considered a valid alternative
- Use unique_ptr or shared_ptr to avoid forgetting to delete objects created using new
