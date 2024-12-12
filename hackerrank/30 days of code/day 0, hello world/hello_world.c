// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    char input[105];
    scanf("%104[^\n]", input);
    puts("Hello, World.");
    puts(input);
    return 0;
}
