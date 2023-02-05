# Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main():

    days = int(input())
    cumulativeLikes = ViralAdvertising(days)


class ViralAdvertising:

    def __init__(self, days):

        self.__days = days
        self.__cumulativeLikes = 0
    
        self.__viralAdvertising()
        self.printCumulativeLikes()
    

    def __viralAdvertising(self):

        shared, liked, cumulative = 5, 0, 0

        for _ in range(self.__days):
            liked = int(shared / 2)
            self.__cumulativeLikes += liked
            shared = liked * 3


    def printCumulativeLikes(self):

        print(self.__cumulativeLikes)


if __name__ == "__main__":
    main()
