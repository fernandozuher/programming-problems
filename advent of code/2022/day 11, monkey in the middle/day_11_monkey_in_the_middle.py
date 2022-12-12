class Monkey:

    def __init__(self, input):

        self.indexMonkey = input[0]
        self.itemList = input[1]
        self.operationOperator = input[2]
        self.operationOperand = input[3]
        self.testDivisibleOperand = input[4]
        self.testTrueThrowsItemToMonkey = input[5]
        self.testFalseThrowsItemToMonkey = input[6]
        self.inspectedItems = 0


class MonkeyInTheMiddle:

    def __init__(self, input):

        self.__monkeys = []
        self.__levelMonkeyBusiness = 0
        self.__calculateLevelMonkeyBusinessWithoutDivisionBy3 = 0
        self.__initializeMonkeysFormattingInput(input)

        self.__runSolution(input)
        self.printOutput()


    def __initializeMonkeysFormattingInput(self, input):

        indexMonkey = None
        itemList = []
        operationOperator = ""
        operationOperand = ""
        testDivisibleOperand = None
        testTrueThrowsItemToMonkey = None
        testFalseThrowsItemToMonkey = None

        for line in input:

            splittedLine = line.split()
            
            if len(splittedLine) > 0:

                if (word := splittedLine[0]) == "Monkey":
                    index = splittedLine[1].replace(":", "")
                    indexMonkey = int(index)
                
                elif word == "Starting":
                    stringList = [data.replace(",", "") for data in splittedLine[2:]]
                    itemList = list(map(int, stringList))

                elif word == "Operation:":
                    operationOperator = splittedLine[4]
                    operationOperand = splittedLine[5]

                elif word == "Test:":
                    testDivisibleOperand = int(splittedLine[3])

                elif word == "If":
                    if splittedLine[1] == "true:":
                        testTrueThrowsItemToMonkey = int(splittedLine[-1])
                    else:
                        testFalseThrowsItemToMonkey = int(splittedLine[-1])

                        monkeyData = [indexMonkey, itemList, operationOperator, operationOperand, testDivisibleOperand, testTrueThrowsItemToMonkey, testFalseThrowsItemToMonkey]
                        monkey = Monkey(monkeyData)
                        self.__monkeys.append(monkey)
                        
        
    def __runSolution(self, input):

        rounds = range(20)
        for _ in rounds:
            for monkey in self.__monkeys:
                for item in monkey.itemList:
                    
                    operand2 = item
                    operand1 = operand2 if monkey.operationOperand == "old" else int(monkey.operationOperand)
                    
                    operation = operand1 + operand2 if monkey.operationOperator == "+" else int(operand1 * operand2)
                    newWorryLevel = int(operation / 3)

                    isDivisibleByOperand = newWorryLevel % monkey.testDivisibleOperand == 0

                    if isDivisibleByOperand == True:
                        indexNewMonkey = monkey.testTrueThrowsItemToMonkey
                        self.__monkeys[indexNewMonkey].itemList.append(newWorryLevel)

                    else:
                        indexNewMonkey = monkey.testFalseThrowsItemToMonkey
                        self.__monkeys[indexNewMonkey].itemList.append(newWorryLevel)

                    monkey.inspectedItems += 1

                monkey.itemList = []

        self.__calculateLevelMonkeyBusiness()


    def __calculateLevelMonkeyBusiness(self):

        inspectedItems = [monkey.inspectedItems for monkey in self.__monkeys]
        inspectedItems.sort(reverse=True)
        twoMostActiveMonkeys = inspectedItems[:2]
        self.__levelMonkeyBusiness = twoMostActiveMonkeys[0] * twoMostActiveMonkeys[1]

    
    def __calculateLevelMonkeyBusinessWithoutDivisionBy3(self):

        inspectedItems = [monkey.inspectedItems for monkey in self.__monkeys]
        inspectedItems.sort(reverse=True)
        twoMostActiveMonkeys = inspectedItems[:2]
        self.__calculateLevelMonkeyBusinessWithoutDivisionBy3 = twoMostActiveMonkeys[0] * twoMostActiveMonkeys[1]


    def printOutput(self):

        print(self.__levelMonkeyBusiness)


def main():

    with open("input.txt") as f:
        input = f.readlines()
    monkeyInTheMiddle = MonkeyInTheMiddle(input)


if __name__ == "__main__":
    main()
