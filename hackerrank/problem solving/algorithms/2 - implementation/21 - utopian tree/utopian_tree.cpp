// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Utopian_Tree {
public:
    Utopian_Tree(const vector<int>& test_cases);
    vector<int> trees_heights() const;

private:
    vector<int> test_cases;
    vector<int> heights;

    void calculate_tree_heights();
    int calculate_height(const int cycles) const;
    bool is_cycle_happening_during_spring(const int cycle) const;
};

    Utopian_Tree::Utopian_Tree(const vector<int>& test_cases):
        test_cases{test_cases}, heights{vector<int>(test_cases.size())}
    {
        calculate_tree_heights();
    }

        void Utopian_Tree::calculate_tree_heights()
        {
            int i{};
            auto lambda = [&i, this]() {return calculate_height(test_cases.at(i++));};
            ranges::generate(heights, lambda);
        }

            int Utopian_Tree::calculate_height(const int cycles) const
            {
                int height {1};
                for (int cycle {1}; cycle <= cycles; ++cycle)
                    height = is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
                return height;
            }

                bool Utopian_Tree::is_cycle_happening_during_spring(const int cycle) const
                {
                    return cycle & 1;
                }

    vector<int> Utopian_Tree::trees_heights() const
    {
        return heights;
    }

//////////////////////////////////////////////////

template<class T = int, class container = vector<T>>
vector<int> read_lines(const int n);

template<class T = int, class container = vector<T>>
void print_array(const container& array);

int main() {
    int n;
    cin >> n;
    vector<int> test_cases {read_lines(n)};
    Utopian_Tree obj{test_cases};
    print_array(obj.trees_heights());

    return 0;
}

    template<class T, class container>
    vector<int> read_lines(const int n)
    {
        container array(n);
        ranges::generate(array, [] {T x; cin >> x; return x;});
        return array;
    }

    template<class T, class container>
    void print_array(const container& array)
    {
        for (const T x : array)
            cout << x << '\n';
    }
