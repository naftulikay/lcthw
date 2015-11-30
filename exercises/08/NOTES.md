Notes on Exercise 8
===================

In C, **there is basically no difference between an array of characters and a string**, they're the same thing:

```
char arr1[] = "One";
char arr2[] = { 'T', 'w', 'o', '\0' };
```

The length of a string/character array is always 1 byte greater than the string, as C internally terminates strings
with `\0`:

```
// 6 letter name
char name[] = "Doofus";
// actually returns 7, because it is stored as "Doofus\0" in RAM
sizeof(name);
```

To determine the size of an array in C, divide the size of the array in memory by the size of the array type:

```
int areas[] = { 11, 12, 13, 14 };
// calculate length
int length = sizeof(areas) / sizeof(int);
```

When declaring a string in the character array format **you must manually terminate the string with a `\0` byte**:

```
char arr[] = { 'a', 'b', 'c', '\0' };
```
