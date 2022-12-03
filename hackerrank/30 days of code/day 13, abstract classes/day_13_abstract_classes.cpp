#include <iostream>
#include <string>
using namespace std;

class Book
{
    protected:
        string title;
        string author;

    public:
        Book(string t, string a) {
            title = t;
            author = a;
        }

        virtual void display() = 0;
};

class MyBook : Book
{
    private:
        double price;

    public:
        MyBook(string title, string author, double price): Book(title, author), price{price} {}

        void display() override {
            cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nPrice: " << this->price;
        }        
};

int main() {
    
    string title,author;
    int price;
    
    getline(cin, title);
    getline(cin, author);
    
    cin >> price;
    MyBook novel(title, author, price);
    novel.display();
    
    return 0;
}
