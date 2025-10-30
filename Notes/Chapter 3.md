Welp, Mac does not support all of the C++20 functionality. :pulling_out_hair_emote:


## Header Files

Header files contain the declaration and the .cpp file of the same name would then contatin the implementation of the code.
For example vector.h contains the definitions of the class and its members. The vector.cpp file contains the implementation of the methods.

All modules or files that include the header file like so: `#include "header.h"` share the header interface information. The files are independent just that they share the common imported interface.

Disadvantages of using header files:
- Compilation Times: If the header file is included **n** number of times then the compiler will process the header file **n** number of times.
- Order Dependencies: The ordering of header files matter, i.e., if you import h1 and then h2 then the result can be different than when you import h2 then h1.
- Transitivity: All code that is needd to express the header file contents should be present in the header file itself. This leads to *bloated header files*. The header files may also `include "some_other_header.h"`, which can further increase the bloat.
- Inconsistencies: Multiple definitions of the same entity or slightly different definitions of the same entity in different modules/headers lead to subtle bugs or errors, and sometimes crashes.

## Modules
Module similar to header file gives us the ability to bundle up some interface and implementaion and export it. The key differences being:
- A module is compiled only once, as opposed to header which is compiled for every use.
- Two modules can be imported in any order without them affecting one another.
- If you import or #include something into a module, users of your module do not implicitly gain access to (and are not bothered by) that: import is not transitive.

## Other Randon Stuff
- In a function argument `int sum(const vector<int> &v)` const indicates that the function will not modify the passed variable, i.e. the passed argument is immutable.
- Of course there's pass by value and pass by reference. Typically pass by value would be used for smaller value types, and pass by reference for bigger ones or ones that are heap allocated since copying them over incurs a significant overhead.
 - For bigger types that you want to build locally and return from the function, the compiler performs copy elision (essentially copy and construct the type wherever needed). So, you should avoid manual memory management via pointers.

 ## Advic
 - Prefer modules over headers wherever possible. For me its never happening C++20 support is just not there yet for Mac.
 - Do not use using directives inside of header files.
 - Avoid non-inline function definitions in headers.
 - Prefer to pass-by-**const**-reference over plain pass-by-reference.
