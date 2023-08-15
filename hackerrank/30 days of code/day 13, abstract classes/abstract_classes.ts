// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    const TITLE: string = readLine();
    const AUTHOR: string = readLine();
    const PRICE: number = +readLine();

    const NOVEL = new MyBook(TITLE, AUTHOR, PRICE);
    NOVEL.display();
}

    class Book {
        protected title: string;
        protected author: string;
        
        constructor(title: string, author: string) {
            if (this.constructor === Book)
                throw new TypeError('Do not attempt to directly instantiate an abstract class.');
            else {
                this.title = title;
                this.author = author;
            }
        }
        
        display() {
            console.log(`Implement the 'display' method!`);
        }
    }

        class MyBook extends Book {
            private price: number;
            
            constructor(title: string, author: string, price: number) {
                super(title, author);
                this.price = price;
            }

            display() {
                console.log(`Title: ${this.title} \nAuthor: ${this.author} \nPrice: ${this.price}`)
            }
        }
