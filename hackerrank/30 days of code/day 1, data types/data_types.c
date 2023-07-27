// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    const int i = 4;
    const double d = 4.0;
    const char s[] = "HackerRank ";

    int i2;
    double d2;
    char s2[50];
    scanf("%d %lf %49[^\n]", &i2, &d2, s2);

    printf("%d\n", i + i2);
    printf("%.1lf\n", d + d2);
    printf("%s%s\n", s, s2);

    return 0;
}
