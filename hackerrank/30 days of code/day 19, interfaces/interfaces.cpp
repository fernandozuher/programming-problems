// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

#include <iostream>

using namespace std;

namespace Advanced_Arithmetic_Exercise {
    bool is_divisible_by(int a, int b)
    {
        return a % b == 0;
    }

    class Advanced_Arithmetic {
    public:
        virtual int divisor_sum(int n) = 0;
        virtual ~Advanced_Arithmetic() = default;
    };

    class Calculator : public Advanced_Arithmetic {
    public:
        int divisor_sum(int n) override
        {
            int sum{};
            for (int i{1}; i <= n / 2; ++i)
                if (is_divisible_by(n, i))
                    sum += i;
            return sum + n;
        }
    };
}

int main()
{
    int n;
    cin >> n;
    Advanced_Arithmetic_Exercise::Calculator calc;
    cout << "I implemented: AdvancedArithmetic\n" << calc.divisor_sum(n);
    return 0;
}
