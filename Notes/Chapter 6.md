This one was a heavy chapter might need to read it more than once.

## Essential Opertaions
- There are five situations in which an object can be copied or moved:
 - As the source of an assignment
 - As an object initializer
 - As a function argument
 - As a function return value
 - As an exception

- A good rule of thumb is to either define all of the essential operations or none. When none are defined the compiler generates defaults for us if required.
- You can use the `default` keyword to explicitly tell the compiler to generate the default implementation.
 - Classes owning memory on heap (i.e. pointer to objects) are likely not a good target for default copy and move implementations. Reason being, the object we are pointing to might need to be deleted or might not need to be deleted depending on the usecase.
 - You can remember the rule of zero, which states that you either let the compiler generate everything or nothing.
  - The idea behind this is simple say you got a constructor, destructor(it calls `delete` on the list it's pointing to), and move but not copy, and the object has a pointer to a list. Then when you copy the compiler will simply copy it as a reference leading to both objects pointing to the same memory address. Now when the destructor is called for both we will have **double free** which can lead to undefined behaviour.
- Similarly we have the `delete` keyword that tells the compiler not to generate the method.
- For conversions use the `explicit` keyword unless there is a good reason not to. This prevents a host of unwanted implicit casting/conversion which could lead  to errors.
- After a move, the moved-from object should be in a state that allows a destructor to be run.
- You can use the `std::move()` to explicitly tell the compiler to move and not copy.
 - **The standard library move function deosn't actually move anything. It returns a reference to its argument from which we may move - an rvalue reference; it is a kind of case.**

## Advice
- Control construction, copy, move, and destruction of objects.
- Design constructors, assignments, and the destructor as a matched set of operations.
- **Define all essential operations or none.**
- If a class has *poiner* member, consider carefuly if it needs a user-defined or delted destructor, copy, and move.
- If a class has a user-defined destructor, it probably needs user-defined or deleted copy and move.
- By default, declare single-argument constructors explicit.
- Redefine or prohibit copying if the default is not appropriate
- For large operands, use `const` reference argument types.
- If a class is a resource handle, it needs a user-defined constructor, a destructor, and non- default copy operations
- If you overload an operator, define all operations that conventionally work together
