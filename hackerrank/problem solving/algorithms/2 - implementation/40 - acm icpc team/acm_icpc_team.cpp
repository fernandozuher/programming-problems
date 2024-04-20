// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

import <algorithm>;
import <bitset>;
import <iostream>;
import <ranges>;
import <vector>;

using namespace std;

constexpr int n_bitset {500};

namespace {
int count_subjects_known_by_2_teams(const bitset<n_bitset>& binary1, const bitset<n_bitset>& binary2)
{
    return (binary1 | binary2).count();
}
}

class ACM_ICPC_TEAM {
public:
    explicit ACM_ICPC_TEAM(const vector<bitset<n_bitset>>& binaries);
    int max_subjects_known_by_teams() const;
    int teams_that_know_max_subjects() const;
    void find_maximum_subjects_and_teams_that_know_them();

private:
    vector<bitset<n_bitset>> binaries;
    int maximum_subjects_known_by_teams {};
    int teams_that_know_maximum_subjects {};

    void update_maximum_subjects_and_teams_that_know_them(const int subjects_known_by_2_teams);
};

    ACM_ICPC_TEAM::ACM_ICPC_TEAM(const vector<bitset<n_bitset>>& binaries): binaries{binaries} {}

    int ACM_ICPC_TEAM::max_subjects_known_by_teams() const
    {
        return maximum_subjects_known_by_teams;
    }

    int ACM_ICPC_TEAM::teams_that_know_max_subjects() const
    {
        return teams_that_know_maximum_subjects;
    }

    void ACM_ICPC_TEAM::find_maximum_subjects_and_teams_that_know_them()
    {
        auto previous_binaries {span(binaries.begin(), binaries.end() - 1)};
        for (const auto& [i, previous] : previous_binaries | views::enumerate | views::as_const)
            for (const auto& current : binaries | views::drop(i + 1) | views::as_const)
                update_maximum_subjects_and_teams_that_know_them(count_subjects_known_by_2_teams(previous, current));
    }

        void ACM_ICPC_TEAM::update_maximum_subjects_and_teams_that_know_them(const int subjects_known_by_2_teams)
        {
            if (subjects_known_by_2_teams > maximum_subjects_known_by_teams) {
                maximum_subjects_known_by_teams = subjects_known_by_2_teams;
                teams_that_know_maximum_subjects = 1;
            }
            else if (subjects_known_by_2_teams == maximum_subjects_known_by_teams)
                ++teams_that_know_maximum_subjects;
        }

//////////////////////////////////////////////////

int main()
{
    int attendees, topics;
    cin >> attendees >> topics;
    vector<bitset<n_bitset>> binaries(attendees);
    ranges::generate(binaries, [] {bitset<n_bitset> x; cin >> x; return x;});

    ACM_ICPC_TEAM obj{binaries};
    obj.find_maximum_subjects_and_teams_that_know_them();
    cout << obj.max_subjects_known_by_teams() << '\n' << obj.teams_that_know_max_subjects() << '\n';

    return 0;
}
