---
date: 2024-01-20
type: note/language
language: C++
focus: "debugging"
sourceType: tutorial
source: "[https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/](https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/)"
tags: cpp, debugging
---

# Debugging Tactics

1. Commenting out your code. 
2. Validating your code flow. For example, by printing out the names of the functions being executed. For this, it's recommended to use `std::cerr` instead of `std::cout`, as the former is unbuffered. It also helps make clear that the information being output is for an error case rather than a normal case. 
3. Printing values.
4. Conditionalizing your debugging code.
5. Using a logger. C++ contains an output stream named `std::clog` that is intended to be used for writing logging information. However, by default, `std::clog` writes to the standard error stream. You can technically redirect it to a file instead, but it's better to just use a third party solution, like for example `plog`. 
6. Using a debugger. Either integrated in the IDE or standalone (like `gdb`). When using **stepping**, it is preferable to make `std::cout` unbuffered. This can be achieved by adding the following statement: `std::cout << std::unitbuf;`. 