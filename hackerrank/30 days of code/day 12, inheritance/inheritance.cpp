// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name, const int id)
        : first_name{first_name}, last_name{last_name}, id{id}
    {}

    void print_person() const
    {
        cout << "Name: " << last_name << ", " << first_name << "\nID: " << id << '\n';
    }

protected:
    string first_name, last_name;
    int id;
};

class Student: public Person {
public:
    Student(const string& first_name, const string& last_name, const int id, const vector<int>& scores)
        : Person{first_name, last_name, id}, scores{scores}
    {}

    char calculate_grade() const
    {
        const int sum_scores {accumulate(scores.begin(), scores.end(), 0)};
        const int n {static_cast<int>(scores.size())};
        const int avg {sum_scores / n};

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

private:
    vector<int> scores;
};

int main()
{
    string first_name, last_name;
    int id, n_scores;
    cin >> first_name >> last_name >> id >> n_scores;

    vector<int> scores;
    for (int score; n_scores-- && cin >> score; scores.push_back(score));

    const Student student {first_name, last_name, id, scores};
    student.print_person();
    cout << "Grade: " << student.calculate_grade() << '\n';

    return 0;
}
