# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main
  letters_heights = read_numbers
  word = gets
  puts designer_pdf_viewer(letters_heights, word)
end

def read_numbers
  gets.split.map(&:to_i)
end

def designer_pdf_viewer(letters_heights, word)
  max_height = word.chars.inject(0) { |max_height, letter|
    [max_height, letters_heights[letter.ord - 'a'.ord]].max
  }
  max_height * word.length
end

main if $PROGRAM_NAME == __FILE__
