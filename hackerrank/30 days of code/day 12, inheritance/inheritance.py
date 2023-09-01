# https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

from statistics import mean

def main():

    first_name, last_name, id = input().split()
    _ = int(input()) # n_scores not used
    scores = list(map(int, input().split()))

    student = Student(first_name, last_name, id, scores)
    student.print_person()
    print('Grade:', student.calculate())


class Person:

    def __init__(self, first_name, last_name, id):

        self.first_name = first_name
        self.last_name = last_name
        self.id = id


    def print_person(self):

        print(f"Name: {self.last_name}, {self.first_name} \nid: {self.id}")


class Student(Person):

    def __init__(self, first_name, last_name, id, scores):

        super().__init__(first_name, last_name, id)
        self._scores = scores


    def calculate(self):

        avg = mean(self._scores)

        if avg >= 90 and avg <= 100:
            return 'O'
        elif avg >= 80 and avg < 90:
            return 'E'
        elif avg >= 70 and avg < 80:
            return 'A'
        elif avg >= 55 and avg < 70:
            return 'P'
        elif avg >= 40 and avg < 55:
            return 'D'
        else:
            return 'T'


if __name__ == '__main__':
    main()
