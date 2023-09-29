# https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

from abc import ABCMeta, abstractmethod

def main():

    title = input()
    author = input()
    price = int(input())
    
    novel = MyBook(title, author, price)
    novel.display()


class Book(object, metaclass=ABCMeta):

    def __init__(self, title, author):

        self.title = title
        self.author = author


    @abstractmethod
    def display():

        pass


class MyBook(Book):

    def __init__(self, title, author, price):

        super().__init__(title, author)
        self._price = price


    def display(self):

        print(f"Title: {self.title} \nAuthor: {self.author} \nPrice: {self._price}")


if __name__ == '__main__':
    main()
