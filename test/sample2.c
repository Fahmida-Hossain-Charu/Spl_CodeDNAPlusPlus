#include <stdio.h>

int multiply(int a, int b) {
    int result = 0;
    for(int i=0; i<b; i++) {
        result += a;
    }
    return result;
}

int main() {
    int x = 3;
    int y = 4;
    int z = multiply(x, y);
    printf("Product: %d\n", z);
    return 0;
}
