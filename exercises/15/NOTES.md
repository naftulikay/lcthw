Notes on Exercise 15
====================

fscking pointers.

## Regular Pointers

A pointer can act as a 'gateway' to an array like so:

```
int ids[] = { ... };
int *ids_pointer = ids;
```

`ids_pointer` points to the head item at index 0 in `ids`.

## Nested Pointers

Since an array of strings is already an array of pointers, a pointer to items in this array will have to be nested:

```
char *names[] = { ... };
char **names_pointer = names;
```

Again, let's break down what `char *names[]` means. It is:

 1. `[]` an array
 2. `*` of pointers
 3. `char` of type `char`

Therefore, a `char **` is a pointer to a pointer: namely, it points to the first character of the first string in an
array of strings.

Now that _that's_ handled...

## Pointer Incrementing

If a pointer points to an array, the pointer can be incremented or decremented to reach the next or previous item in
the array:

```
int ints[] = { ... };
int *intptr = ints;

printf("0: %d\n", *intptr);
intptr = intptr + 1;
printf("1: %d\n", *intptr);
printf("0: %d\n", *(intptr - 1));
```

Questions:

 1. How does a pointer _know_ how to increment itself? If I'm pointing to a list of `struct` types with some fixed
    length, how would incrementing the pointer automatically point to the next element? Shouldn't it just move the
    pointer forward one byte?

Answers:

 1. The compiler _knows all_. You cannot increment a void pointer. At compile time, it appears that the compiler
    rewrites all pointer incrementation code to increment aligned to the underlying type.

## Pointers Are Arrays, Too

Pointers are also arrays, sort of. If your pointer is pointing at an array, you can access your pointer like an array:

```
int intarr[] = { ... };
int *intptr = intarr;

printf("intarr[0] = %d, intptr[0] = %d\n", intarr[0], intptr[0]);
```

Cool. Not. Just because you can use a pointer like an array and vice versa, doesn't mean that they're the same thing.

When in doubt, if you can, use an array. If you absolutely cannot use an array, use a pointer, but only then.

## Analysis of the Psychotic Method 4

Here's the code:

```
for (cur_name = names, cur_age = ages;
        (cur_age - ages) < count;
        cur_name++, cur_age++) {
    printf("%s lived %d years so far.\n", *cur_name, *cur_age);
}
```

Why does this work? First, let's break down what the code does. Everything is happening in the for loop declaration,
so that's where we start.

 1. Set `cur_name` to point to the head of `names` and `cur_age` to the head of `ages`.
 2. Keep looping while the difference between `cur_age` and `ages`. This is magical™. What happens under the hood here
    is that the compiler evaluates the difference between the memory locations underlying `cur_age` and `ages[0]` and
    divides by `sizeof(int)`. This produces a positive difference, yielding 0 on the first time, 1 on the second, etc.
 3. Finally, on every loop, move the `cur_name` and `cur_age` pointers forward one place in memory,, which means
    `sizeof(int)` in actuality.

Don't use this unless you're psychotic and want to drive everyone mad.

## Pointer Lexicon

<dl>
    <dt><code>type \*ptr</code></dt>
    <dd>A pointer of <code>type</code> named <code>ptr</code></dd>
    <dt><code>\*ptr</code></dt>
    <dd>The value of whatever <code>ptr</code> is pointed at</dd>
    <dt><code>\*(ptr + 1)</code></dt>
    <dd>The value of whatever <code>ptr</code> is pointed at, plus one.</dd>
    <dt><code>&amp;thing</code></dt>
    <dd>The address of <code>thing</code></dd>
    <dt><code>type \*ptr = &amp;thing</code></dt>
    <dd>A pointer of <code>type</code> named <code>ptr</code> pointed to the address of <code>thing</code>.</dd>
    <dt><code>ptr++</code></dt>
    <dd>Increment where <code>ptr</code> points.</dd>
</dl>

This is extremely important with pointers. They come with their own language, which needs to be unwrapped and grokked
completely.
