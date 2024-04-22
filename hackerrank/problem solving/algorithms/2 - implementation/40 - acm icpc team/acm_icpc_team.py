# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

from bitarray import bitarray

def main():

    attendees, topics = read_int_array()
    binaries = read_binaries(attendees)
    obj = ACM_ICPC_TEAM(binaries)
    obj.find_maximum_subjects_and_teams_that_know_them()
    print(f"{obj.maximum_subjects_known_by_teams()} \n{obj.teams_that_know_maximum_subjects()}")


def read_int_array():

    return list(map(int, input().split()))


def read_binaries(n):

    return [bitarray(input()) for _ in range(n)]


class ACM_ICPC_TEAM:

    def __init__(self, binaries):

        self._binaries = binaries
        self._maximum_subjects_known_by_teams = 0
        self._teams_that_know_maximum_subjects = 0


    def find_maximum_subjects_and_teams_that_know_them(self):

        for i, previous in enumerate(self._binaries[:-1]):
            for current in self._binaries[i + 1:]:
                subjects_known_by_2_teams = self._count_subjects_known_by_2_teams(previous, current)
                self._update_maximum_subjects_and_teams_that_know_them(subjects_known_by_2_teams)


    def _count_subjects_known_by_2_teams(self, binary1, binary2):

        return (binary1 | binary2).count(1)


    def _update_maximum_subjects_and_teams_that_know_them(self, subjects_known_by_2_teams):

        if subjects_known_by_2_teams > self._maximum_subjects_known_by_teams:
            self._maximum_subjects_known_by_teams = subjects_known_by_2_teams
            self._teams_that_know_maximum_subjects = 1

        elif subjects_known_by_2_teams == self._maximum_subjects_known_by_teams:
            self._teams_that_know_maximum_subjects += 1


    def maximum_subjects_known_by_teams(self):

        return self._maximum_subjects_known_by_teams


    def teams_that_know_maximum_subjects(self):

        return self._teams_that_know_maximum_subjects


if __name__ == '__main__':
    main()
