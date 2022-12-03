#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string extract_email_domain(string email);
void check_and_insert_name_if_email_domain_gmail(string first_name, string email_domain, vector<string> &first_names);
void sort_names_of_gmail_emails(vector<string> &first_names);
void print_first_gmail_names(vector<string> &first_names);

int main() {
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    vector<string> first_names;

    for (int N_itr = 0; N_itr < N; N_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
        string firstName{first_multiple_input[0]};
        string emailID{first_multiple_input[1]};

        string email_domain = extract_email_domain(emailID);
        check_and_insert_name_if_email_domain_gmail(firstName, email_domain, first_names);
    }

    sort_names_of_gmail_emails(first_names);
    print_first_gmail_names(first_names);

    return 0;
}

string extract_email_domain(string emailID) {
    int index_arroba{emailID.find("@")};
    string email_domain{emailID.substr(index_arroba)};
    return email_domain;
}

void check_and_insert_name_if_email_domain_gmail(string first_name, string email_domain, vector<string> &first_names) {
    if (email_domain == "@gmail.com")
        first_names.push_back(first_name);
}

void sort_names_of_gmail_emails(vector<string> &first_names) {
    sort(first_names.begin(), first_names.end());
}

void print_first_gmail_names(vector<string> &first_names) {
    for (auto& first_name : first_names)
        cout << first_name << '\n';
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
