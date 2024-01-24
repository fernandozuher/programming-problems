# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?is_full_screen=true

def main():

    n = int(input())
    nearest_cats_or_not = [None] * n

    ANIMALS = 3
    for i in range(n):
        positions = read_int_array(ANIMALS)
        obj = CatsAndAMouse(positions)
        nearest_cats_or_not[i] = obj.nearest_cat_or_not()

    print(*nearest_cats_or_not, sep='\n')


def read_int_array(n):

    return list(map(int, input().split()))


class CatsAndAMouse:

    def __init__(self, cats_and_mouse_positions):

        self._cat_a_position, self._cat_b_position, self._mouse_position = cats_and_mouse_positions
        self._nearest_cat_or_not = ''
        self._find_nearest_cat_or_not()


    def _find_nearest_cat_or_not(self):

        cat_a_position_from_mouse = abs(self._cat_a_position - self._mouse_position)
        cat_b_position_from_mouse = abs(self._cat_b_position - self._mouse_position)

        if cat_a_position_from_mouse < cat_b_position_from_mouse:
            self._nearest_cat_or_not = 'Cat A'
        elif cat_a_position_from_mouse > cat_b_position_from_mouse:
            self._nearest_cat_or_not = 'Cat B'
        else:
            self._nearest_cat_or_not = 'Mouse C'


    def nearest_cat_or_not(self):

        return self._nearest_cat_or_not


if __name__ == '__main__':
    main()
