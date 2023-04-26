# Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main
    attendees, topics = readAnIntArray
    binaryStrings = readStrings attendees

    obj = AcmIcpcTeam.new binaryStrings
    puts obj.getMaximumSubjectsKnownByTeams, obj.getTeamsThatKnowMaximumSubjects
end

    def readAnIntArray
        array = gets.split.map(&:to_i)
    end

    def readStrings nStrings
        binaryStrings = Array.new(nStrings).map{|_| gets.strip}
    end

    class AcmIcpcTeam
        @binaryStrings
        @maximumSubjectsKnownByTeams
        @teamsThatKnowMaximumSubjects

        def initialize binaryStrings
            @binaryStrings = binaryStrings
            @maximumSubjectsKnownByTeams = 0
            @teamsThatKnowMaximumSubjects = 0

            _findMaximumSubjectsAndTeamsThatKnowThem
        end

            def _findMaximumSubjectsAndTeamsThatKnowThem
                rangeOfBinaryStrings1 = @binaryStrings[0...@binaryStrings.size - 1].each_with_index

                for binaryString1, i in rangeOfBinaryStrings1
                    rangeOfBinaryStrings2 = @binaryStrings[i + 1...@binaryStrings.size]
                    
                    for binaryString2 in rangeOfBinaryStrings2
                        subjectsKnownBy2Teams = _countSubjectsKnownBy2Teams binaryString1, binaryString2
                        _updateMaximumSubjectsAndTeamsThatKnowThem subjectsKnownBy2Teams
                    end
                end
            end

                def _countSubjectsKnownBy2Teams binaryString1, binaryString2
                    subjectsKnownBy2Teams = 0

                    for characterString1, characterString2 in binaryString1.chars.zip(binaryString2.chars)
                        if characterString1 == '1' || characterString2 == '1'
                            subjectsKnownBy2Teams += 1
                        end
                    end

                    subjectsKnownBy2Teams
                end

                def _updateMaximumSubjectsAndTeamsThatKnowThem subjectsKnownBy2Teams
                    if subjectsKnownBy2Teams > @maximumSubjectsKnownByTeams
                        @maximumSubjectsKnownByTeams = subjectsKnownBy2Teams
                        @teamsThatKnowMaximumSubjects = 1

                    elsif subjectsKnownBy2Teams == @maximumSubjectsKnownByTeams
                        @teamsThatKnowMaximumSubjects += 1
                    end
                end

        def getMaximumSubjectsKnownByTeams
            @maximumSubjectsKnownByTeams
        end

        def getTeamsThatKnowMaximumSubjects
            @teamsThatKnowMaximumSubjects
        end
    end

main
