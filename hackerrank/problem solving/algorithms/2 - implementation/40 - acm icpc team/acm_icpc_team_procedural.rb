# Source https//www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main
    attendees, topics = readAnIntArray
    binaryStrings = readStrings attendees

    output = acmTeam binaryStrings
    puts output
end

    def readAnIntArray
        array = gets.split.map(&:to_i)
    end

    def readStrings nStrings
        binaryStrings = Array.new(nStrings).map{|_| gets.strip}
    end

    def acmTeam binaryStrings
        maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects = findMaximumSubjectsAndTeamsThatKnowThem binaryStrings
        output = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]
    end

    def findMaximumSubjectsAndTeamsThatKnowThem binaryStrings
        maximumSubjectsKnownByTeams = 0
        teamsThatKnowMaximumSubjects = 0
        rangeOfBinaryStrings1 = binaryStrings[0...binaryStrings.size - 1].each_with_index

        for binaryString1, i in rangeOfBinaryStrings1
            rangeOfBinaryStrings2 = binaryStrings[i + 1...binaryStrings.size]
            
            for binaryString2 in rangeOfBinaryStrings2
                temporaryMaximumSubjectsKnownBy2Teams = calculateMaximumSubjectsKnownByTeam binaryString1, binaryString2

                maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects =
                    updateMaximumSubjectsKnownByTeamsAndTeamsThatKnowMaximumSubjects temporaryMaximumSubjectsKnownBy2Teams, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects
            end
        end

        [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]
    end

        def calculateMaximumSubjectsKnownByTeam binaryString1, binaryString2
            temporaryMaximumSubjectsKnownBy2Teams = 0

            for characterString1, characterString2 in binaryString1.chars.zip(binaryString2.chars)
                if characterString1 == '1' || characterString2 == '1'
                    temporaryMaximumSubjectsKnownBy2Teams += 1
                end
            end

            temporaryMaximumSubjectsKnownBy2Teams
        end

        def updateMaximumSubjectsKnownByTeamsAndTeamsThatKnowMaximumSubjects temporaryMaximumSubjectsKnownBy2Teams, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects
            if temporaryMaximumSubjectsKnownBy2Teams > maximumSubjectsKnownByTeams
                maximumSubjectsKnownByTeams = temporaryMaximumSubjectsKnownBy2Teams
                teamsThatKnowMaximumSubjects = 1

            elsif temporaryMaximumSubjectsKnownBy2Teams == maximumSubjectsKnownByTeams
                teamsThatKnowMaximumSubjects += 1
            end

            [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects]
        end

main
