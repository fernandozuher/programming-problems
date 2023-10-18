// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

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
    let [returnedRealDate, dueDate] = readStdinDates();
    let bookReturnDate = new BookReturnDate(returnedRealDate, dueDate);
    console.log(bookReturnDate.fine());
}

    function readStdinDates() {
        let numbers = readLine().split(' ').map(Number);
        let returnedRealDate = new DateThatWorks(...numbers);
        
        numbers = readLine().split(' ').map(Number);
        let dueDate = new DateThatWorks(...numbers);

        return [returnedRealDate, dueDate];
    }

        class DateThatWorks {
            #day = 0;
            #month = 0;
            #year = 0;

            constructor(day, month, year) {
                this.#day = day;
                this.#month = month;
                this.#year = year;
            }

            day() {
                return this.#day;
            }

            month() {
                return this.#month;
            }

            year() {
                return this.#year;
            }
        }

    class BookReturnDate {
        #returnedRealDate = Object;
        #dueDate = Object;
        #fine = 0;

        constructor(returnedRealDate, dueDate) {
            this.#returnedRealDate = returnedRealDate;
            this.#dueDate = dueDate;
            this.#calculateFine();
        }

            #calculateFine() {
                if (this.#returnedRealDate.year() < this.#dueDate.year())
                    this.#fine = 0;
                else if (this.#returnedRealDate.year() === this.#dueDate.year()) {
                    if (this.#returnedRealDate.month() < this.#dueDate.month())
                        this.#fine = 0;
                    else if (this.#returnedRealDate.month() === this.#dueDate.month()) {
                        if (this.#returnedRealDate.day() < this.#dueDate.day())
                            this.#fine = 0;
                        else
                            this.#fine = (this.#returnedRealDate.day() - this.#dueDate.day()) * HackosFine.HackosDaysFine;
                    }
                    else
                        this.#fine = (this.#returnedRealDate.month() - this.#dueDate.month()) * HackosFine.HackosMonthsFine;
                } else
                    this.#fine = HackosFine.HackosYearsFine;
            }

        fine() {
            return this.#fine;
        }
    }

        const HackosFine = Object.freeze({
            HackosDaysFine: 15,
            HackosMonthsFine: 500,
            HackosYearsFine: 10000
        });
