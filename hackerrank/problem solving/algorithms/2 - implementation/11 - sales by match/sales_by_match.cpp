// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read(int n);
int sock_merchant(const vector<int>& socks);

int main()
{
    int n;
    cin >> n;
    cout << sock_merchant(read(n));
    return 0;
}

template<class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

int sock_merchant(const vector<int>& socks)
{
    int pairs{};
    for (unordered_map<int, bool> socks_pairing; const int sock : socks) {
        if (socks_pairing[sock])
            ++pairs;
        socks_pairing[sock] = !socks_pairing[sock];
    }
    return pairs;
}
