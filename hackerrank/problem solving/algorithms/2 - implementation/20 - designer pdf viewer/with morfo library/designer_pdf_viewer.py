# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import morfo


def main():
    letters_heights = morfo.read(int, 26)
    word = morfo.read(str)
    print(designer_pdf_viewer(letters_heights, word))


# n: length word, <= 10
# T: O(10) = O(1)
# S: O(1) extra space
def designer_pdf_viewer(letters_heights, word):
    max_height = max(letters_heights[ord(ch) - ord('a')] for ch in word)
    return max_height * len(word)


if __name__ == '__main__':
    main()
