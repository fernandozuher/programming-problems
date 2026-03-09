# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main
  letters_heights = read_numbers
  word = gets
  puts designer_pdf_viewer(letters_heights, word)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length word, <= 10
# T: O(10) = O(1)
# S: O(1) extra space
def designer_pdf_viewer(letters_heights, word)
  max_height = word.each_char.lazy.map { |ch| letters_heights[ch.ord - 'a'.ord] }.max
  max_height * word.length
end

main if __FILE__ == $0
