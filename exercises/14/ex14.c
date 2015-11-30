#include <ctype.h>
#include <stdio.h>

// forward declarations: "interface" for method
int can_print_it(char ch);
void print_letters(char arg[]);

// implementation of methods
int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

void print_letters(char arg[])
{
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];
        printf("'%c' == %d ", ch, ch);
    }

    printf("\n");
}

// other methods
void print_arguments(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
}

// main
int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
