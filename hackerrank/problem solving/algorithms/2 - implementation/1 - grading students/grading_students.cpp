#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'grading_students' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

bool is_zero_remainder(int grade) {
    return grade % 5 == 0;
}

vector<int> grading_students(vector<int> grades) {

    const int N {static_cast<int>(grades.size())};
    vector<int> new_grades(N);

    for (int i {0}, min_grade {38}; i < N; i++) {

        if (grades.at(i) < min_grade || is_zero_remainder(grades.at(i)))
            new_grades.at(i) = grades.at(i);
        else {
            int quocient {grades.at(i) / 5};
            int next_multiple_5 {(quocient + 1) * 5};
            int difference {next_multiple_5 - grades.at(i)};

            int result {difference < 3 ? next_multiple_5 : grades.at(i)};
            new_grades.at(i) = result;
        }
    }
    return new_grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = grading_students(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
