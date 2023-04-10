// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


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

    getDay() {
        return this.#day;
    }

    getMonth() {
        return this.#month;
    }

    getYear() {
        return this.#year;
    }
}

function main() {
    const RETURN_DATE = readADate();
    const DUE_DATE = readADate();

    const OBJ = new LibraryFine(RETURN_DATE, DUE_DATE);
    const FINE = OBJ.getFine();
    console.log(FINE);
}

    function readADate() {
        const [DAY, MONTH, YEAR] = readLine().split(" ").map(Number);
        const DATE = new DateThatWorks(DAY, MONTH, YEAR);
        return DATE;
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
                    this.#fine = (this.#returnDate.getMonth() - this.#dueDate.getMonth()) * HackosFine.HackosMonthsFine;
                else
                    this.#fine = (this.#returnDate.getDay() - this.#dueDate.getDay()) * HackosFine.HackosDaysFine;
            }

                #wereBooksReturnedInTime() {
                    if ((this.#returnDate.getYear() < this.#dueDate.getYear()) ||
                            ((this.#returnDate.getYear() === this.#dueDate.getYear()) && (this.#returnDate.getMonth() < this.#dueDate.getMonth())) ||
                            ((this.#returnDate.getYear() === this.#dueDate.getYear()) && (this.#returnDate.getMonth() === this.#dueDate.getMonth()) && (this.#returnDate.getDay() <= this.#dueDate.getDay()))
                       )
                        return true;
                    return false;
                }

                #isReturnDateLateInMoreThanOrEqualToOneYear() {
                    return this.#returnDate.getYear() > this.#dueDate.getYear();
                }

                #isReturnDateLateInMoreThanOrEqualToOneMonth() {
                    return this.#returnDate.getMonth() > this.#dueDate.getMonth();
                }

        getFine() {
            return this.#fine;
        }
    }
