# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main():

    n = int(input())
    chocolate_squares = read_int_array()
    day_month = read_int_array()

    obj = TheBirthdayBar(chocolate_squares, day_month)
    print(obj.ways_bar_can_be_divided())


def read_int_array():

    return list(map(int, input().split()))


class TheBirthdayBar:

    def __init__(self, chocolate_squares, day_month):
        
        self._chocolate_squares = chocolate_squares
        self._day = day_month[0]
        self._month = day_month[1]
        self.n_divisions = 0

        self._birthday()


    def _birthday(self):

        for i in range (0, len(self._chocolate_squares) - self._month + 1):
            sum = 0

            for j in range(i, i + self._month):
                sum += self._chocolate_squares[j]
            if sum == self._day:
                self.n_divisions += 1


    def ways_bar_can_be_divided(self):
        
        return self.n_divisions


if __name__ == '__main__':
    main()
