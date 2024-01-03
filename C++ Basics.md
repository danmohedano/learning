---
date: 2024-01-03
type: note/language
language: C++
focus: "Basics"
sourceType: tutorial
source: "[https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/](https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/)"
tags: cpp, basics
---

# Variable Assignment and Initialization
## Initialization Methods

```cpp
int a;
int b = 5;
int c(0);
int d{7};
int e = {5};
int f {};
```

One of the benefits of list initialization is that it disallows "narrowing conversions", for example:

```cpp
int width { 4.5 }; // error
```

## Unused Initialized Variable Warnings

To avoid this kinds of warnings, use the `[[maybe_unused]]` attribute in C++17 and onwards.

```cpp
int main()
{
    [[maybe_unused]] double pi { 3.14159365 };
}
```

# Iostream

`std::cout` is buffered. 

`std::endl` is not only a new line. It moves the cursor to the next line and flushes the buffer.