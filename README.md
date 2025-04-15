# cppslx

Some utilities extending C++23 standard library.

## Introduction

The CppSLX (standing for C++ Standard Library eXtensions) is a collection of C++ definitions that cover some C++ std library shortcomings (as I perceive them, of course).

## Prerequisites

ISO C++20/23-compliant compiler. Modules are not used.

## Building/installing

Header-only library. Just copy it where you want it to reside.

## Contents

### helper\_macros.hpp

#### Static operator() support

You may define a call operator supposed to be static to be static if a compiler supports it or be just const if it does not:

```cpp
struct SayHello
{
    // This operator() does not depend on SayHello state.
    CPPSLX_STATIC_CALL void operator()() CPPSLX_STATIC_CALL_CONST noexcept
    {
        std::cout << "Hello!\n";
    }
};
```

### unpack\_into.hpp

A struct that captures a functional object and applies it to a tuple unpacking tuple into a list of arguments:

```cpp
std::cout << cppslx::unpack_into{std::plus<>{}}( std::tuple{1, 2} ); // > 3
```



