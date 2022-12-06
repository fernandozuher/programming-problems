class SupplyStacks:
    __topStacksCrateMover9000 = ""
    __topStacksCrateMover9001 = ""
    __stacksCrateMover9000 = [[] for _ in range(9)]
    __stacksCrateMover9001 = [[] for _ in range(9)]

    def __init__(self, input):
        self.__InitializeStacksState(input)
        self.__runRearrangementProcedure(input)
        self.__initializeTopStacks()
        self.printOutput()


    def __InitializeStacksState(self, input):
        crateLines = input[:8]
        for crateLine in crateLines:
            for stackIndex, crateIndex in enumerate(range(1, len(crateLine), 4)):
                if crateLine[crateIndex] != ' ':
                    self.__stacksCrateMover9000[stackIndex].insert(0, crateLine[crateIndex])
        
        for i in range(9):
            self.__stacksCrateMover9001[i] = self.__stacksCrateMover9000[i].copy()


    def __runRearrangementProcedure(self, input):
        rearrangementProcedure = input[10:]
        for procedure in rearrangementProcedure:
            extractedProcedure = self.__extractProcedure(procedure)
            self.__moveCrates(extractedProcedure)


    def __extractProcedure(self, procedure):
        splittedProcedure = procedure.split(' ')
        quantityToBeMoved = int(splittedProcedure[1])
        fromStack = int(splittedProcedure[3]) - 1
        toStack = int(splittedProcedure[5]) - 1
        return [quantityToBeMoved, fromStack, toStack]


    def __moveCrates(self, extractedProcedure):
        [quantityToBeMoved, fromStack, toStack] = extractedProcedure
        crateIndexToPopFor9001 = len(self.__stacksCrateMover9001[fromStack]) - quantityToBeMoved

        for i in range(quantityToBeMoved):
            crateToMoveBy9000 = self.__stacksCrateMover9000[fromStack].pop()
            crateToMoveBy9001 = self.__stacksCrateMover9001[fromStack].pop(crateIndexToPopFor9001)

            self.__stacksCrateMover9000[toStack].append(crateToMoveBy9000)
            self.__stacksCrateMover9001[toStack].append(crateToMoveBy9001)


    def __initializeTopStacks(self):
        for i in range(9):
            if self.__stacksCrateMover9000[i]:
                self.__topStacksCrateMover9000 += self.__stacksCrateMover9000[i][-1]

            if self.__stacksCrateMover9001[i]:
                self.__topStacksCrateMover9001 += self.__stacksCrateMover9001[i][-1]


    def printOutput(self):
        print(self.__topStacksCrateMover9000)
        print(self.__topStacksCrateMover9001)


def main():
    with open("input.txt") as f:
        input = f.readlines()
    supplyStacks = SupplyStacks(input)


if __name__ == "__main__":
    main()
