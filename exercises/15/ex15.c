#include <stdio.h>

int main(int argc, char *argv[])
{
//  create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan",
        "Frank",
        "Mary",
        "John",
        "Lisa"
    };

//  safely get the size of ages
    int count = sizeof(ages) / sizeof(int);

//  first way using indexing
    int i = 0;
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

//  second way, using pointers
//  setup pointers pointing to the HEAD of each array
    int *cur_age = ages;
    char **cur_name = names;

    for (i = 0; i < count; i++) {
//      this is weird AF
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

//  third way, pointers are just arrays
    for (i = 0; i < count; i++) {
//      o.O
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

//  fourth way: stupid and complex hacks
    for (cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
