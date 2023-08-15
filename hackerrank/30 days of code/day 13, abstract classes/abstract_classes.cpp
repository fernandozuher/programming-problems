// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Book {
protected:
    string title, author;

public:
    Book(const string& title, const string& author): title{title}, author{author} {}
    virtual void display() = 0;
};

class My_Book: Book {
private:
    double price;

public:
    My_Book(const string& title, const string& author, double price): Book{title, author}, price{price} {}

    void display() override
    {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: " << price;
    }
};

int main()
{
    string title, author;
    int price;

    getline(cin, title);
    getline(cin, author);
    cin >> price;

    My_Book novel {title, author, price};
    novel.display();

    return 0;
}
