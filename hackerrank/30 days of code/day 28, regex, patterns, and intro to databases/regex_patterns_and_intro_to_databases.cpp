// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> find_names_with_gmail_domains_emails_from_stdin(int n);
    bool is_gmail_domain(const string& email_id);
void sort_and_print_names(vector<string>& names);

int main()
{
    int n;
    cin >> n;

    vector<string> names = find_names_with_gmail_domains_emails_from_stdin(n);
    sort_and_print_names(names);

    return 0;
}

    vector<string> find_names_with_gmail_domains_emails_from_stdin(int n)
    {
        vector<string> names;

        while (n--) {
            string name, email_id;
            cin >> name >> email_id;

            if (is_gmail_domain(email_id))
                names.push_back(name);
        }

        return names;
    }

        bool is_gmail_domain(const string& email_id)
        {
            auto index_arroba{email_id.find("@")};
            string email_domain{email_id.substr(index_arroba)};
            return email_domain == "@gmail.com";
        }

    void sort_and_print_names(vector<string>& names)
    {
        ranges::sort(names);
        for (const auto& name : names)
            cout << name << '\n';
    }
