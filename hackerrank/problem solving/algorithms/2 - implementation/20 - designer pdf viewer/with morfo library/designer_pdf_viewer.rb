# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

require 'morfo'

def main
  letters_heights = Morfo.read(26, &:to_i)
  word = Morfo.read(&:to_s)
  puts designer_pdf_viewer(letters_heights, word)
end

# n: length word, <= 10
# T: O(10) = O(1)
# S: O(1) extra space
def designer_pdf_viewer(letters_heights, word)
  max_height = word.each_char.lazy.map { |ch| letters_heights[ch.ord - 'a'.ord] }.max
  max_height * word.length
end

main if __FILE__ == $0
