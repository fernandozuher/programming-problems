// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Person {
protected:
    string first_name, last_name;
    int id;

public:
    Person(const string& first_name, const string& last_name, const int id)
        : first_name{first_name}, last_name{last_name}, id{id}
    {}

    void print_person() const
    {
        cout << "Name: " << last_name << ", " << first_name << "\nID: " << id << '\n';
    }
};

class Student: public Person {
    vector<int> scores;

public:
    Student(const string& first_name, const string& last_name, const int id, const vector<int>& scores)
        : Person{first_name, last_name, id}, scores{scores}
    {}

    char calculate_grade() const
    {
        int sum_scores {accumulate(scores.begin(), scores.end(), 0)};
        size_t n {scores.size()};
        auto avg {sum_scores / n};

        if (avg >= 90 && avg <= 100)
            return 'O';
        else if (avg >= 80 && avg < 90)
            return 'E';
        else if (avg >= 70 && avg < 80)
            return 'A';
        else if (avg >= 55 && avg < 70)
            return 'P';
        else if (avg >= 40 && avg < 55)
            return 'D';
        else
            return 'T';
    }
};

int main()
{
    string first_name, last_name;
    int id, n_scores;
    cin >> first_name >> last_name >> id >> n_scores;

    vector<int> scores(n_scores);
    ranges::generate(scores, [] {int n; cin >> n; return n;});

    Student student {first_name, last_name, id, scores};
    student.print_person();
    cout << "Grade: " << student.calculate_grade() << '\n';

    return 0;
}
