#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plus_minus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plus_minus(vector<int> arr) {
    int positive_quantity {}, negative_quantity {}, zero_quantity {};

    for (auto& number : arr)
        if (number > 0)
            positive_quantity++;
        else if (number < 0)
            negative_quantity++;
        else
            zero_quantity++;

    int n {static_cast<int>(arr.size())};
    float positive_values_proportion {(float) positive_quantity / n};
    float negative_values_proportion {(float) negative_quantity / n};
    float zero_values_proportion {(float) zero_quantity / n};

    cout << setprecision(6) << fixed
         << positive_values_proportion << "\n"
         << negative_values_proportion << "\n"
         << zero_values_proportion;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plus_minus(arr);

    return 0;
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
