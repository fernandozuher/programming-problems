// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

#include <iostream>

using namespace std;

int main()
{
    string input_string;
    getline(cin, input_string);
    cout << "Hello, World." << '\n';
    cout << input_string << '\n';

    return 0;
}
