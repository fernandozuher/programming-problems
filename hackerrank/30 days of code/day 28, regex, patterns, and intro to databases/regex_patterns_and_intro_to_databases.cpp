// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<string> collect_emails_names_while_read_stdin(int n);
optional<string> collect_name_if_has_gmail_domain();

int main()
{
    int n;
    cin >> n;
    vector names{collect_emails_names_while_read_stdin(n)};
    ranges::sort(names);
    ranges::copy(names, ostream_iterator<string>(cout, "\n"));
    return 0;
}

vector<string> collect_emails_names_while_read_stdin(int n)
{
    vector<string> names;
    while (n--)
        if (auto name{collect_name_if_has_gmail_domain()}; name)
            names.emplace_back(name.value());
    return names;
}

optional<string> collect_name_if_has_gmail_domain()
{
    string name, email;
    cin >> name >> email;
    return email.ends_with("@gmail.com"s) ? make_optional(name) : nullopt;
}
