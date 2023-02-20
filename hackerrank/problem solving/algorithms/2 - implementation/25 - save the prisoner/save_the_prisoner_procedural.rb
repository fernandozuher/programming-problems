# Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main
    nTestCases = readANumber
    prisonersChairNumberToWarn = readTestCasesAndSaveThePrisoners nTestCases
    printResults prisonersChairNumberToWarn
end

    def readANumber
        number = gets.to_i
    end

    def readTestCasesAndSaveThePrisoners nTestCases
        prisonersChairNumberToWarn = Array.new nTestCases

        for i in 0..(nTestCases-1)
            testCase = readTestCase
            prisonersChairNumberToWarn[i] = saveThePrisoner testCase
        end

        prisonersChairNumberToWarn
    end

        def readTestCase
            testCase = gets.split.map(&:to_i)
        end

        def saveThePrisoner testCase
            prisoners = testCase.first
            sweets = testCase[1]
            chairNumberToBegin = testCase.last
            prisonerChairNumberToWarn = chairNumberToBegin + (sweets - 1)

            if prisonerChairNumberToWarn > prisoners
                prisonerChairNumberToWarn %= prisoners

                if prisonerChairNumberToWarn == 0
                    prisonerChairNumberToWarn = prisoners
                end
            end

            prisonerChairNumberToWarn
        end

    def printResults array
        puts array
    end

main