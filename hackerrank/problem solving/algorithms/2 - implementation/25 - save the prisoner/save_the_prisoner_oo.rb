# Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main
    nTestCases = readANumber
    prisonersChairNumberToWarn = Array.new nTestCases

    for i in 0..(nTestCases - 1)
        testCase = readTestCase
        obj = SaveThePrisoner.new testCase
        prisonersChairNumberToWarn[i] = obj.getPrisonerChairNumberToWarn
    end

    printResults prisonersChairNumberToWarn
end

    def readANumber
        number = gets.to_i
    end

    def readTestCase
        testCase = gets.split.map(&:to_i)
    end

    class SaveThePrisoner

        @prisoners
        @sweets
        @chairNumberToBegin
        @prisonerChairNumberToWarn

        def initialize testCase
            @prisoners = testCase.first
            @sweets = testCase[1]
            @chairNumberToBegin = testCase.last

            @prisonerChairNumberToWarn = _saveThePrisoner
        end

            private def _saveThePrisoner
                prisonerChairNumberToWarn = @chairNumberToBegin + (@sweets - 1)

                if prisonerChairNumberToWarn > @prisoners
                    prisonerChairNumberToWarn %= @prisoners

                    if prisonerChairNumberToWarn == 0
                        prisonerChairNumberToWarn = @prisoners
                    end
                end

                prisonerChairNumberToWarn
            end

        def getPrisonerChairNumberToWarn
            @prisonerChairNumberToWarn
        end
    end

    def printResults array
        puts array
    end

main
