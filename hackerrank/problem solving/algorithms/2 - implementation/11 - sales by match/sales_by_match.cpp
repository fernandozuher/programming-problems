// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

vector<int> read_int_array(int n);
int sock_merchant(const vector<int>& socks);

int main()
{
    int n;
    cin >> n;
    vector array{read_int_array(n)};
    cout << sock_merchant(array);

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }

    int sock_merchant(const vector<int>& socks)
    {
        int pairs{};
        for (map<int, bool> socks_pairing; const int sock : socks) {
            if (socks_pairing[sock])
                ++pairs;
            socks_pairing[sock] = !socks_pairing[sock];
        }
        return pairs;
    }
