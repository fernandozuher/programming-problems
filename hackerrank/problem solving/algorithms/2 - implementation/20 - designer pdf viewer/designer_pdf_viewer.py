# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main():
    letters_heights = read_numbers()
    word = input()
    print(designer_pdf_viewer(letters_heights, word))


def read_numbers():
    return list(map(int, input().split()))


# n_w: length of string word, no more than 10 letters
# T = O(10) = O(1)
# S = O(1) extra space
def designer_pdf_viewer(letters_heights, word):
    max_height = max(letters_heights[ord(ch) - ord('a')] for ch in word)
    return max_height * len(word)


if __name__ == '__main__':
    main()
