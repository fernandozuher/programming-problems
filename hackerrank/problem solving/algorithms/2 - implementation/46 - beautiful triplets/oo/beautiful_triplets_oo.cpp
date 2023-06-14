// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int size);

class Beautiful_Triplets
{
private:
    vector<int> array;
    int beautiful_difference;
    int n_beautiful_triplets;

    void find_beautiful_triplets()
    {
        this->n_beautiful_triplets = 0;
        const int array_size {static_cast<int>(this->array.size())};
        if (array_size > 2)
            for (int i {0}; i < array_size - 2; i++)
                for (int j {i + 1}; j < array_size - 1; j++)
                {
                    const int first_difference {array[j] - array[i]};

                    if (first_difference < this->beautiful_difference)
                        continue;
                    else if (first_difference > this->beautiful_difference)
                        break;

                    for (int k {j + 1}; k < array_size; k++)
                    {
                        const int second_difference {array[k] - array[j]};

                        if (second_difference == this->beautiful_difference)
                            this->n_beautiful_triplets++;
                        else if (second_difference > this->beautiful_difference)
                            break;
                    }
                }
    }

public:
    Beautiful_Triplets(const vector<int> array, const int beautiful_difference)
    {
        this->array = {array};
        this->beautiful_difference = {beautiful_difference};
        find_beautiful_triplets();
    }

    int get_n_beautiful_triplets() const
    {
        return n_beautiful_triplets;
    }
};

int main()
{
    const int size {read_a_number()};
    const int beautiful_difference {read_a_number()};
    const vector<int> array {read_an_array(size)};

    const Beautiful_Triplets obj(array, beautiful_difference);
    cout << obj.get_n_beautiful_triplets() << "\n";

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
