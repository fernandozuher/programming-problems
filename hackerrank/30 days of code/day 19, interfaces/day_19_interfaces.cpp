#include <iostream>
using namespace std;

class AdvancedArithmetic
{
public:
    virtual int divisorSum(int n) = 0;
};

class Calculator : AdvancedArithmetic
{
public:
    int divisorSum(int n) override
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
    cout << "I implemented: AdvancedArithmetic\n" << calc.divisorSum(n);

    return 0;
}
