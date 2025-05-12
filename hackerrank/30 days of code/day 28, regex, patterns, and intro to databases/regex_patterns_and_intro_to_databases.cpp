// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<string> collect_gmail_users(int n);

int main()
{
    int n;
    cin >> n;
    vector names{collect_gmail_users(n)};
    ranges::sort(names);
    ranges::copy(names, ostream_iterator<string>(cout, "\n"));
    return 0;
}

vector<string> collect_gmail_users(int n)
{
    vector<string> names;

    while (n--) {
        string name, email;
        cin >> name >> email;
        if (email.ends_with("@gmail.com"s))
            names.push_back(name);
    }

    return names;
}
