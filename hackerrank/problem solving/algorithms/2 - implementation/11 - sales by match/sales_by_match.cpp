// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> read_int_array(const int n);

class Sales_By_Match {
public:
    Sales_By_Match(const vector<int>& socks): socks{socks}, n_pairs{}
    {
        sock_merchant();
    }

    int pairs() const
    {
        return n_pairs;
    }

private:
    vector<int> socks;
    int n_pairs;

    void sock_merchant()
    {
        map<int, bool> socks_pairing;

        for (const int sock : socks) {
            if (socks_pairing[sock])
                ++n_pairs;
            socks_pairing[sock] = !socks_pairing[sock];
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> array {read_int_array(n)};

    Sales_By_Match obj{array};
    cout << obj.pairs();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        generate(array.begin(), array.end(), [] {int x; cin >> x; return x;});
        return array;
    }
