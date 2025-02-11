// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true
// From C23 onwards

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    bool is_weird = n & 1 || n >= 6 && n <= 20;
    puts(is_weird ? "Weird" : "Not Weird");
    return 0;
}
