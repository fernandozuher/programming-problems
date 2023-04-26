# Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main():

    ATTENDEES, TOPICS = readAnIntArray()
    BINARY_STRINGS = readStrings(ATTENDEES)

    OBJ = ACM_ICPC_TEAM(BINARY_STRINGS)
    print(f"{OBJ.getMaximumSubjectsKnownByTeams()} \n{OBJ.getTeamsThatKnowMaximumSubjects()}")


def readAnIntArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def readStrings(N_STRINGS):

    BINARY_STRINGS = [input() for _ in range(N_STRINGS)]
    return BINARY_STRINGS


class ACM_ICPC_TEAM:

    def __init__(self, binaryStrings):

        self.__binaryStrings = binaryStrings
        self.__maximumSubjectsKnownByTeams = 0
        self.__teamsThatKnowMaximumSubjects = 0

        self.__findMaximumSubjectsAndTeamsThatKnowThem()


    def __findMaximumSubjectsAndTeamsThatKnowThem(self):

        RANGE_OF_BINARY_STRINGS_1 = enumerate(self.__binaryStrings[:len(self.__binaryStrings) - 1])

        for i, BINARY_STRING_1 in RANGE_OF_BINARY_STRINGS_1:
            RANGE_OF_BINARY_STRINGS_2 = self.__binaryStrings[i + 1:]
            
            for BINARY_STRING_2 in RANGE_OF_BINARY_STRINGS_2:
                SUBJECTS_KNOWN_BY_2_TEAMS = self.__countSubjectsKnownBy2Teams(BINARY_STRING_1, BINARY_STRING_2)
                self.__updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS)


    def __countSubjectsKnownBy2Teams(self, BINARY_STRING_1, BINARY_STRING_2):

        subjectsKnownBy2Teams = 0

        for characterString1, characterString2 in zip(BINARY_STRING_1, BINARY_STRING_2):
            if characterString1 == '1' or characterString2 == '1':
                subjectsKnownBy2Teams += 1

        return subjectsKnownBy2Teams


    def __updateMaximumSubjectsAndTeamsThatKnowThem(self, SUBJECTS_KNOWN_BY_2_TEAMS):

        if SUBJECTS_KNOWN_BY_2_TEAMS > self.__maximumSubjectsKnownByTeams:
            self.__maximumSubjectsKnownByTeams = SUBJECTS_KNOWN_BY_2_TEAMS
            self.__teamsThatKnowMaximumSubjects = 1

        elif SUBJECTS_KNOWN_BY_2_TEAMS == self.__maximumSubjectsKnownByTeams:
            self.__teamsThatKnowMaximumSubjects += 1


    def getMaximumSubjectsKnownByTeams(self):

        return self.__maximumSubjectsKnownByTeams


    def getTeamsThatKnowMaximumSubjects(self):

        return self.__teamsThatKnowMaximumSubjects


if __name__ == "__main__":
    main()
