# https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

class Person:

    def __init__(self, initial_age):

        if initial_age < 0:
            self._age = 0
            print('Age is not valid, setting age to 0.')
        else:
            self._age = initial_age


    def am_i_old(self):

        if self._age < 13:
            print('You are young.')
        elif self._age >= 13 and self._age < 18:
            print('You are a teenager.')
        else:
            print('You are old.')


    def year_passes(self):

        self._age += 1


def main():

    n_tests = int(input())

    for _ in range(n_tests):
        age = int(input())
        p = Person(age)
        p.am_i_old()

        for _ in range(3):
            p.year_passes()
        p.am_i_old()

        print('')


if __name__ == '__main__':
    main()
