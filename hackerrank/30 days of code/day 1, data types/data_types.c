// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true
// From C23 onwards

#include <stdio.h>

int main()
{
    constexpr int i = 4;
    constexpr double d = 4.0;
    constexpr char s[] = "HackerRank ";

    int i2;
    double d2;
    char s2[50];
    scanf("%d %lf %49[^\n]", &i2, &d2, s2);

    printf("%d\n", i + i2);
    printf("%.1lf\n", d + d2);
    printf("%s%s\n", s, s2);

    return 0;
}
