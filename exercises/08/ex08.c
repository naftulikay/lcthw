#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = { 10, 12, 13, 14, 20 };

    char name[] = "Doofus";
    char full_name[] = {
        'D', 'o', 'o', 'f', 'u', 's',
        ' ',
        'M', 'c', 'G', 'e', 'e', '\0'
    };

    // WARNING: on some systems you may have to change the %ld in this code
    // to %u because it will use unsigned ints underneath the hood.
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    // want to find out how long an array is in C? sizeof(array) / sizeof(array_type)
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
    printf("The first area is %d, the second is %d\n", areas[0], areas[1]);
    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("Number of chars in full_name: %ld\n", sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
