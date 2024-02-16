---
date: 2024-02-15
type: note
focus: "cmake"
description: "'Mastering CMake' book notes"
source: https://cmake.org/cmake/help/book/mastering-cmake/index.html
tags: cmake, build
---

# Getting Started

The `CMakeLists.txt` files are plain text files that contain the project description in CMake's Language.

The simplest possible `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.20)
project(Hello)
add_executable(Hello Hello.c)
```

The `project` command sets the name of the project and may specify other options such as language or version.

For each directory in a project where the `CMakeLists.txt` file invokes the `project` command, CMake generates a top-level Makefile or IDE project file. The project will contain all targets that are in the `CMakeLists.txt` file and any subdirectories, as specified by the `add_subdirectory` command. If the `EXCLUDE_FROM_ALL` option is used in the `add_subdirectory` command, the generated project will not appear in the top-level Makefile or IDE project file; this is useful for generating subprojects that do not make sense as part of the main build process (for example, build examples).

## Specifying Compiler and Compile Flags

The `CC` environment variable specifies the C compiler, while `CXX` specifies the C++ compiler. They can also be specified directly on the command line using `-DCMAKE_CXX_COMPILER=cl`. The flags for the compiler and the linker can also be changed by setting environment variables. Setting `LDFLAGS` will initialize the cache values for link flags, while `CXXFLAGS` and `CFLAGS` will initialize `CMAKE_CXX_FLAGS` and `CMAKE_C_FLAGS` respectively.

## Build Types

They allow a project to be built in different ways, i.e. debug, optimized, etc.

The configuration can be specified with the `CMAKE_BUILD_TYPE` variable. 

```sh
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
$ cmake .. -DCMAKE_BUILD_TYPE=Release
```

# Writing CMakeLists Files

## Comments

Start with `#` and run to the end of the line

## Variables

