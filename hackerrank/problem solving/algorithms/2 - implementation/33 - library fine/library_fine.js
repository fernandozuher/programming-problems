// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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

//////////////////////////////////////////////////

const HackosFine = Object.freeze({
    HackosDaysFine: 15,
    HackosMonthsFine: 500,
    HackosYearsFine: 10000
})

class DateThatWorks {
    #day;
    #month;
    #year;

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

function main() {
    let returnDate = readADate();
    let dueDate = readADate();
    let obj = new LibraryFine(returnDate, dueDate);
    console.log(obj.fine());
}

    function readADate() {
        let [day, month, year] = readLine().split(' ').map(Number);
        return new DateThatWorks(day, month, year);
    }

    class LibraryFine {
        #returnDate;
        #dueDate;
        #fine;

        constructor(returnDate, dueDate) {
            this.#returnDate = returnDate;
            this.#dueDate = dueDate;
            this.#fine = 0;
            this.#calculateFine();
        }

            #calculateFine() {
                if (this.#wereBooksReturnedInTime())
                    this.#fine = 0;
                else if (this.#isReturnDateLateInMoreThanOrEqualToOneYear())
                    this.#fine = HackosFine.HackosYearsFine;
                else if (this.#isReturnDateLateInMoreThanOrEqualToOneMonth())
                    this.#fine = (this.#returnDate.month() - this.#dueDate.month()) * HackosFine.HackosMonthsFine;
                else
                    this.#fine = (this.#returnDate.day() - this.#dueDate.day()) * HackosFine.HackosDaysFine;
            }

                #wereBooksReturnedInTime() {
                    if ((this.#returnDate.year() < this.#dueDate.year()) ||
                            ((this.#returnDate.year() === this.#dueDate.year()) && (this.#returnDate.month() < this.#dueDate.month())) ||
                            ((this.#returnDate.year() === this.#dueDate.year()) && (this.#returnDate.month() === this.#dueDate.month()) && (this.#returnDate.day() <= this.#dueDate.day()))
                       )
                        return true;
                    return false;
                }

                #isReturnDateLateInMoreThanOrEqualToOneYear() {
                    return this.#returnDate.year() > this.#dueDate.year();
                }

                #isReturnDateLateInMoreThanOrEqualToOneMonth() {
                    return this.#returnDate.month() > this.#dueDate.month();
                }

        fine() {
            return this.#fine;
        }
    }
