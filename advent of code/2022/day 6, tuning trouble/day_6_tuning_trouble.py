class TuningTrouble:

    __charactersBeforeEndOfPacketMaker = -1
    __charactersBeforeEndOfMessageMaker = -1

    def __init__(self, input):
        self.__charactersBeforeEndOfPacketMaker = self.__countCharactersBeforeEndOfSomeMaker(input, 4)
        self.__charactersBeforeEndOfMessageMaker = self.__countCharactersBeforeEndOfSomeMaker(input, 14)
        self.printOutput()


    def __countCharactersBeforeEndOfSomeMaker(self, input, sizePacket):
        initialIndex = sizePacket - 1
        last_index_of_some_maker = -1

        for i in range(initialIndex, len(input[0])):
            substring = input[0][i-initialIndex : i+1]

            if (self.__isSubstringLikeASet(substring)):
                last_index_of_some_maker = i
                break

        return last_index_of_some_maker + 1


    def __isSubstringLikeASet(self, substring):
        if len(substring) == len(set(substring)):
            return True
        return False


    def printOutput(self):
        print(self.__charactersBeforeEndOfPacketMaker)
        print(self.__charactersBeforeEndOfMessageMaker)


def main():
    with open("input.txt") as f:
        input = f.readlines()
    tuningTrouble = TuningTrouble(input)


if __name__ == "__main__":
    main()
