# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main():
    letters_heights = read_numbers()
    word = input()
    print(designer_pdf_viewer(letters_heights, word))


def read_numbers():
    return list(map(int, input().split()))


def designer_pdf_viewer(letters_heights, word):
    max_height = max(letters_heights[ord(letter) - ord('a')] for letter in word)
    return max_height * len(word)


if __name__ == '__main__':
    main()
