Consider first a single argu- ment for several alternative functions:
 - If the argument doesn’t match the concept, that alternative cannot be chosen.
 - If the argument matches the concept for just one alternative, that alternative is chosen.
 - If arguments from two alternatives match a concept and one is stricter than the other (match all the requirements of the other and more), that alternative is chosen.
 - If arguments from two alternatives are equally good matches for a concept, we have an ambiguity.
For an alternative to be chosen it must be
 - a match for all of its arguments, and
 - at least an equally good match for all arguments as other alternatives, and
 - a better match for at least one argument.


## Concepts and Types
A type:
 - Specifies the set of operations that can be applied to an object, implicitly and explicitly
 - Relies on function declarations and language rules
 - Specifies how an object is laid out in memory

A single-argument concept:
 - Specifies the set of operations that can be applied to an object, implicitly and explicitly
 - Relies on use patterns reflecting function declarations and language rules
 - Says nothing about the layout of the object
 - Enables the use of a set of types

## Generic Programming
For basic use, consider the concept regular (§14.5). A type is regular when it behaves much like
an int or a vector. An object of a regular type
 - can be default constructed.
 - can be copied (with the usual semantics of copy, yielding two objects that are independent and compare equal) using a constructor or an assignment.
 - can be compared using== and !=.
 - doesn’t suffer technical problems from overly clever programming

The process of generalizing from a concrete piece of code (and preferably from several) while preserving performance is called lifting. Conversely, the best way to develop a template is often to
 - first, write a concrete version
 - then, debug, test, and measure it
 - finally, replace the concrete types with template arguments.

## Advice
- When designing a template carefully consider the concepts assumed for its template arguments.
- When designing a template, use a concrete version for initial implementation, debugging, and measurement.
- Use concepts as design tools
- Specify concepts for all template arguments.
- Whenever possible use named concepts.
- Use templates to express containers and ranges.
