// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read(int n);
int find_most_spotted_bird(const vector<int>& bird_sightings);

int main()
{
    int n;
    cin >> n;
    vector array{read(n)};
    ranges::sort(array);
    cout << find_most_spotted_bird(array);
    return 0;
}

template<class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

int find_most_spotted_bird(const vector<int>& bird_sightings)
{
    int most_spotted_bird{bird_sightings.front()};
    int count_most_spotted_bird{1};
    int temp_count_most_spotted_bird{1};

    for (const auto [current_bird, next_bird] : bird_sightings | views::adjacent<2>) {
        if (current_bird == next_bird)
            ++temp_count_most_spotted_bird;

        else if (temp_count_most_spotted_bird > count_most_spotted_bird) {
            most_spotted_bird = current_bird;
            count_most_spotted_bird = temp_count_most_spotted_bird;
            temp_count_most_spotted_bird = 1;
        }
    }

    if (temp_count_most_spotted_bird > count_most_spotted_bird)
        most_spotted_bird = bird_sightings.back();

    return most_spotted_bird;
}
