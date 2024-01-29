# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main
    letters_heights = read_int_array
    word = gets
    obj = DesignerPdfViewer.new(letters_heights, word)
    puts obj.area
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class DesignerPdfViewer
        attr_reader :area

        def initialize(letters_heights, word)
            @letters_heights = letters_heights
            @word = word
            @area = 0
            calculate_area
        end

            private def calculate_area
                max_height = 0

                @word.chars.each do |letter|
                    letter_index = letter.ord - 'a'.ord
                    letter_height = @letters_heights[letter_index]
                    max_height = [max_height, letter_height].max
                end

                @area = max_height * @word.size
            end
    end

main
