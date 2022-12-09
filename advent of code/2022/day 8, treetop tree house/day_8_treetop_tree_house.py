import sys

class TreetopTreeHouse:

    def __init__(self, input):

        self.nLines = len(input)
        self.nColumns = len(input[0]) - 1 #minus \n
        self.amountVisibleTrees = self.nLines*2 + self.nColumns*2 - 4

        minIntegerPython = -sys.maxsize - 1
        self.highestScenicScore = minIntegerPython

        self.runSolution(input)
        self.printOutput()


    def runSolution(self, input):

        for i in range(1, self.nLines - 1):
            for j in range(1, self.nColumns - 1):
                self.__calculateAmountTreesVisibleFromOutside(input, i, j)
                self.__findHighestScenicScore(input, i, j)


    def __calculateAmountTreesVisibleFromOutside(self, input, i, j):

        if self.__upMovementTreesVisible(input, i, j) or self.__downMovementTreesVisible(input, i, j) or \
           self.__leftMovementTreesVisible(input, i, j) or self.__rightMovementTreesVisible(input, i, j):
           self.amountVisibleTrees += 1
           return


    def __upMovementTreesVisible(self, input, i, j):

        isTreeVisible = True
        currentHeightTree = input[i][j]
        for upIndex in range(0, i):
            if input[upIndex][j] >= currentHeightTree:
                isTreeVisible = False
                break
        
        return isTreeVisible


    def __downMovementTreesVisible(self, input, i, j):

        isTreeVisible = True
        currentHeightTree = input[i][j]
        for downIndex in range(i+1, self.nLines):
            if input[downIndex][j] >= currentHeightTree:
                isTreeVisible = False
                break
        
        return isTreeVisible

    
    def __leftMovementTreesVisible(self, input, i, j):

        isTreeVisible = True
        currentHeightTree = input[i][j]
        for leftIndex in range(0, j):
            if input[i][leftIndex] >= currentHeightTree:
                isTreeVisible = False
                break
        
        return isTreeVisible


    def __rightMovementTreesVisible(self, input, i, j):

        isTreeVisible = True
        currentHeightTree = input[i][j]
        for righIndex in range(j+1, self.nColumns):
            if input[i][righIndex] >= currentHeightTree:
                isTreeVisible = False
                break
        
        return isTreeVisible


    def __findHighestScenicScore(self, input, i, j):

        up = self.__upMovementScenicScore(input, i, j)
        down = self.__downMovementScenicScore(input, i, j)
        left = self.__leftMovementScenicScore(input, i, j)
        right = self.__rightMovementScenicScore(input, i, j)

        currentScenicScore = up * down * left * right

        if self.highestScenicScore < currentScenicScore:
            self.highestScenicScore = currentScenicScore


    def __upMovementScenicScore(self, input, i, j):

        up = 0
        currentHeightTree = input[i][j]
        for upIndex in range(i-1, -1, -1):
            up +=1
            if input[upIndex][j] >= currentHeightTree:
                break
        return up


    def __downMovementScenicScore(self, input, i, j):

        down = 0
        currentHeightTree = input[i][j]
        for downIndex in range(i+1, self.nLines):
            down += 1
            if input[downIndex][j] >= currentHeightTree:
                break
        return down

    
    def __leftMovementScenicScore(self, input, i, j):

        left = 0
        currentHeightTree = input[i][j]
        for leftIndex in range(j-1, -1, -1):
            left += 1
            if input[i][leftIndex] >= currentHeightTree:
                break
        return left


    def __rightMovementScenicScore(self, input, i, j):

        right = 0
        currentHeightTree = input[i][j]
        for rightIndex in range(j+1, self.nColumns):
            right += 1
            if input[i][rightIndex] >= currentHeightTree:
                break
        return right


    def printOutput(self):
        print(self.amountVisibleTrees)
        print(self.highestScenicScore)
    

def main():
    with open("input.txt") as f:
        input = f.readlines()
    treetopTreeHouse = TreetopTreeHouse(input)


if __name__ == "__main__":
    main()
