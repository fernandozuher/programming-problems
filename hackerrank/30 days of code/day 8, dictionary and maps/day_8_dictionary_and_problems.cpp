#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, string> phone_book;
    for (string name, phone; n--; phone_book.insert({name, phone}))
        cin >> name >> phone;
    
    for (string name; (cin >> name); )
        if (phone_book.find(name) != phone_book.end())
            cout << name << '=' << phone_book.at(name) << '\n';
        else
            cout << "Not found\n";
    
    return 0;
}
