class CathodeRayTube:

    def __init__(self, input):

        self.__sumSixSignalStrengths = 0
        self.__runSolution(input)
        self.printOutput()


    def __runSolution(self, input):

        currentCycle = 0
        registerX = 1

        for line in input:

            self.__drawSprite(currentCycle, registerX)
            currentCycle += 1
            self.__sumSignalStrengthIfCurrentCycleIsInRange(currentCycle, registerX)

            splittedLine = line.split()
            if splittedLine[0] == "addx":

                self.__drawSprite(currentCycle, registerX)
                currentCycle += 1
                self.__sumSignalStrengthIfCurrentCycleIsInRange(currentCycle, registerX)

                registerX += int(splittedLine[1])
                

    def __sumSignalStrengthIfCurrentCycleIsInRange(self, currentCycle, registerX):

        isDivisibleBy40 = (currentCycle - 20) % 40 == 0 # => currentCycle in (20, 20+40, 20+40+40, ...)
        if isDivisibleBy40:
            self.__sumSixSignalStrengths += currentCycle * registerX


    def __drawSprite(self, currentCycle, registerX):
      
        lastPixelOfRow = currentCycle % 40 == 0 # => 40, 80, 120, 160, 200

        if lastPixelOfRow:
            print()
        newX = self.__calculateNewX(currentCycle, registerX)
        self.__drawPixel(currentCycle, newX)


    def __calculateNewX(self, currentCycle, registerX):

        crtRaw = int(currentCycle / 40)
        newX = registerX + 40 * crtRaw
        return newX


    def __drawPixel(self, currentCycle, newX):

        if currentCycle in (newX-1, newX, newX+1):
            print("# ", end="")
        else:
            print(". ", end="")

    
    def printOutput(self):
        
        print(f"\n\n{self.__sumSixSignalStrengths}")


def main():
    with open("input.txt") as f:
        input = f.readlines()
    cathodeRayTube = CathodeRayTube(input)


if __name__ == "__main__":
    main()
