# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main
  letters_heights = read_numbers
  word = gets
  puts designer_pdf_viewer(letters_heights, word)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n_w: length of string word, no more than 10 letters
# T = O(10) = O(1)
# S = O(1) extra space
def designer_pdf_viewer(letters_heights, word)
  ch = word.each_char.max_by { |ch| letters_heights[ch.ord - 'a'.ord] }
  max_height = letters_heights[ch.ord - 'a'.ord]
  max_height * word.length
end

main if __FILE__ == $0
