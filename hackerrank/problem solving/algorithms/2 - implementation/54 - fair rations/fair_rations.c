// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// From C23

#include <stdio.h>

int find_min_loaves_to_satisfy_rules(int n);
    bool is_odd(int n);

int main()
{
    int n;
    scanf("%d", &n);
    int min_loaves = find_min_loaves_to_satisfy_rules(n);
    min_loaves == -1 ? puts("NO") : printf("%d", min_loaves);

    return 0;
}

    int find_min_loaves_to_satisfy_rules(int n)
    {
        int min_loaves_to_satisfy_rules = 0;
        int loaves;
        scanf("%d", &loaves);

        while (--n)
            if (is_odd(loaves)) {
                scanf("%d", &loaves);
                ++loaves;
                min_loaves_to_satisfy_rules += 2;
            } else
                scanf("%d", &loaves);

        return is_odd(loaves) ? -1 : min_loaves_to_satisfy_rules;
    }

        bool is_odd(const int n)
        {
            return n & 1;
        }