A number of useful variables are automatically defined by CMake and are discussed in the [`cmake-variables`](https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html#manual:cmake-variables(7)) manual. These variables begin with `CMAKE_`.

Use the `set` command to set variable values. Multiple value arguments are packed into a semicolon-separated list and stored in the variable as a string.

```cmake
set(Foo a)        # value is "a"
set(Foo "a b c")  # value is "a b c"
set(Foo a b c)    # value is "a;b;c"
```

Varaibles may be referenced in command arguments using syntax `${VAR}`. Replacement is performed prior to the expansion of unquoted arguments, so varaible values containing semicolons are split into zero-or-more arguments in place of the original unquoted argument.

```cmake
set(Foo a b c)
command(${Foo})   # expands to three arguments
command("${Foo}") # expands to one argument with value "a;b;c" 
```

To access system environment variables, use the syntax `$ENV{VAR}`.

When you set a variable, it is visible to the current `CMakeLists` file or function and any subdirectory's `CMakeLists` files, any functions or macros that are invoked, and any files that are included using the `include` command.

For CMake to return a value from a function, the `set` command accepts the option `PARENT_SCOPE`.

```cmake
function(foo)
    set(test 2 PARENT_SCOPE)
endfunction()

set(test 1)
foo()
...
```

## Commands

All whitespace is ignored except to separate arguments. Therefore, commands may span multiple lines as long as the command name and the opening parenthesis are on the same line.

### Basic Commands

`set` and `unset` explicitly set and unset variables. The `string`, `list`, and `separate_arguments` commands offer basic manipulation of strings and lists.

The `add_executable` and `add_library` commands are the main commands for defining the executables and libraries to build, and which source files comprise them.

## Flow Control

- Conditional statements: `if`

```cmake
if(FOO)
    # do something
elseif()
    # do something else if
else()
    # do something else
endif()
```

- Looping constructs: `foreach` and `while`

```cmake
foreach(tfile
        TestX
        TestY
        TestZ
        )
    add_test(${tfile}-image ...)
endforeach()
```

The loop variable is replaced prior to any other variable expansion. This means that in the body of a `foreach` loop, you can construct variable names using the loop variable.

- Procedure definitions: `macro` and `function`

The main differences are that a macro does not push and pop a new variable scope, and that the arguments to a macro are not treated as variables but as strings replaced prior to execution. The `macro` command also supports defining macros that take variable argument lists, which can be referenced using `ARGC` and `ARGV0`, `ARGV1`, etc.

## Advanced Commands

- `add_dependencies`: creates a dependency between two targets.
- `include_regular_expression`: controls the regular expression that is used for tracing source code dependencies. 

# CMake Cache

The CMake cache may be thought of as a configuration file. The first time CMake is run on a project, it produces a `CMakeCache.txt` file in the top directory of the build tree. CMake uses this fiel to store a set of global cache variables, whose valeus persist across multiple runs within a project build tree.

To create a variable in the cache, use commands like `option`, `find_file`, or the standard `set` command with the `CACHE` option.

Another purpose oof the cache is to allow CMake itself to persistently store values between CMake runs.

## Setting Initial Values for CMake

The first way is to pass the cache values on the CMake command line using `-DCACHE_VAR:TYPE=VALUE`. The second way is to create a file to be loaded using `cmake`'s `-C` option. 

# Key Concepts

## Targets

Targets represent executables, libraries and utilites built by CMake. Every `add_library`, `add_executable` and `add_custom_target` command creates a target. 

```cmake
add_library(foo STATIC foo1.c foo2.c) # creates a target named "foo" that is a static library, with foo1.c and foo2.c as source files
```

Libraries can be declared as a particular type such as `STATIC`, `SHARED`, `MODULE` or left undeclared.

- `STATIC` - built as static library
- `SHARED` - built as shared library
- `MODULE` - built so that it can be dynamically loaded into an executable. 

In addition to storing their type, targets also keep track of general properties. These properties can be set and retrieved using the `set_target_properties` and `get_target_properties` commands, or the more general `set_property` and `get_property` commands. One useful property is `LINK_FLAGS`, which is used to specify additional link flags for a specific target. 

## Usage Requirements

CMake will also propagate "usage requirements" from linked library targets. Usage requirements affect compilation of sources in the `<target>`. For example, to specify include directories that are required when linking to a library, you can do the following:

```cmake
add_library(foo foo.cxx)
target_include_directories(foo PUBLIC
                           "${CMAKE_CURRENT_BINARY_DIR}"
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )
```

The order of the included directories brought in through "usage requirements" will match the order of the targets in the `target_link_libraries` call.

For each library or executable CMake creates, it tracks all the libraries on which the target depends using the `target_link_libraries` command.

```cmake
add_library(foo foo.cpp)
target_link_libraries(foo bar)

add_executable(foobar foobar.cpp)
target_link_libraries(foobar foo)
```

# CMake Tutorial

## Basic Starting Point (Step 1)

### Version Number and Configured Header File

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.2)

configure_file(TutorialConfig.h.in TutorialConfig.h)
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ) # add to path because the configured file will be written to the binary tree

# add the executable
add_executable(Tutorial tutorial.cxx)
```

```cpp
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

CMake will then automatically configure this header file and replace the values. 

### Specify C++ Standard

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

## Adding a Library (Step 2)

For the tutorial, the library will be put into a subdirectory called `MathFunctions`. This directory already contains a header file, `MathFunctions.h` and a source file `mysqrt.cxx`. 

```cmake
add_library(MathFunctions MathFunctions.cxx mysqrt.cxx)
```

To make use of the new library, we will:

- Add an `add_subdirectory` call in the top-level `CMakeLists.txt` file so that the library will get built
- Add the new library to the executable
- Add `MathFunctions` as an include directory so that the header file can be found

```cmake
add_subdirectory(MathFunctions)
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial PUBLIC MathFunctions)
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MathFunctions)"
                           )
```

To make the MathFunctions library optional, we can add the option to the `MathFunctions/CMakeLists.txt`:

```cmake
option(USE_MYMATH "Use tutorial provided math implementation" ON)
```

The next step is to make the building and linking conditional (and make the option a compile definition).

```cmake
if(USE_MYMATH)
    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
```

Then the source code for `MathFunctions/MathFunctions.cxx` must be updated to use the correct implementation:

```cpp
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
```

Also, to avoid `mysqrt.cxx` being compiled even when the option is disabled, we can add the following commands to the conditional:

```cmake
add_library(SqrtLibrary STATIC mysqrt.cxx)
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
```

Therefore, `mysqrt.cxx` can be removed from the `MathFunctions` library source list.

To update the value of the option, the following command can be run:

```sh
cmake .. -DUSE_MYMATH=OFF
```