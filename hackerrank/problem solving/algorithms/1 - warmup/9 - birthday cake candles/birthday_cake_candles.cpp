// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <iostream>

using namespace std;

int birthday_cake_candles(int n);

int main()
{
    int n;
    cin >> n;
    cout << birthday_cake_candles(n);
    return 0;
}

    int birthday_cake_candles(const int n)
    {
        int max_count{};

        for (int i{}, max_element{}, x; i < n && cin >> x; ++i)
            if (x > max_element) {
                max_element = x;
                max_count = 1;
            }
            else if (x == max_element)
                ++max_count;

        return max_count;
    }
