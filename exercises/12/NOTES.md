Notes on Exercise 12
====================

`argc` is always one longer than you might expect. This is because `argv[0]` is the name of the program:

```
// prints exercises/11/ex11
printf("name of program: %s\n", argv[0]);
```
