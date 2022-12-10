class RopeBridge:

    def __init__(self, input):

        self.__tailPositions = set()
        self.__ninthKnotPositions = set()
        self.__directionValue = {"U": 1, "D": -1, "R": 1, "L": -1}

        self.__runSolution(input)

        self.printOutput()


    def __runSolution(self, input):

        currentHeadPosition = {"line": 0, "column": 0}
        currentTailPosition = {"line": 0, "column": 0}
        knots = [{"line": 0, "column": 0} for _ in range(10)]

        self.__tailPositions.add("0 0")
        self.__ninthKnotPositions.add("0 0")

        for line in input:
            
            direction, field1, field2, timesToMove = self.__formatInput(line)
            formattedInput1 = direction, field1, field2, currentHeadPosition, currentTailPosition
            formattedInput2 = direction, field1, field2, timesToMove, knots

            for _ in range(timesToMove):
                self.__findTailPosition(formattedInput1)
                self.__findKnotNinthPosition(formattedInput2)

            #self.__printTrajectory(knots, direction, timesToMove)


    def __formatInput(self, line):
        
        direction, timesToMove = line.split()
        timesToMove = int(timesToMove)

        if direction in ("U", "D"):
            field1, field2 = "line", "column"
        elif direction in ("L", "R"):
            field1, field2 = "column", "line"

        formattedInput = direction, field1, field2, timesToMove
        return formattedInput


    def __findTailPosition(self, formattedInput):

        direction, field1, field2, currentHeadPosition, currentTailPosition = formattedInput

        currentHeadPosition[field1] += self.__directionValue[direction]

        if abs(currentTailPosition[field1] - currentHeadPosition[field1]) == 2:
            currentTailPosition[field1] = currentHeadPosition[field1] - self.__directionValue[direction]
            currentTailPosition[field2] = currentHeadPosition[field2]

            tailVisitedPosition = str(currentTailPosition["line"]) + " " + str(currentTailPosition["column"])
            self.__tailPositions.add(tailVisitedPosition)


    def __findKnotNinthPosition(self, formattedInput):

        direction, field1, field2, timesToMove, knots = formattedInput

        knots[0][field1] += self.__directionValue[direction]

        rangeKnotsFrom1To10 = range(1, 10)
        for i in rangeKnotsFrom1To10:

            moreThan2LinesFarAway = abs(knots[i]["line"] - knots[i-1]["line"]) == 2
            moreThan2ColumnsFarAway = abs(knots[i]["column"] - knots[i-1]["column"]) == 2

            if moreThan2LinesFarAway or moreThan2ColumnsFarAway:

                if moreThan2LinesFarAway and moreThan2ColumnsFarAway:
                    self.__farAwayInLineAndColumn(i, knots)
                else:
                    formattedInput = [i, knots, moreThan2LinesFarAway, moreThan2ColumnsFarAway]
                    self.__farAwayInLineOrColumn(formattedInput)

                if (lastKnot := 9) == i:
                    lastKnotVisitedPosition = str(knots[i]["line"]) + " " + str(knots[i]["column"])
                    self.__ninthKnotPositions.add(lastKnotVisitedPosition)
            else:
                break


    def __farAwayInLineAndColumn(self, index, knots):

        i = index
        newDirection1 = "U" if knots[i-1]["line"] > knots[i]["line"] else "D"
        newDirection2 = "R" if knots[i-1]["column"] > knots[i]["column"] else "L"

        knots[i]["line"] = knots[i-1]["line"] - self.__directionValue[newDirection1]
        knots[i]["column"] = knots[i-1]["column"] - self.__directionValue[newDirection2]


    def __farAwayInLineOrColumn(self, formattedInput):
        
        i, knots, moreThan2LinesFarAway, moreThan2ColumnsFarAway = formattedInput

        if moreThan2LinesFarAway:
            newField1, newField2 = "line", "column"
            newDirection = "U" if knots[i-1][newField1] > knots[i][newField1] else "D"
        
        elif moreThan2ColumnsFarAway:
            newField1, newField2 = "column", "line"
            newDirection = "R" if knots[i-1][newField1] > knots[i][newField1] else "L"

        knots[i][newField1] = knots[i-1][newField1] - self.__directionValue[newDirection]
        knots[i][newField2] = knots[i-1][newField2]


    def __printTrajectory(self, knots, direction, timesToMove):
        """ The matriz size below is suitable for the puzzle sample test size """

        print(f"Direction: {direction} {timesToMove}")

        matrixLines = 15
        columnMatrix = 16
        for i in range(matrixLines, -columnMatrix, -1):
            print(str(i).ljust(4), end="")
            for j in range(-matrixLines, columnMatrix):

                n = "."
                for k, timesToMove in enumerate(knots):

                    if i == timesToMove["line"] and j == timesToMove["column"]:
                        n = str(k)
                        break

                print(n, end="")
            print()
        print()


    def printOutput(self):
        print(len(self.__tailPositions))
        print(len(self.__ninthKnotPositions))


def main():
    with open("input.txt") as f:
        input = f.readlines()
    ropeBridge = RopeBridge(input)


if __name__ == "__main__":
    main()
