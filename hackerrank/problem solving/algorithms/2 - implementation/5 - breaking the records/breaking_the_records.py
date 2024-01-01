# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main():

    input()
    array = read_int_array()

    records = BreakingBestAndWorstRecords(array)
    print(f"{records.most_points_records()} {records.least_points_records()}")


def read_int_array():

    return list(map(int, input().split()))


class BreakingBestAndWorstRecords:

    def __init__(self, array):

        self._scores = array.copy()
        self._breaking_most_points_records = 0
        self._breaking_least_points_records = 0
        self._breaking_records()


    def _breaking_records(self):

        most_points = self._scores[0]
        least_points = self._scores[0]

        for score in self._scores:
            if score > most_points:
                most_points = score
                self._breaking_most_points_records += 1
            elif score < least_points:
                least_points = score
                self._breaking_least_points_records += 1


    def most_points_records(self):

        return self._breaking_most_points_records;


    def least_points_records(self):

        return self._breaking_least_points_records


if __name__ == "__main__":
    main()
