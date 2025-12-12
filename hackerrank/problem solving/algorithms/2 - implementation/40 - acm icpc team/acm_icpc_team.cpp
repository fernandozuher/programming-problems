// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// C++23

import std;
using namespace std;

constexpr int n_bitset{ 500 };

vector<bitset<n_bitset>> read_binaries(int n);
tuple<int, int> acm_team(const vector<bitset<n_bitset>>& binaries);
int count_subjects_known_by_2_teams(const bitset<n_bitset>& a, const bitset<n_bitset>& b);

int main()
{
    int attendees, topics;
    cin >> attendees >> topics;
    vector<bitset<n_bitset>> binaries{ read_binaries(attendees) };
    auto [maxSubjects, teamsWithMax] {acm_team(binaries)};
    cout << maxSubjects << '\n' << teamsWithMax;
    return 0;
}

vector<bitset<n_bitset>> read_binaries(int n)
{
    vector<bitset<n_bitset>> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

tuple<int, int> acm_team(const vector<bitset<n_bitset>>& binaries)
{
    int max_subjects{};
    int teams_with_max{};

    for (auto range{ span(binaries.begin(), binaries.end() - 1) }; const auto& [i, a] : range | views::enumerate)
        for (const auto& b : binaries | views::drop(i + 1)) {
            int known_subjects{ count_subjects_known_by_2_teams(a, b) };

            if (known_subjects > max_subjects) {
                max_subjects = known_subjects;
                teams_with_max = 1;
            }
            else if (known_subjects == max_subjects)
                ++teams_with_max;
        }

    return { max_subjects, teams_with_max };
}

int count_subjects_known_by_2_teams(const bitset<n_bitset>& a, const bitset<n_bitset>& b)
{
    return (a | b).count();
}
