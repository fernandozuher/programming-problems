// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    try {
        cout << stoi(s);
    }
    catch (invalid_argument&) {
        cout << "Bad String";
    }

    return 0;
}
