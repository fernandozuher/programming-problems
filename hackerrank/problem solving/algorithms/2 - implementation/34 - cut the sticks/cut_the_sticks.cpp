// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Cut_The_Sticks {
public:
    explicit Cut_The_Sticks(const vector<int>& array);
    vector<int> remaining_sticks_array() const;

private:
    vector<int> sticks_length_array;
    vector<int> remaining_sticks_length_array;

    void cut_the_sticks();
        int find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const int n) const;
        void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, const int shortest_stick_length);
};

    Cut_The_Sticks::Cut_The_Sticks(const vector<int>& array):
        sticks_length_array{array}, remaining_sticks_length_array{vector<int>{array.size()}}
    {
        cut_the_sticks();
    }

        void Cut_The_Sticks::cut_the_sticks()
        {
            for (int i{}, n = sticks_length_array.size(); i < n;) {
                int shortest_stick_length {sticks_length_array.at(i)};
                i = find_first_element_index_different_of_first_current_shortest_stick_length_index(i, n);

                int current_iteration_size {n - i};
                if (i == n)
                    break;

                remaining_sticks_length_array.push_back(current_iteration_size);
                decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, shortest_stick_length);
            }
        }

            int Cut_The_Sticks::find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const int n) const
            {
                int shortest_stick_length {sticks_length_array.at(index)};
                while (index < n && sticks_length_array.at(index) == shortest_stick_length)
                    ++index;
                return index;
            }

            void Cut_The_Sticks::decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, const int shortest_stick_length)
            {
                auto lambda = [shortest_stick_length](auto& x) {x -= shortest_stick_length;};
                for_each(sticks_length_array.begin() + index, sticks_length_array.end(), lambda);
            }

    vector<int> Cut_The_Sticks::remaining_sticks_array() const
    {
        return remaining_sticks_length_array;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<T> read_array(const int n);

template <class T = int>
void print_array(const vector<T>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_array(n)};
    ranges::sort(array);

    Cut_The_Sticks obj{array};
    print_array(obj.remaining_sticks_array());

    return 0;
}

    template<class T = int>
    vector<T> read_array(const int n) {
        vector<T> array(n);
        ranges::generate(array, [] {T x; cin >> x; return x;});
        return array;
    }

    template <class T = int>
    void print_array(const vector<T>& array) {
        for (auto element : array)
            cout << element << "\n";
    }
