// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Result {

private:
    int _page_quantity, _page;
    int _turn_of_pages_from_front, _turn_of_pages_from_back;
    int _minimum_turn_of_pages;

    void _drawing_book() {
        _turn_of_pages_from_front = _calculate_turn_of_pages(_page);
        
        int maximum_turns {_calculate_turn_of_pages(_page_quantity)};

        _turn_of_pages_from_back = maximum_turns - _turn_of_pages_from_front;

        _minimum_turn_of_pages = min(_turn_of_pages_from_front, _turn_of_pages_from_back);
    }

        int _calculate_turn_of_pages(const int page) const {
            return page & 1 ? _page_is_odd(page) : _page_is_even(page);
        }

            int _page_is_odd(const int page) const {
                return (page - 1) / 2;
            }

            int _page_is_even(const int page) const {
                return page / 2;
            }

public:
    Result(const int page_quantity, const int page): _page_quantity{page_quantity}, _page{page} {
        _turn_of_pages_from_front = 0;
        _turn_of_pages_from_back = 0;
        _minimum_turn_of_pages = 0;

        _drawing_book();
        print_result();
    }

        void print_result() const {
            cout << _minimum_turn_of_pages;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> numbers;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; numbers.push_back(number));
    return numbers;
}

int main() {
    vector<int> page_quantity {read_line_as_vector_int()};
    vector<int> page {read_line_as_vector_int()};

    Result result(page_quantity.front(), page.front());

    return 0;
}
