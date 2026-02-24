// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// C23

#include <stdio.h>

constexpr int min_id = 1;
constexpr int max_id = 5;
constexpr size_t n_distinct_ids = max_id - min_id + 1;

void read_input(int *freq_map);
bool is_valid_id(int x);
int find_most_spotted_bird(const int *birds_to_counts);

int main()
{
    int birds_to_counts[n_distinct_ids] = {};
    read_input(birds_to_counts);
    printf("%d\n", find_most_spotted_bird(birds_to_counts));
    return 0;
}

// n: length of input array
// n_distinct_ids: length of output = 5
// T: O(n)
// S: O(n_distinct_ids) = O(5) = O(1) extra space
void read_input(int *freq_map)
{
    int n;
    scanf("%d", &n);

    for (size_t i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (is_valid_id(x))
            ++freq_map[x - min_id];
    }
}

bool is_valid_id(int x)
{
    return x >= min_id && x <= max_id;
}

// n_distinct_ids: length of array birds_to_counts = 5
// T: O(n_distinct_ids) = O(5) = O(1)
// S: O(1) extra space
int find_most_spotted_bird(const int *birds_to_counts)
{
    int id = 0;
    int count = birds_to_counts[0];

    for (size_t i = 1; i < n_distinct_ids; ++i)
        if (birds_to_counts[i] > count) {
            count = birds_to_counts[i];
            id = (int) i;
        }

    return id + min_id;
}
