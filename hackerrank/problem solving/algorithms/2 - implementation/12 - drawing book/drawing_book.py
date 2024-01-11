# https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

def main():

    page_quantity = int(input())
    page = int(input())
    obj = DrawingBook(page_quantity, page)
    print(obj.minimum_turn_of_pages())


class DrawingBook:

    def __init__(self, page_quantity, page):

        self._page_quantity = page_quantity
        self._page = page
        self._turn_of_pages_from_front = 0
        self._turn_of_pages_from_back = 0
        self._minimum_turn_of_pages = 0
        self._page_count()


    def _page_count(self):

        self._turn_of_pages_from_front = self._calculate_turn_of_pages(self._page)
        maximum_turns = self._calculate_turn_of_pages(self._page_quantity)
        self._turn_of_pages_from_back = maximum_turns - self._turn_of_pages_from_front
        self._minimum_turn_of_pages = int(min(self._turn_of_pages_from_front, self._turn_of_pages_from_back))


    def _calculate_turn_of_pages(self, page):

        return self._page_is_odd(page) if page & 1 else self._page_is_even(page)


    def _page_is_odd(self, page):

        return (page - 1) / 2


    def _page_is_even(self, page):

        return page / 2


    def minimum_turn_of_pages(self):

        return self._minimum_turn_of_pages


if __name__ == "__main__":
    main()
