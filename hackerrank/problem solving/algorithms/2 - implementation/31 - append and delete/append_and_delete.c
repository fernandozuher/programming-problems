// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <string.h>

bool append_and_delete(const char *s1, int n1, const char *s2, int n2, int n_ops);
int common_prefix_length(const char *s1, int n1, const char *s2, int n2);

int main()
{
    constexpr int max_size = 101;
    char initial_string[max_size], final_string[max_size];
    scanf("%s %s", initial_string, final_string);
    int n1 = strlen(initial_string);
    int n2 = strlen(final_string);

    int n_operations;
    scanf("%d", &n_operations);

    append_and_delete(initial_string, n1, final_string, n2, n_operations) ? puts("Yes") : puts("No");

    return 0;
}

bool append_and_delete(const char *s1, int n1, const char *s2, int n2, int n_ops)
{
    int prefix_len = common_prefix_length(s1, n1, s2, n2);
    int total_ops_needed = (n1 - prefix_len) + (n2 - prefix_len);
    bool can_remove_all = n_ops >= n1 + n2;
    return can_remove_all || (n_ops >= total_ops_needed && (n_ops - total_ops_needed) % 2 == 0);
}

int common_prefix_length(const char *s1, int n1, const char *s2, int n2)
{
    int min_len = n1 <= n2 ? n1 : n2;
    for (int i = 0; i < min_len; ++i)
        if (s1[i] != s2[i])
            return i;
    return min_len;
}
