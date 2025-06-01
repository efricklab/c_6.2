#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char greeting[100];
    char compareStr[50] = "Hello";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline from fgets

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);

    printf("\n%s!\n", greeting);
    printf("The greeting has %lu characters.\n", strlen(greeting));

    if (strncmp(greeting, compareStr, 5) == 0) {
        printf("The greeting starts with 'Hello'.\n");
    } else {
        printf("The greeting does not start with 'Hello'.\n");
    }

    return 0;
}
