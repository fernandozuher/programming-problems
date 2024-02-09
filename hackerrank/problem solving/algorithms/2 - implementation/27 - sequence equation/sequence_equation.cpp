// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Sequence_Equation {

public:
    Sequence_Equation(const vector<int>& array);
    vector<int> permutated_array() const;

private:
    vector<int> array;
    vector<int> elements_positions_array;
    vector<int> permut_array;

    void generate_elements_positions_array();
    void generate_permutated_array();
};

    Sequence_Equation::Sequence_Equation(const vector<int>& array)
        : array{array}, elements_positions_array{vector<int>(array.size())},
          permut_array{vector<int>(array.size())}
    {
        generate_elements_positions_array();
        generate_permutated_array();
    }

        void Sequence_Equation::generate_elements_positions_array()
        {
            for (int i{}; const auto x : array)
                elements_positions_array.at(x - 1) = i++;
        }

        void Sequence_Equation::generate_permutated_array()
        {
            for (int i{}; const auto x : elements_positions_array)
                permut_array.at(i++) = elements_positions_array[x] + 1;
        }

    vector<int> Sequence_Equation::permutated_array() const
    {
        return permut_array;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<T> read(const int n);

template<class T = int>
void print_array(const vector<T>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array {read(n)};

    Sequence_Equation obj{array};
    print_array(obj.permutated_array());

    return 0;
}

    template<class T = int>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        auto read = []{T x; cin >> x; return x;};
        ranges::generate(array, read);
        return array;
    }

    template<class T = int>
    void print_array(const vector<T>& array)
    {
        auto println = [](auto x) {cout << x << '\n';};
        ranges::for_each(array, println);
    }
