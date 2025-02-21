// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true
// From C++23 onwards: ranges::to

#include <iostream>
#include <map>
#include <ranges>

using namespace std;

map<string, string> init_phone_book(int n);
void query_names(const map<string, string>& phone_book);

int main()
{
    int n;
    cin >> n;
    auto phone_book{init_phone_book(n)};
    query_names(phone_book);
    return 0;
}

map<string, string> init_phone_book(const int n)
{
    const auto read_contact{[](auto) {string a, b; cin >> a >> b; return pair{a, b};}};
    return views::iota(0, n) | views::transform(read_contact) | ranges::to<map<string, string>>();
}

void query_names(const map<string, string>& phone_book)
{
    for (string name; cin >> name;)
        if (phone_book.contains(name))
            cout << name << '=' << phone_book.at(name) << '\n';
        else
            cout << "Not found\n";
}
