---
date: 2023-12-14
type: note/language
language: C++
focus: "compiler"
sourceType: doc
source: "[https://clang.llvm.org/](https://clang.llvm.org/)"
tags: C++, compiler
---

Clang is a C language family frontend for LLVM.

Basic compilation:

```sh
clang++ -Wall -Werror -std=c++11 main.cpp
```

When using header files, the `-I` option can be used to tell the compiler where to find the include directory.