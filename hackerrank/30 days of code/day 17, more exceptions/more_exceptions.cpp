// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
public:
    int power(int n, int p) const {
        if (n < 0 || p < 0)
            throw invalid_argument("n and p should be non-negative");
        return pow(n, p);
    }
};

int main()
{
    Calculator calc;
    int n_tests;
    cin >> n_tests;

    for (int n, p; n_tests-- && cin >> n >> p;)
        try {
            cout << calc.power(n, p) << '\n';
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }

    return 0;
}
