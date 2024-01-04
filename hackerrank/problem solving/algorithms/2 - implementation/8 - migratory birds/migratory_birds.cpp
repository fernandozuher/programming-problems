// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Migratory_Birds {
public:
    Migratory_Birds(const vector<int>& bird_sightings): bird_sightings{bird_sightings}
    {
        find_most_spotted_bird();
    }

    int most_spotted_bird() const;

private:
    vector<int> bird_sightings;
    int n_most_spotted_bird;

    void find_most_spotted_bird();
};

    int Migratory_Birds::most_spotted_bird() const
    {
        return n_most_spotted_bird;
    }

    void Migratory_Birds::find_most_spotted_bird()
    {
        n_most_spotted_bird = bird_sightings.front();
        int count_n_most_spotted_bird {1};
        int temp_count_n_most_spotted_bird {1};

        for (int i {1}, n = bird_sightings.size(); i < n; ++i)

            if (bird_sightings[i] == bird_sightings[i - 1])
                ++temp_count_n_most_spotted_bird;

            else if (temp_count_n_most_spotted_bird > count_n_most_spotted_bird) {
                n_most_spotted_bird = bird_sightings[i - 1];
                count_n_most_spotted_bird = temp_count_n_most_spotted_bird;
                temp_count_n_most_spotted_bird = 1;
            }

        if (temp_count_n_most_spotted_bird > count_n_most_spotted_bird)
            n_most_spotted_bird = bird_sightings.back();
    }

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_int_array(n)};
    ranges::sort(array);

    Migratory_Birds obj(array);
    cout << obj.most_spotted_bird();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, []{int x; cin >> x; return x;});
        return array;
    }
