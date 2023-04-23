# Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main():

    ATTENDEES, TOPICS = readAnIntArray()
    BINARY_STRINGS = readStrings(ATTENDEES)

    output = acmTeam(BINARY_STRINGS)
    print(*output, sep="\n")


def readAnIntArray():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def readStrings(N_STRINGS):

    BINARY_STRINGS = [input() for _ in range(N_STRINGS)]
    return BINARY_STRINGS


def acmTeam(BINARY_STRINGS):

    maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects = findMaximumSubjectsAndTeamsThatKnowThem(BINARY_STRINGS)
    output = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]
    return output


def findMaximumSubjectsAndTeamsThatKnowThem(BINARY_STRINGS):

    maximumSubjectsKnownByTeams = 0
    teamsThatKnowMaximumSubjects = 0
    RANGE_OF_BINARY_STRINGS_1 = enumerate(BINARY_STRINGS[:len(BINARY_STRINGS) - 1])

    for i, BINARY_STRING_1 in RANGE_OF_BINARY_STRINGS_1:
        RANGE_OF_BINARY_STRINGS_2 = BINARY_STRINGS[i + 1:]
        
        for BINARY_STRING_2 in RANGE_OF_BINARY_STRINGS_2:
            temporaryMaximumSubjectsKnownBy2Teams = calculateMaximumSubjectsKnownByTeam(BINARY_STRING_1, BINARY_STRING_2)

            maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects = \
                updateMaximumSubjectsKnownByTeamsAndTeamsThatKnowMaximumSubjects(temporaryMaximumSubjectsKnownBy2Teams, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects)

    return [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]


def calculateMaximumSubjectsKnownByTeam(BINARY_STRING_1, BINARY_STRING_2):

    temporaryMaximumSubjectsKnownBy2Teams = 0

    for characterString1, characterString2 in zip(BINARY_STRING_1, BINARY_STRING_2):
        if characterString1 == '1' or characterString2 == '1':
            temporaryMaximumSubjectsKnownBy2Teams += 1

    return temporaryMaximumSubjectsKnownBy2Teams


def updateMaximumSubjectsKnownByTeamsAndTeamsThatKnowMaximumSubjects(temporaryMaximumSubjectsKnownBy2Teams, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects):

    if temporaryMaximumSubjectsKnownBy2Teams > maximumSubjectsKnownByTeams:
        maximumSubjectsKnownByTeams = temporaryMaximumSubjectsKnownBy2Teams
        teamsThatKnowMaximumSubjects = 1

    elif temporaryMaximumSubjectsKnownBy2Teams == maximumSubjectsKnownByTeams:
        teamsThatKnowMaximumSubjects += 1

    return [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]


if __name__ == "__main__":
    main()
