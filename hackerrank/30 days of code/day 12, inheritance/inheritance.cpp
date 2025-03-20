// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true
// From C++23 onward: ranges::fold_left_first

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct personal_data {
    string first_name, last_name;
    int id{};
};

struct student_data {
    vector<int> scores;
};

class Person {
    string first_name, last_name;
    int id;

public:
    explicit Person(const personal_data& data);
    void print_person() const;
};

class Student : public Person {
    vector<int> scores;

public:
    explicit Student(const personal_data& personal_d, const student_data& student_d);
    [[nodiscard]] char calculate_grade() const;
};

Person::Person(const personal_data& data)
    : first_name{data.first_name}, last_name{data.last_name}, id{data.id}
{
}

void Person::print_person() const
{
    cout << "Name: " << last_name << ", " << first_name << '\n';
    cout << "ID: " << id << '\n';
}

Student::Student(const personal_data& personal_d, const student_data& student_d)
    : Person{personal_d}, scores{student_d.scores}
{
}

char Student::calculate_grade() const
{
    if (auto avg{*ranges::fold_left_first(scores, plus{}) / scores.size()}; avg > 100 || avg < 40)
        return 'T';
    else if (avg >= 90)
        return 'O';
    else if (avg >= 80)
        return 'E';
    else if (avg >= 70)
        return 'A';
    else if (avg >= 55)
        return 'P';
    return 'D';
}

//////////////////////////////////////////////////

tuple<personal_data, student_data> read_input();

int main()
{
    auto [personal_d, student_d]{read_input()};
    Student student{personal_d, student_d};
    student.print_person();
    cout << "Grade: " << student.calculate_grade();
    return 0;
}

tuple<personal_data, student_data> read_input()
{
    personal_data personal_d;
    student_data student_d;
    int n_scores;
    cin >> personal_d.first_name >> personal_d.last_name >> personal_d.id >> n_scores;
    student_d.scores.resize(n_scores);
    copy_n(istream_iterator<int>(cin), n_scores, student_d.scores.begin());
    return {personal_d, student_d};
}
