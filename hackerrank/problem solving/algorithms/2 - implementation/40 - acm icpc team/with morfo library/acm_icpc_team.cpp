// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

tuple<int, int> acm_team(const vector<string>& binaries);
int count_subjects_known_by_2_teams(string_view a, string_view b);

int main()
{
    int attendees = morfo::read();
    morfo::skip_input();
    vector<string> binaries = morfo::read(attendees);
    auto [maxSubjects, teamsWithMax] { acm_team(binaries) };
    morfo::println(vector{ maxSubjects, teamsWithMax });
    return 0;
}

tuple<int, int> acm_team(const vector<string>& binaries)
{
    int max_subjects{};
    int teams_with_max{};

    for (size_t i{}, n1{ binaries.size() - 1 }; i < n1; ++i)
        for (size_t j{ i + 1 }; j < binaries.size(); ++j) {
            int known_subjects{ count_subjects_known_by_2_teams(binaries.at(i), binaries.at(j)) };

            if (known_subjects > max_subjects) {
                max_subjects = known_subjects;
                teams_with_max = 1;
            }
            else if (known_subjects == max_subjects)
                ++teams_with_max;
        }

    return { max_subjects, teams_with_max };
}

int count_subjects_known_by_2_teams(string_view a, string_view b)
{
    return ranges::count_if(views::zip(a, b), [](auto x) { return get<0>(x) == '1' || get<1>(x) == '1'; });
}
