// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <string.h>

bool append_and_delete(const char *s1, int n1, const char *s2, int n2, int n_ops);
int common_prefix_length(const char *s1, int n1, const char *s2, int n2);

int main()
{
    constexpr int max_size = 101;
    char s1[max_size], s2[max_size];
    scanf("%s %s", s1, s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int n_ops;
    scanf("%d", &n_ops);

    puts(append_and_delete(s1, n1, s2, n2, n_ops) ? "Yes" : "No");

    return 0;
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
bool append_and_delete(const char *s1, int n1, const char *s2, int n2, int n_ops)
{
    int prefix_len = common_prefix_length(s1, n1, s2, n2);
    int ops_needed = (n1 - prefix_len) + (n2 - prefix_len);
    if (n_ops < ops_needed)
        return false;

    if (n_ops >= n1 + n2)
        return true;

    return (n_ops - ops_needed) % 2 == 0;
}

int common_prefix_length(const char *s1, int n1, const char *s2, int n2)
{
    int min_len = n1 <= n2 ? n1 : n2;
    for (int i = 0; i < min_len; ++i)
        if (s1[i] != s2[i])
            return i;
    return min_len;
}
