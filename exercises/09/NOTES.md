Notes for Exercise 09
=====================

Integer arrays are initialized as zeroes by default:

```
int numbers[4] = { 0 };
// returns 0 0 0 0
for (int i = 0; i < (sizeof(numbers) / sizeof(int)); i++)
    printf("%d ", numbers[i]);
```

---

Character arrays are initialized as the null character, which is `\0` and equivalent to the integer 0:

```
int name[4] = { 'a' };
printf("name[1] == 0: %s\n", name[1] == 0 ? "true" : "false");
```

---

When creating string literals, convention is to use this syntax:

```
char *name = "Teeks";
```
