Notes on Exercise 14
====================

It's possible to define "abstract methods" or "method interfaces" in C, and this is typically done in C header files
such as `myprogram.h`:

```
// define method interface in myprogram.h
int dowerk(int id);

// define method implementation in myprogram.c
#include "myprogram.h"

int dowerk(int id) {
    return id + 1;
}
```
