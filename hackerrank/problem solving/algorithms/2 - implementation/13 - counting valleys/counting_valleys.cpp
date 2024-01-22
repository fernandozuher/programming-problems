// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <iostream>

using namespace std;

class CountValleys {
public:
    CountValleys(const string& steps);
    int traversed_valleys() const;

private:
    string steps;
    int n_traversed_valleys;

    void counting_valleys();
        bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude) const;

};

    CountValleys::CountValleys(const string& steps): steps{steps}, n_traversed_valleys{}
    {
        counting_valleys();
    }

    int CountValleys::traversed_valleys() const
    {
        return n_traversed_valleys;
    }

        void CountValleys::counting_valleys()
        {
            int current_altitude {};
            for (const char step : steps) {
                bool was_travessing_a_valley {current_altitude < 0};
                current_altitude += step == 'D' ? -1 : 1;

                if (is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude))
                    ++n_traversed_valleys;
            }
        }

            bool CountValleys::is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude) const
            {
                return was_travessing_a_valley && !current_altitude;
            }

int main()
{
    int n;
    string array;
    cin >> n >> array;
    CountValleys obj{array};
    cout << obj.traversed_valleys();

    return 0;
}
