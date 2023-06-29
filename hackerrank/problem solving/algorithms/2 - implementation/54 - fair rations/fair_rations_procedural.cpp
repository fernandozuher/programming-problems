// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string find_min_loaves_to_satisfy_rules(vector<int>& n_loaves_of_each_person);

int main()
{
    int n_subjects;
    cin >> n_subjects;

    vector<int> n_loaves_of_each_person(n_subjects);
    ranges::generate(n_loaves_of_each_person, [] {int element; cin >> element; return element;});

    cout << find_min_loaves_to_satisfy_rules(n_loaves_of_each_person) << '\n';

    return 0;
}

    string find_min_loaves_to_satisfy_rules(vector<int>& n_loaves_of_each_person)
    {
        int min_loaves_to_satisfy_rules {0};

        for (int i {0}, size {static_cast<int>(n_loaves_of_each_person.size() - 1)}; i < size; ++i)
            if (n_loaves_of_each_person.at(i) % 2) {
                n_loaves_of_each_person.at(i)++;
                n_loaves_of_each_person.at(i + 1)++;
                min_loaves_to_satisfy_rules += 2;
            }

        return n_loaves_of_each_person.back() % 2 ? "NO" : to_string(min_loaves_to_satisfy_rules);
    }
