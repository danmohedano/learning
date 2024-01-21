---
date: 2024-01-20
type: note/language
language: C++
focus: "functions and files"
sourceType: tutorial
source: "[https://www.learncpp.com/cpp-tutorial/introduction-to-functions/](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)"
tags: cpp, basics, functions, files
---

# Introduction to Functions

```cpp
returnType function_name() // function header
{
    // function body
}
```

# Function return Values (value-returning functions)

When the return statement is executed, the function exits immediately, and the return value is copied from the function back to the caller. This process is called **return by value**.

The C++ standard only defines the meaning of 3 status codes: `0`, `EXIT_SUCCESS` and `EXIT_FAILURE`. These last two are **preprocessor macros** defined in the `cstdlib` header.

# Void Functions (non-value Returning functions)

To tell the compiler that a function does not return a value, a return type of `void` is used.

# Introduction to Function Parameters and Arguments

A **function parameter** is a variable used in the header of a function. Function parameters work almos identically to variables defined inside the function, but with one difference: they are initialized with a value provided by the caller of the function.

An **argument** is a value that is passed from the caller to the function when a function call is made.

When a function is called, all the parameters of the function are created as variables, and the value of each of the arguments is cpoied into the matching parameter (using copy intialization). This process is called **pass by value**. Function parameters that utilize pass by value are called **value parameters**. 

# Introduction to Local Scope

Variables defined inside the body of a function are called **local variables**. Function parameters are also generally considered to be local variables.

An identifier's **scope** determines where the identifier can be seen and used within the source code. 

A **temporary object** (also sometimes called an **anonymous object**) is an unnamed object that is created by the compiler to store a value temporarily. Temporary objects have no scope at all, since scope is a property of an identifier, and temporary objects have no identifier. Temporary objects are destroyed at the end of the full expression in which they are created. 

# Forward Declarations and Definitions

A better solution to reorganizing the order of definition of functions is the use of **forward declaration**. It allows us to tell the compiler about the existence of an identifier before actually defining the identifier.

```cpp
int add(int x, int y); 

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3,4) << std::endl;
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```

A **declaration** tells the compiler about the existence of an identifer and its associated type information. A **definition** is a declaration thata actually implements or instantiates the identifier.

Functions that share an identifier but have different sets of parameters are also considered to be distinct functions, so such definitions do not violate the ODR (**One Definition Rule**).

# Naming Collisions and an Introduction to Namespaces

A **namespace** is a region that allows you to declare names inside of it for the purpose of disambiguation. The namespace provides a scope region (called **namespace scope**) to the names declared inside of it. 

# Introduction to the Preprocessor

Prior to compilation, each code file goes through a **preprocessing** phase. One of the tasks of the preprocessor is to process `#include` directives. When the preprocessor has finished processing a code file, the result is called a **translation unit**. 

**Preprocessor directives** are instructions that start with `#` and end with a newline. 

# Header Files

A **header file** is used to contain all the forward declarations.

# Header Guards

**Header guards** are conditinal compilation directives used to avoid duplicate definition problems with header files. 

```cpp
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
// the declarations
#endif
```

Modern compilers also support a simpler, alternate form of header guards using the `#pragma` preprocessor directive:

```cpp
#pragma once
// code here
```

Because `#pragma once` is not defined by the C++ standard, it is possible that some compilers may not implement it. 