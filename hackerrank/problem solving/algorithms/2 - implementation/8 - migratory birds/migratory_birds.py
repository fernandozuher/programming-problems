# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main():

    n = int(input())
    array = readIntArray()
    array.sort()

    obj = MigratoryBirds(array)
    print(obj.mostSpottedBird())


def readIntArray():

    return list(map(int, input().split()))


class MigratoryBirds:

    def __init__(self, birdSightings):
    
        self._birdSightings = birdSightings
        self._mostSpottedBird = None
        self._findMostSpottedBird()


    def _findMostSpottedBird(self):
    
            self._mostSpottedBird = self._birdSightings[0]
            countMostSpottedBird = 1
            tempCountMostSpottedBird = 1

            n = len(self._birdSightings)
            for i in range(1, n):

                if self._birdSightings[i] == self._birdSightings[i - 1]:
                    tempCountMostSpottedBird += 1
                
                elif tempCountMostSpottedBird > countMostSpottedBird:
                    self._mostSpottedBird = self._birdSightings[i - 1]
                    countMostSpottedBird = tempCountMostSpottedBird
                    tempCountMostSpottedBird = 1
                
            if tempCountMostSpottedBird > countMostSpottedBird:
                self._mostSpottedBird = self._birdSightings[n - 1]
        

    def mostSpottedBird(self):
        
        return self._mostSpottedBird


if __name__ == "__main__":
    main()
