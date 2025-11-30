// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true
// C++26

import std;
using namespace std;

vector<int> factorial(int n);
void multiply_array_with_number(vector<int>& arr, int number);
void add_carry_to(int carry, vector<int>& arr);
void print_factorial(const vector<int>& arr);

int main()
{
    int number;
    cin >> number;
    print_factorial(factorial(number));
    return 0;
}

vector<int> factorial(int n)
{
    vector<int> factorial{ 1 };
    for (int i{ 2 }; i <= n; ++i)
        multiply_array_with_number(factorial, i);
    return factorial;
}

void multiply_array_with_number(vector<int>& arr, int number)
{
    int carry{};

    for (auto& last_digit : arr) {
        int product{ last_digit * number + carry };
        last_digit = product % 10;
        carry = product / 10;
    }

    add_carry_to(carry, arr);
}

void add_carry_to(int carry, vector<int>& arr)
{
    for (; carry; carry /= 10)
        arr.push_back(carry % 10);
}

void print_factorial(const vector<int>& arr)
{
    for (auto x : views::reverse(arr))
        cout << x;
    println();
}
