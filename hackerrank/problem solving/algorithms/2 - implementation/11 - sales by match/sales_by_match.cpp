// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Result {

private:
    vector<int> _socks;
    int _pairs;

    void _sock_merchant() {
        map<int, bool> socks_pairing;

        for (int sock : _socks) {
            if (socks_pairing[sock])
                _pairs++;
            socks_pairing[sock] = !socks_pairing[sock];
        }
    }

public:
    Result(const vector<int> socks): _socks{socks} {
        _pairs = 0;

        _sock_merchant();
        print_result();
    }

        void print_result() const {
            cout << _pairs;
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
    read_line_as_vector_int();
    vector<int> socks {read_line_as_vector_int()};

    Result result(socks);

    return 0;
}
