// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    char input_string[105];
    scanf("%104[^\n]", input_string);
    puts("Hello, World.");
    puts(input_string);

    return 0;
}
