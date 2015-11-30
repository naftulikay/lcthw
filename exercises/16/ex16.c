#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// a method which returns a pointer to a Person struct
struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

//  free all owned pointers first, else memory leak
    free(who->name);
//  then free the person object
    free(who);
}

void Person_print(struct Person *who)
{
    printf("{ name: %s, age: %d, height: %d, weight: %d }\n",
        who->name, who->age, who->height, who->weight);
}

int main(int argc, char *argv[])
{
//  create two people structs
    struct Person *joe = Person_create("Joe Bumblebee", 32, 64, 140);
    struct Person *frank = Person_create("Frank \"Teh Chill\" Brosefson", 20, 72, 180);

//  print them out with their locations in memory
    printf("joe lives at %p\n", joe);
    Person_print(joe);

    printf("frank lives at %p\n", frank);
    Person_print(frank);

//  make everyone +20 years older
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    frank->age += 20;
    frank->weight += 20;

    Person_print(joe);
    Person_print(frank);

//  destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
