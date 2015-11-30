Notes on Exercise 16
====================

A struct can have a pointer to something of an undefined size, like a string, but it'll still be accessible in an
array, pointers are by definition external.

```
struct Person {
    int id;
    char *name;
}

sizeof(struct Person); // returns sizeof(int) + sizeof(pointer)
```

---

When destroying something, free its owned pointers first, obviously:

```
free(person->name);
free(person);
```

If you try it in the other direction, you'll likely segfault and you've created a memory leak.

---

When accepting a string as a `char *`, you'll likely want to duplicate it into local memory in case it is ever freed elsewhere:

```
struct *thing do_things(char *name)
{
    struct thing *result = malloc(sizeof(struct thing));
    result->name = name;
    return result;
}

int main(int argc, char *argv[])
{
    char *ext_name = "Brosefson"

    struct *thing = do_things(ext_name);

    free(ext_name)

    // probably segfault
    thing->name

    return 0;
}
```



---
