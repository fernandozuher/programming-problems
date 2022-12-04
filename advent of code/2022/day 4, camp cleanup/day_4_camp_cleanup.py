class campCleanup:
    __rangesInsideAnother = 0
    __rangesOverlapAtAll = 0

    def __init__(self, input):
        self.__campCleanup(input)
        self.printOutput()


    def __campCleanup(self, input):    
        for line in input:
            elves_ranges = self.__findRanges(line)
            output = self.__isRangeInsideAnotherRange(elves_ranges)
            self.__rangesInsideAnother += output[0]
            self.__rangesOverlapAtAll += output[1]


    def __findRanges(self, line):
        elvesPair = line.split(',')

        elf1 = list(map(int, elvesPair[0].split('-')))
        elf2 = list(map(int, elvesPair[1].split('-')))

        elf1Range = range(elf1[0], elf1[1] + 1)
        elf2Range = range(elf2[0], elf2[1] + 1)

        return [elf1Range, elf2Range]


    def __isRangeInsideAnotherRange(self, elves_ranges):
        output = [0, 0]
        if all(x in elves_ranges[0] for x in elves_ranges[1]) or all(x in elves_ranges[1] for x in elves_ranges[0]):
            output[0] = 1
        if any(x in elves_ranges[0] for x in elves_ranges[1]) or any(x in elves_ranges[1] for x in elves_ranges[0]):
            output[1] = 1
        return output


    def printOutput(self):
        print(self.__rangesInsideAnother)
        print(self.__rangesOverlapAtAll)


def main():
    with open("input.txt") as f:
        lines = f.readlines()
    obj = campCleanup(lines)


if __name__ == "__main__":
    main()
