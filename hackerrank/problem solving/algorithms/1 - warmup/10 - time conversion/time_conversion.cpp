#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'time_conversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string time_conversion(string time) {
    string converted_time {time.substr(0, 8)};
    string hour_string {time.substr(0, 2)};
    string period_of_day {time.substr(8, 1)};

    if (hour_string == "12") {
        if (period_of_day == "A")
            converted_time.replace(0, 2, "00");
    }
    else if (period_of_day == "P") {
        int hour {stoi(hour_string)};
        hour += 12;
        converted_time.replace(0, 2, to_string(hour));
    }
    return converted_time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = time_conversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
