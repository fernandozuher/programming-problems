// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  let title: string = readLine();
  let author: string = readLine();
  let price: number = +readLine();
  let novel = new MyBook(title, author, price);
  novel.display();
}

abstract class Book {
  protected title: string;
  protected author: string;

  protected constructor(title: string, author: string) {
    this.title = title;
    this.author = author;
  }

  abstract display(): void;
}

class MyBook extends Book {
  private price: number;

  constructor(title: string, author: string, price: number) {
    super(title, author);
    this.price = price;
  }

  display() {
    console.log(
      `Title: ${this.title} \nAuthor: ${this.author} \nPrice: ${this.price}`,
    );
  }
}
