Notes on Exercise 10
====================

The traditional `argv` parameter which is passed to the `main` method in a C program looks like this:

```
char *argv[];
```

Breaking this down, we can work backwards through the assignment to determine what this variable actually is:

 1. `[]`: it is an array
 2. `*`: of pointers
 3. `char`: of type `char`

Since a `char *item` is a standard idiom for defining a string in C, we're just creating an array of those here. If we
were to define array items manually, it'd look like this:

```
char *argv0 = "One";
char *argv1 = "Two";
char *argv2 = "Three";

char *argv[] = { &argv0, &argv1, &argv2 };
```

---

C doesn't allow you to declare variables in for loop initializer blocks. This will fail:

```
for (int i = 0; i < length; i++)
    continue;
```

To work around this, either declare outside of the for loop:

```
int i = 0;
for (i = 0; i < length; i++)
    continue;
```

Or, alternatively, you can compile with C99 support:

```
note: use option -std=c99 or -std=gnu99 to compile your code
```
