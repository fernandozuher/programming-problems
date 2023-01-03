#!/bin/python3

# Source: 

def main():

    input1 = readLineAsIntList()
    itemAnnaDidntConsume = input1[1]
    
    costOfEachMeal = readLineAsIntList()
    brianChargedAnna = readLineAsIntList()

    result = Result(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna[0])


def readLineAsIntList():

    numbers = list(map(int, input().split()))
    return numbers


class Result:

    def __init__(self, costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna):
        
        self.__costOfEachMeal = costOfEachMeal.copy()
        self.__itemAnnaDidntConsume = itemAnnaDidntConsume
        self.__brianChargedAnna = brianChargedAnna
        self.__brianOverchargedAnna = ""

        self.__bonAppetit()
        self.printResult()


    def __bonAppetit(self):

        annaCost = self.__calculateAnnaCost()
        self.__brianOverchargedAnna = self.__checkIfBrianOverchargedAnna(annaCost)


    def __calculateAnnaCost(self):
        
        sumElements = sum(self.__costOfEachMeal)
        annaCost = (sumElements - self.__costOfEachMeal[self.__itemAnnaDidntConsume]) / 2
        return int(annaCost)


    def __checkIfBrianOverchargedAnna(self, annaCost):
        
        if annaCost == self.__brianChargedAnna:
            return "Bon Appetit"
        else:
            brianOverchargedAnna = self.__brianChargedAnna - annaCost
            return str(brianOverchargedAnna)


    def printResult(self):
        
        print(self.__brianOverchargedAnna)


if __name__ == "__main__":
    main()
