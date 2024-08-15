// From C++23

#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

int exponent(int n);
string binary_to_string(double n);

int main()
{
    println("From 0.000'000 up to 0.10'000'000 (inclusive) step 0.1...");
    println("All can't be represented from double (64 bits) to single-precision (32 bits) floating-point, but:");
    vector<tuple<int, double, string>> binary;

    for (const int n : views::iota(0, 10'000'000)) {
        const auto exp{exponent(n)};
        const double fractional{1 / pow(10.0, exp)};
        const double double_precision{n * fractional};
        if (const auto str{binary_to_string(double_precision)}; str != "ERROR.")
            binary.emplace_back(n, double_precision, str);
    }

    for (const auto& [n, double_precision, str] : binary)
        cout << fixed << setprecision(exponent(n)) << double_precision << " = " << str << "\n";
}

int exponent(const int n)
{
    if (n < 10)
        return 1;
    if (n < 100)
        return 2;
    if (n < 1000)
        return 3;
    if (n < 10000)
        return 4;
    if (n < 100000)
        return 5;
    if (n < 1000000)
        return 6;
    if (n < 10000000)
        return 7;
    return 8;
}

union float_union {
    float f;
    uint32_t u;
};

string binary_to_string(const double n)
{
    if (const float single_precision{static_cast<float>(n)}; single_precision == n) {
        float_union fu{single_precision};
        static constexpr int precision{32};
        bitset<precision> bits(fu.u);
        return bits.to_string();
    }
    return "ERROR."s;
}
