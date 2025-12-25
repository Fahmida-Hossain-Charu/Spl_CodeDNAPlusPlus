#include <stdio.h>

void greet(char* name) {
    printf("Hello, %s!\n", name);
}

int main() {
    char name[20] = "Fahmida";
    greet(name);
    return 0;
}
