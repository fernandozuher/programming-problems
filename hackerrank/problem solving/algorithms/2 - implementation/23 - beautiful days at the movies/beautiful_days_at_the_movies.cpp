// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Beautiful_Days {
public:
    Beautiful_Days(const int starting_day_number, const int ending_day_number, const int divisor);
    int n_beautiful_days() const;

private:
    int starting_day_number;
    int ending_day_number;
    int divisor;
    int beautiful_days_quantity;

    void calculate_beautiful_days_quantity();
        int generate_reverse_number(int number) const;
        bool is_day_beautiful(const int number, const int reverse_number) const;
};

    Beautiful_Days::Beautiful_Days(const int starting_day_number, const int ending_day_number, const int divisor)
        : starting_day_number{starting_day_number}, ending_day_number{ending_day_number},
          divisor{divisor}, beautiful_days_quantity{}
    {
        calculate_beautiful_days_quantity();
    }

        void Beautiful_Days::calculate_beautiful_days_quantity()
        {
            for (int number{starting_day_number}; number <= ending_day_number; ++number) {
                int reverse_number {generate_reverse_number(number)};
                if (is_day_beautiful(number, reverse_number))
                    ++beautiful_days_quantity;
            }
        }

            int Beautiful_Days::generate_reverse_number(int number) const
            {
                int reverse_number = 0;
                for (; number > 0; number /= 10)
                    reverse_number = (reverse_number * 10) + (number % 10);
                return reverse_number;
            }

            bool Beautiful_Days::is_day_beautiful(const int number, const int reverse_number) const
            {
                return abs(number - reverse_number) % divisor == 0;
            }

    int Beautiful_Days::n_beautiful_days() const
    {
        return beautiful_days_quantity;
    }

//////////////////////////////////////////////////

int main()
{
    int starting_day_number, ending_day_number, divisor;
    cin >> starting_day_number >> ending_day_number >> divisor;
    Beautiful_Days obj{starting_day_number, ending_day_number, divisor};
    cout << obj.n_beautiful_days();

    return 0;
}
