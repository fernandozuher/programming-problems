// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string extract_email_domain(const string& email_id);

int main()
{
    int n;
    cin >> n;
    vector<string> first_names;

    while (n--) {
        string name, email_id;
        cin >> name >> email_id;

        string email_domain {extract_email_domain(email_id)};
        if (email_domain == "@gmail.com")
            first_names.push_back(name);
    }

    ranges::sort(first_names);
    for (const auto& name : first_names)
        cout << name << '\n';

    return 0;
}

    string extract_email_domain(const string& email_id)
    {
        auto index_arroba{email_id.find("@")};
        string email_domain{email_id.substr(index_arroba)};
        return email_domain;
    }
