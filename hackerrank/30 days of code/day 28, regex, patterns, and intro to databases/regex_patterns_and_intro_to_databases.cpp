// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> find_names_with_gmail_domains_emails_from_stdin(int n);
    bool is_gmail_domain(const string& email_id);
void sort_in_place_and_print_names(vector<string>& names);

int main()
{
    int n;
    cin >> n;

    vector<string> names {find_names_with_gmail_domains_emails_from_stdin(n)};
    sort_in_place_and_print_names(names);

    return 0;
}

    vector<string> find_names_with_gmail_domains_emails_from_stdin(int n)
    {
        vector<string> names;

        while (n--) {
            string name, email_id;
            cin >> name >> email_id;
            if (email_id.find("@gmail.com") != std::string::npos)
                names.push_back(name);
        }

        return names;
    }

    void sort_in_place_and_print_names(vector<string>& names)
    {
        ranges::sort(names);
        for (const auto& name : names)
            cout << name << '\n';
    }
