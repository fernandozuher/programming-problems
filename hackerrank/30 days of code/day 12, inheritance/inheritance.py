# https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

from dataclasses import dataclass
from statistics import mean


def main():
    personal_data, student_data = read_input()
    student = Student(personal_data, student_data)
    student.print_person()
    print('Grade:', student.calculate_grade())


def read_input():
    first_name, last_name, id = input().split()
    input()  # Skip new line about size of scores
    scores = list(map(int, input().split()))
    return PersonalData(first_name, last_name, int(id)), StudentData(scores)


@dataclass(frozen=True)
class PersonalData:
    first_name: str
    last_name: str
    id: int


@dataclass(frozen=True)
class StudentData:
    scores: list


class Person:

    def __init__(self, personal_data):
        self.__first_name = personal_data.first_name
        self.__last_name = personal_data.last_name
        self.__id = personal_data.id

    def print_person(self):
        print(f"Name: {self.__last_name}, {self.__first_name} \nid: {self.__id}")


class Student(Person):

    def __init__(self, personal_data, student_data):
        super().__init__(personal_data)
        self.__scores = student_data.scores

    def calculate_grade(self):
        avg = mean(self.__scores)

        if avg > 100 or avg < 40:
            return 'T'
        elif avg >= 90:
            return 'O'
        elif avg >= 80:
            return 'E'
        elif avg >= 70:
            return 'A'
        elif avg >= 55:
            return 'P'
        return 'D'


if __name__ == '__main__':
    main()
