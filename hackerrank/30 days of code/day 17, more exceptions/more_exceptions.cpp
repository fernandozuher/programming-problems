// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

#include <iostream>
#include <cmath>

using namespace std;

void power(int n, int p);

class Calculator {
public:
    static int power(int n, int p)
    {
        if (n < 0 || p < 0)
            throw invalid_argument("n and p should be non-negative");
        return pow(n, p);
    }
};

int main()
{
    int n_tests;
    cin >> n_tests;
    for (int n, p; n_tests-- && cin >> n >> p;)
        power(n, p);
    return 0;
}

void power(int n, int p)
{
    try {
        cout << Calculator::power(n, p) << '\n';
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
