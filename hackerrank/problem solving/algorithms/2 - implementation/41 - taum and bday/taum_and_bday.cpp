// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true
// C++23

import std;
using namespace std;

using gifts = struct gifts {
    long n_black_gifts{};
    long n_white_gifts{};
    long black_gift_cost{};
    long white_gift_cost{};
    long cost_to_convert_between_gifts{};
};

gifts read_test_case();
long min_cost_of_buying_gifts(const gifts& x);

int main()
{
    int n;
    cin >> n;
    for (int i{}; i < n; ++i)
        println("{}", min_cost_of_buying_gifts(read_test_case()));
    return 0;
}

gifts read_test_case()
{
    gifts x;
    cin >> x.n_black_gifts >> x.n_white_gifts
        >> x.black_gift_cost >> x.white_gift_cost
        >> x.cost_to_convert_between_gifts;
    return x;
}

long min_cost_of_buying_gifts(const gifts& x)
{
    long black_cost{ min(x.black_gift_cost, x.white_gift_cost + x.cost_to_convert_between_gifts) };
    long white_cost{ min(x.white_gift_cost, x.black_gift_cost + x.cost_to_convert_between_gifts) };
    return x.n_black_gifts * black_cost + x.n_white_gifts * white_cost;
}

