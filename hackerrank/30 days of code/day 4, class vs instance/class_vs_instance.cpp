// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Person {
private:
    int age;

public:
    explicit Person(const int initial_age);
    void am_i_old() const;
    void year_passes();
};

Person::Person(const int initial_age)
{
    if (initial_age < 0) {
        age = 0;
        cout << "Age is not valid, setting age to 0.\n";
    }
    else
        age = initial_age;
}

void Person::am_i_old() const
{
    if (age < 13)
        cout << "You are young.\n";
    else if (age >= 13 && age < 18)
        cout << "You are a teenager.\n";
    else
        cout << "You are old.\n";
}

void Person::year_passes()
{
    ++age;
}

int main()
{
    int n_tests;
    cin >> n_tests;

    for (int age; cin >> age && n_tests-- > 0;) {
        Person p {age};
        p.am_i_old();

        for (int i {3}; i--; p.year_passes());
        p.am_i_old();

        cout << '\n';
    }

    return 0;
}
