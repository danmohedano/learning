---
date: 2024-01-21
type: note/language
language: C++
focus: "constants and strings"
sourceType: tutorial
source: "[https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/](https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/)"
tags: cpp, strings, constants
---

# Constant Variables

C++ supports two different kinds of constants. **Named constants** are constant values that are associated with an identifier. **Literal constants** are constant values that are not associated with an identifier.

Types of named constants: 

- Constant variables: to declare them, you can use the `const` keyword. Because they are constant, they must be initialized when defining them. Making a function parameter constant enlists the compiler's help to ensure that the parameter's value is not changed inside the function, although it is irrelevant for value parameters, as the original variable can't be changed from within the function. 
- Object-like macros with substitution text: it is preferable to use constant variables instead of macros, as the latter ones don't follow normal scoping rules. 
- Enumerated constants

# Literals

**Literals** are values that are inserted directly into the code. If the default type of literal is not as desired, you can change the type of literal by adding a suffix. 

C-style string literals are const objects that are created at the start of the program and are guaranteed to exist for the entirety of the program.

# Constant Expressions and Compile-time Optimization

A **constant expression** is an expression that contains only compile-time constants and operators/functions that support compile-time evaluation. A **compile-time constant** is a constant whose value must be known at compile time. `const` variables that are not compile-time constants are sometimes called **runtime constants**. 

The compiler is only required to evaluate constant expressions at compile-time in contexts that require a constant expression. If they don't, the compiler may choose whether to evaluate a constant expression at compile-time or runtime.

# `Constexpr` Variables

When you declare a `const` variable, the compiler will implicitly keep track of whether it's a runtime or compile-time constant. Because compile-time cosntants also allow for better optimization (and have little downside), we typically want to use compile-time constants wherever possible.