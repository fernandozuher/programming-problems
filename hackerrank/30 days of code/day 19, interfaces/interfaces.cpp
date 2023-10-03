// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

#include <iostream>
using namespace std;

class Advanced_Arithmetic {
public:
    virtual int divisor_sum(const int n) = 0;
};

class Calculator: public Advanced_Arithmetic {
public:
    int divisor_sum(const int n) override
    {
        int sum {};
        for (int i {1}; i <= n / 2; ++i)
            if (!(n % i))
                sum += i;
        return sum + n;
    }
};

int main()
{
    int n;
    cin >> n;

    Calculator calc;
    cout << "I implemented: AdvancedArithmetic\n" << calc.divisor_sum(n);

    return 0;
}
