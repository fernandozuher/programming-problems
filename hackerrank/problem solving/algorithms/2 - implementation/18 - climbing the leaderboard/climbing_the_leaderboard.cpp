// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

// The test cases 6, 7, 8 and 9 has runtime limit exceeded when vector<int> is used as a data structure.
// That's why simple arrays int[] are used herein.

class Result {

private:
    shared_ptr<int[]> _ranked;
    int _n_ranked;
    shared_ptr<int[]> _player;
    int _n_player;
    unique_ptr<int[]> _player_rank;

    void _remove_duplicates_from_ranked_array() {
        int n_temp {0};

        for (int i {0}; i < _n_ranked - 1; i++)
            if (_ranked[i] != _ranked[i + 1])
                _ranked[n_temp++] = _ranked[i];

        _ranked[n_temp++] = _ranked[_n_ranked - 1];

        _n_ranked = n_temp;
    }

    void _climbing_leaderboard() {
        for (int i {0}; i < _n_player; i++) {
            int index {_binary_search_descending_order(0, _n_ranked, _player[i])};
            index = index <= _n_ranked - 1 ? index + 1 : index;
            _player_rank[i] = index;
        }
    }

        int _binary_search_descending_order(const int low, const int high, const int key) const {
            if (high >= low) {
                int middle {(low + high) / 2};

                if (key == _ranked[middle])
                    return middle;
                else if (key > _ranked[middle])
                    return _binary_search_descending_order(low, (middle - 1), key);
                else if (key < _ranked[middle])
                    return _binary_search_descending_order((middle + 1), high, key);
            }
            return low;
        }

public:
    Result(shared_ptr<int[]> ranked, const int n_ranked, shared_ptr<int[]> player, const int n_player) {
        _ranked = ranked;
        _n_ranked = n_ranked;
        _player = player;
        _n_player = n_player;

        _player_rank = std::make_unique<int[]>(n_player);

        _remove_duplicates_from_ranked_array();

        _climbing_leaderboard();
        print_result();
    }

    void print_result() const {
        for (int i {0}; i < _n_player; i++)
            cout << _player_rank[i] << "\n";
    }
};

shared_ptr<int[]> read_line_as_array_int(const int n) {
    auto input_line = std::make_unique<int[]>(n);
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int i {0}; ss >> input_line[i]; i++);
    return input_line;
}

int main() {
    shared_ptr<int[]> input_line {read_line_as_array_int(1)};
    int n1 {input_line[0]};
    shared_ptr<int[]> ranked {read_line_as_array_int(n1)};

    input_line = read_line_as_array_int(1);
    int n2 {input_line[0]};
    shared_ptr<int[]> player {read_line_as_array_int(n2)};

    Result result(ranked, n1, player, n2);

    return 0;
}
