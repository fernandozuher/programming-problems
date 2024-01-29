// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read_array(const int n);

vector<int> remove_duplicates(vector<int> array);
int binary_search_descending_order(const vector<int>& array, const int low, const int high, const int key);

template<class T = int>
void print_array(const vector<T>& array);


class Climbing_The_Leaderboard {
public:
    Climbing_The_Leaderboard(const vector<int>& ranked, const vector<int>& player);
    vector<int> rank() const;

private:
    vector<int> ranked, player;
    vector<int> player_rank;

    void climbing_leaderboard();
};

    Climbing_The_Leaderboard::Climbing_The_Leaderboard(const vector<int>& ranked, const vector<int>& player)
        : ranked{ranked}, player{player}, player_rank{vector<int>(player.size())}
    {
        climbing_leaderboard();
    }

    vector<int> Climbing_The_Leaderboard::rank() const
    {
        return player_rank;
    }

    void Climbing_The_Leaderboard::climbing_leaderboard()
    {
        for (int i = 0, last_index = ranked.size() - 1, n = player.size(); i < n; ++i) {
            int index {binary_search_descending_order(ranked, 0, last_index, player.at(i))};
            player_rank.at(i) = ++index;
        }
    }

/////////////////////////////////////////////////

int main()
{
    int n;

    cin >> n;
    vector<int> ranked {read_array(n)};
    ranked = remove_duplicates(ranked);

    cin >> n;
    vector<int> player {read_array(n)};

    Climbing_The_Leaderboard obj{ranked, player};
    print_array(obj.rank());

    return 0;
}

    template<class T = int>
    vector<T> read_array(const int n)
    {
        vector<T> array(n);
        ranges::generate(array, [] {T x; cin >> x; return x;});
        return array;
    }

    vector<int> remove_duplicates(vector<int> array)
    {
        int new_size{};

        for (int i{}, n = array.size() - 1; i < n; ++i)
            if (array[i] != array[i + 1])
                array[new_size++] = array[i];

        array[new_size++] = array[array.size() - 1];
        array.erase(array.begin() + new_size, array.end());
        return array;
    }

    int binary_search_descending_order(const vector<int>& array, const int low, const int high, const int key)
    {
        if (high >= low) {
            int middle {low + (high - low) / 2};

            if (key == array.at(middle))
                return middle;
            else if (key > array.at(middle))
                return binary_search_descending_order(array, low, middle - 1, key);
            else
                return binary_search_descending_order(array, middle + 1, high, key);
        }
        return low;
    }

    template<class T = int>
    void print_array(const vector<T>& array)
    {
        for (const auto x : array)
            cout << x << '\n';
    }
