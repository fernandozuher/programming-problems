// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

char **read_binaries(int n1);
void acm_team(char **binaries, int n, int n_topics, int *res);
int count_subjects_known_by_2_teams(const char *a, const char *b, int n);

int main()
{
    int n = morfo_read(int);
    int m = morfo_read(int);
    char **binaries = read_binaries(n);

    int res[2];
    acm_team(binaries, n, m, res);
    morfo_println(res, 2);

    for (int i = 0; i < n; ++i)
        free(binaries[i]);
    free(binaries);

    return 0;
}

char **read_binaries(int n1)
{
    auto binaries = (char **) malloc(sizeof(char *) * n1);
    for (int i = 0; i < n1; ++i)
        binaries[i] = morfo_read(char *);
    return binaries;
}

void acm_team(char **binaries, int n, int n_topics, int *res)
{
    int max_subjects = 0;
    int teams_with_max = 0;

    for (int i = 0, n1 = n - 1; i < n1; ++i)
        for (int j = i + 1; j < n; ++j) {
            int known_subjects = count_subjects_known_by_2_teams(binaries[i], binaries[j], n_topics);

            if (known_subjects > max_subjects) {
                max_subjects = known_subjects;
                teams_with_max = 1;
            } else if (known_subjects == max_subjects)
                ++teams_with_max;
        }

    res[0] = max_subjects;
    res[1] = teams_with_max;
}

int count_subjects_known_by_2_teams(const char *a, const char *b, int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        count += a[i] == '1' || b[i] == '1';
    return count;
}
