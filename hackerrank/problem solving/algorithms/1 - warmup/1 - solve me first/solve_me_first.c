#include <stdio.h>

int solve_me_first(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int sum = solve_me_first(num1, num2);
    printf("%d", sum);
    return 0;
}