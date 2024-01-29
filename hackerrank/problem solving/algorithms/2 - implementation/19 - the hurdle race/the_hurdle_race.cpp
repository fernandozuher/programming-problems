// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read_array(const int n);

class Hurdle_Race {
public:
    Hurdle_Race(const vector<int>& hurdles_heights, const int maximum_height_can_jump);
    int doses() const;

private:
    vector<int> hurdles_heights;
    int maximum_height_can_jump;
    int n_doses;

    void hurdle_race();
};

    Hurdle_Race::Hurdle_Race(const vector<int>& hurdles_heights, const int maximum_height_can_jump)
        : hurdles_heights{hurdles_heights},
          maximum_height_can_jump{maximum_height_can_jump},
          n_doses{}
    {
        hurdle_race();
    }

        void Hurdle_Race::hurdle_race()
        {
            int highest_hurdle {*ranges::max_element(hurdles_heights)};
            n_doses = highest_hurdle > maximum_height_can_jump ? highest_hurdle - maximum_height_can_jump : 0;
        }

    int Hurdle_Race::doses() const
    {
        return n_doses;
    }

/////////////////////////////////////////////////

int main()
{
    int n, maximum_height_can_jump;
    cin >> n >> maximum_height_can_jump;
    vector<int> hurdles_heights {read_array(n)};

    Hurdle_Race obj{hurdles_heights, maximum_height_can_jump};
    cout << obj.doses();

    return 0;
}

    template<class T = int>
    vector<T> read_array(const int n)
    {
        vector<T> array(n);
        ranges::generate(array, [] {T x; cin >> x; return x;});
        return array;
    }
