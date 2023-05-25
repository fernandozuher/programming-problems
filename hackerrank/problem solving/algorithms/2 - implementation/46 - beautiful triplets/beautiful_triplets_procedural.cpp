// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int size);
int find_beautiful_triplets(const vector<int> array, const int beautiful_difference);

int main()
{
    const int size {read_a_number()};
    const int beautiful_difference {read_a_number()};
    const vector<int> array {read_an_array(size)};

    const int n_beautiful_triplets {find_beautiful_triplets(array, beautiful_difference)};
    cout << n_beautiful_triplets << "\n";

    return 0;
}

    int read_a_number()
    {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int size)
    {
        vector<int> array(size);
        ranges::generate(array, read_a_number);
        return array;
    }

    int find_beautiful_triplets(const vector<int> array, const int beautiful_difference)
    {
        int n_beautiful_triplets {0};

        const int array_size {static_cast<int>(array.size())};
        if (array_size > 2)
            for (int i {0}; i < array_size - 2; i++)
                for (int j {i + 1}; j < array_size - 1; j++)
                {
                    const int first_difference {array[j] - array[i]};

                    if (first_difference < beautiful_difference)
                        continue;
                    else if (first_difference > beautiful_difference)
                        break;

                    for (int k {j + 1}; k < array_size; k++)
                    {
                        const int second_difference {array[k] - array[j]};

                        if (second_difference == beautiful_difference)
                            n_beautiful_triplets++;
                        else if (second_difference > beautiful_difference)
                            break;
                    }
                }

        return n_beautiful_triplets;
    }
