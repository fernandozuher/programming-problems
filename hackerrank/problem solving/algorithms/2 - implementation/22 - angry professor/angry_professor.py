# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main():

    n = int(input())
    cancelled_classes = [None] * n

    for i in range(n):
        n_students_arrival_time, cancellation_threshold = read_int_array()
        students_arrival_time = read_int_array()
        obj = AngryProfessor(students_arrival_time, cancellation_threshold)
        cancelled_classes[i] = obj.cancelled_class()

    for cancelled in cancelled_classes:
        print("YES" if cancelled else "NO")


def read_int_array():

    return list(map(int, input().split()))


class AngryProfessor:

    def __init__(self, students_arrival_time, cancellation_threshold):

        self._students_arrival_time = students_arrival_time
        self._cancellation_threshold = cancellation_threshold
        self._cancelled_class = False
        self._check_if_class_is_cancelled()


    def _check_if_class_is_cancelled(self):

        self._cancelled_class = self._count_early_arrival_time() < self._cancellation_threshold


    def _count_early_arrival_time(self):

        early_arrival_time_count = 0

        for arrival_time in self._students_arrival_time:
            if arrival_time <= 0:
                early_arrival_time_count += 1

        return early_arrival_time_count


    def cancelled_class(self):

        return self._cancelled_class


if __name__ == '__main__':
    main()
