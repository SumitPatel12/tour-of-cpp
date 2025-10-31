## What to keep in mind while designing classes?
- Formulating invariants lets us know precisely what we want.
- Invariants force us to be specific; giving us a better change of getting our implementation correct.
- Better use RAII than having your code littered with try-catch statements.


## Error Handling Alternatives
- First off, throwing a value as error costs the compiler more than just returning the value. So, be sparing with throwing errors.
- You can handle exceptions in one of the following ways.
 1. Throw an exception.
 2. Return a value that indicates failure. Someting like with int main where non-zero values indicate failure.
 3. Terminating the whole program. **This should be done in some very exceptional cases only. Don't be trigger happy with this.**


## Assertions
- We got normal `assertion` which only fire off in debug mode.
- Then we got `static_assert` that checks at compile time for constant expressions.

## Other Stuff
- We've got try-catch blocks.
  - You can have generic error catching or concrete ones i.e. you are expecting say out_of_range error than just type that out in the catch and we'll match that only. You can ofcourse have multiple catches matching each error type you want handled with the more generic ones at the bottom (ordering matters).
- Resource Acquisition Is Initialization; RAII. We'll see more of it in the next chapter but this seems like something I should know more about so adding here.
  - Basic idea is that the constructor is in charge of releasing the resources that the class holds. This is generally done via a destructor.
  - I see why Rust does some things as it does now. Also I can see why a lot of people say that you see the appeal of the language more after you had to write a bunch of stuff by hand in C or C++. I also see why all the memes about skill issues for someone using rust are so famous. :laughing:
- `noexpect`: Any function that we know should not fail can be declared with the `noexpect` keyword. It makes sure any failure of the function would result in terminate the program. So, once again don't be trigger happy with this. For example if a function decalread as noexpect calls another function that can throw an error, then that error will also convert to a terminate.

## Advice
- Throw exceptions to indicate that you cannot perform the assigned task.
- Exceptions for error handling only.
- Failing to open a file or reaching the end of a file are expected events, not exceptions.
- Use error codes when an immediate caller is expected to handle the error.
- **Develop error handling strategies early in a design.**
- **Design your error-handling strategy around invariants.**
- Prefer to use purpose-designed user-defined types as Exceptions rather than built-in types.
- Let your constructor establish an Invariant and throw if it cannot.
- **What can be checked at compile-time is best checked at compile time.**
