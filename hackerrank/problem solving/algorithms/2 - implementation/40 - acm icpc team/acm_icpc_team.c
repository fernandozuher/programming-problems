// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_binaries(int n1, int n2);
void acm_team(char **binaries, int n, int *res);
int count_subjects_known_by_2_teams(const char *a, const char *b);

int main()
{
    int attendees, topics;
    scanf("%d %d", &attendees, &topics);
    char **binaries = read_binaries(attendees, topics);

    int res[2];
    acm_team(binaries, attendees, res);
    printf("%d\n%d", res[0], res[1]);

    for (int i = 0; i < attendees; ++i)
        free(binaries[i]);
    free(binaries);

    return 0;
}

char **read_binaries(int n1, int n2)
{
    auto binaries = (char **) malloc(sizeof(char *) * n1);
    for (int i = 0; i < n1; ++i) {
        binaries[i] = (char *) malloc(sizeof(char) * (n2 + 1)); // +1 = \0
        scanf("%s", binaries[i]);
    }
    return binaries;
}

void acm_team(char **binaries, int n, int *res)
{
    int max_subjects = 0;
    int teams_with_max = 0;

    for (int i = 0, n1 = n - 1; i < n1; ++i)
        for (int j = i + 1; j < n; ++j) {
            int known_subjects = count_subjects_known_by_2_teams(binaries[i], binaries[j]);

            if (known_subjects > max_subjects) {
                max_subjects = known_subjects;
                teams_with_max = 1;
            } else if (known_subjects == max_subjects)
                ++teams_with_max;
        }

    res[0] = max_subjects;
    res[1] = teams_with_max;
}

int count_subjects_known_by_2_teams(const char *a, const char *b)
{
    int count = 0;
    for (int i = 0, n = strlen(a); i < n; ++i)
        if (a[i] == '1' || b[i] == '1')
            ++count;
    return count;
}
