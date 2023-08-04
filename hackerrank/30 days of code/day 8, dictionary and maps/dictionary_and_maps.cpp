// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, string> phone_book;
    for (string name, phone; n > 0; n--) {
        cin >> name >> phone;
        phone_book.insert({name, phone});
    }

    for (string name; cin >> name;)
        if (phone_book.contains(name))
            cout << name << '=' << phone_book.at(name) << '\n';
        else
            cout << "Not found\n";

    return 0;
}
