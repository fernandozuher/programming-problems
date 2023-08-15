// https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

function main() {
    const TITLE = readLine();
    const AUTHOR = readLine();
    const PRICE = +readLine();
    
    const NOVEL = new MyBook(title, author, price);
    NOVEL.display();
}

    class Book {
        _title;
        _author;

        constructor(title, author) {
            if (this.constructor === Book)
                throw new TypeError('Do not attempt to directly instantiate an abstract class.');
            else {
                this._title = title;
                this._author = author;
            }
        }

        display() {
            console.log(`Implement the 'display' method!`);
        }
    }

        class MyBook extends Book {
            #price;
            
            constructor(title, author, price) {
                super(title, author);
                this.#price = price;
            }
            
            display() {
                console.log(`Title: ${this._title} \nAuthor: ${this._author} \nPrice: ${this.#price}`)
            }
        }
