# https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main():

    letters_heights = read_int_array()
    word = input()
    obj = DesignerPdfViewer(letters_heights, word)
    print(obj.area())


def read_int_array():

    return list(map(int, input().split()))


class DesignerPdfViewer:

    def __init__(self, letters_heights, word):

        self._letters_heights = letters_heights
        self._word = word
        self._area = 0
        self._calculate_area()


    def _calculate_area(self):

        max_height = 0

        for letter in self._word:
            letter_index = ord(letter) - ord('a')
            letter_height = self._letters_heights[letter_index]
            max_height = max(max_height, letter_height)

        self._area = max_height * len(self._word)


    def area(self):

        return self._area


if __name__ == "__main__":
    main()
