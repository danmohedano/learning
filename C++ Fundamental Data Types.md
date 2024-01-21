---
date: 2024-01-20
type: note/language
language: C++
focus: "data types"
sourceType: tutorial
source: "[https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/](https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/)"
tags: cpp, types
---

# Introduction to Fundamental Data Types

C++ comes with built-in support for many different data types. These are called **fundamental data types**, but are often informally called **basic types**, **primitive types**, or **built-in types**.

# Void

Void is an **incomplete type**. An **incomplete type** is a type that has been declared but not yet defined. 

# Object Sizes and the `sizeof` Operator

The C++ standard does not define the exact size (in bits) for any of the fundamental types, although it does define its minimum size in bytes. The `sizeof` operator is a unary operator that takes either a type or a variable and returns its size in bytes. The operator does not include dynamically allocated memory used by an object.

# Signed Integers

The integer types (`short`, `int`, `long`, `long long`) can also take an optional `signed` keyword, which is by convention typically placed before the type name. However, this keyword is redundant.

When dividing two integers, C++ performs **integer division**, where the result is**dropped** (not rounded).

# Unsigned Integers and why to Avoid Them

Unsigned integer types can be defined with the keyword `unsigned`. For unsigned integers, when overflow happens, it acts as a modulo operation. It is not recommended to use unsigned integers because they are easier to overflow on the bottom of the range. Also, unexpected behaviour can result when you mix signed and unsigned integers. In C++, if a mathematical operation has one signed integer and one unsigned integer, the signed integer will usually be converted to an unsigned integer. And the result will thus be unsigned.

# Fixed-width Integers and `size_t`

To address the issues caused by not having fixed sizes in integer variables, **fixed-width integers** are also defined, available in the `<cstdint>` header. These ensure the size of the integer type, like `std::uint8_t`, `std::uint64_t`, etc.

But this can also cause problems. They might not be defined on all architectures, and your CPU might be faster handling specific widths. 

To solve this, C++ also introduces **fast types**. `std::int_fast#_t` and `std::uint_fast#_t` provide the fastest signed/unsigned integer type with a width of at least `#` bits. The **least types** `std::int_least#_t` and `std::uint_least#_t` provide the smallest signed/unsigned integer type with a width of at least `#` bits. 

Also take into account that due to an oversight in the C++ specification, most compilers define and treat `std::int8_t` and `std::uint8_t` identically to types `signed char` and `unsigned char`, which may cause some problems.

To avoid problems with integer types and their widths when returning actual sizes, the type `size_t` is defined. It is defined in a number of different headers, but `<cstddef>` is probably the best one. 

# Floating point Numbers

Always make sure the type of your literals matches the type of the variables they're being assigned to or used to initialize. By default, no suffix means a double type.

To override the default precision that `std::cout` shows, you can use `std::setprecision()`, defined in the `iomanip` header. 

# Boolean Values

To make `std::cout` print `true` or `false` instead of `0` or `1`, you can use `std::boolalpha`. This also is applicatble to `std::cin`, which would otherwise only understand the integer values. 

# Chars

Although `std::cin` allows entering multiple characters, only one can be held by a `char` type. If this is the case, the rest of the characters will be queued for the next time `std::cin` is called.

# Introduction to Type Conversion and `static_cast`

When the compiler does type conversion on our behalf without us explicitly asking, it's called `implicit type conversion`. 

C++ supports a second method of type conversion, **explicit type conversion**. To perform this conversion, you can use the `static_cast<new_type>(expression)` operator. This can also be used to convert from unsigned to signed.