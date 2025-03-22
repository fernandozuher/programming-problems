// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Book {
protected:
    string title, author;

public:
    Book(const string_view& title, const string_view& author): title{title}, author{author} {}
    virtual void display() = 0;
    virtual ~Book() = default;
};

class My_Book final : public Book {
    double price;

public:
    My_Book(const string_view& title, const string_view& author, double price): Book{title, author}, price{price} {}
    void display() override
    {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: " << price;
    }
};

int main()
{
    string title, author;
    double price;

    getline(cin, title);
    getline(cin, author);
    cin >> price;

    My_Book novel{title, author, price};
    novel.display();

    return 0;
}
