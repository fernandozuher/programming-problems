# https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

from statistics import mean

def main():

    FIRST_NAME, LAST_NAME, ID = input().split()
    _ = int(input()) # N_SCORES not used
    SCORES = list(map(int, input().split()))

    STUDENT = Student(FIRST_NAME, LAST_NAME, ID, SCORES)
    STUDENT.print_person()
    print('Grade:', STUDENT.calculate())


class Person:

    def __init__(self, first_name, last_name, id):

        self.first_name = first_name
        self.last_name = last_name
        self.id = id


    def print_person(self):

        print('Name:', self.last_name + ',', self.first_name, '\nID:', self.id)


class Student(Person):

    def __init__(self, first_name, last_name, id, scores):

        super().__init__(first_name, last_name, id)
        self._scores = scores


    def calculate(self):

        AVG = mean(self._scores)

        if AVG >= 90 and AVG <= 100:
            return 'O'
        elif AVG >= 80 and AVG < 90:
            return 'E'
        elif AVG >= 70 and AVG < 80:
            return 'A'
        elif AVG >= 55 and AVG < 70:
            return 'P'
        elif AVG >= 40 and AVG < 55:
            return 'D'
        else:
            return 'T'


if __name__ == "__main__":
    main()
