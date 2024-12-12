// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true
// From C++23 onwards

#include <iostream>
#include <print>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    println("Hello, World.");
    println("{}", input);
    return 0;
}
