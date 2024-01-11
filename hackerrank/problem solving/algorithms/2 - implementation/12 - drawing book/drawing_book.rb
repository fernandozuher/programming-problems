# https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

def main
    page_quantity = gets.to_i
    page = gets.to_i
    obj = Drawing_book.new(page_quantity, page)
    puts obj.minimum_turn_of_pages
end

    class Drawing_book
        attr_reader :minimum_turn_of_pages

        def initialize(page_quantity, page)
            @page_quantity = page_quantity
            @page = page
            @turn_of_pages_from_front = 0
            @turn_of_pages_from_back = 0
            @minimum_turn_of_pages = 0
            page_count
        end

            private def page_count
                @turn_of_pages_from_front = calculate_turn_of_pages(@page)
                maximum_turns = calculate_turn_of_pages(@page_quantity)
                @turn_of_pages_from_back = maximum_turns - @turn_of_pages_from_front
                @minimum_turn_of_pages = [@turn_of_pages_from_front, @turn_of_pages_from_back].min
            end

                private def calculate_turn_of_pages(page)
                    page.odd? ? page_is_odd(page) : page_is_even(page)
                end

                    private def page_is_odd(page)
                        (page - 1) / 2
                    end

                    private def page_is_even(page)
                        page / 2
                    end
    end

main
