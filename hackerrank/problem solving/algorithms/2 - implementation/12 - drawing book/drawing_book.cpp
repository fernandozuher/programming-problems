// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Drawing_Book {
public:
    Drawing_Book(int page_quantity, int page);
    [[nodiscard]] int page_count();
    [[nodiscard]] int minimum_turn_of_pages() const;

private:
    int page_quantity, page;
    int turn_of_pages_from_front{}, turn_of_pages_from_back{};
    int min_turn_of_pages{};

    [[nodiscard]] static int calculate_turn_of_pages(int page);
    [[nodiscard]] static int page_is_odd(int page);
    [[nodiscard]] static int page_is_even(int page);
};

Drawing_Book::Drawing_Book(const int page_quantity, const int page):
    page_quantity{page_quantity}, page{page} {}

int Drawing_Book::page_count()
{
    turn_of_pages_from_front = calculate_turn_of_pages(page);
    int maximum_turns{calculate_turn_of_pages(page_quantity)};
    turn_of_pages_from_back = maximum_turns - turn_of_pages_from_front;
    min_turn_of_pages = min(turn_of_pages_from_front, turn_of_pages_from_back);
    return minimum_turn_of_pages();
}

int Drawing_Book::calculate_turn_of_pages(const int page)
{
    return page & 1 ? page_is_odd(page) : page_is_even(page);
}

int Drawing_Book::page_is_odd(const int page)
{
    return (page - 1) / 2;
}

int Drawing_Book::page_is_even(const int page)
{
    return page / 2;
}

int Drawing_Book::minimum_turn_of_pages() const
{
    return min_turn_of_pages;
}

//////////////////////////////////////////////////

int main()
{
    int page_quantity, page;
    cin >> page_quantity >> page;
    cout << Drawing_Book{page_quantity, page}.page_count();
    return 0;
}
