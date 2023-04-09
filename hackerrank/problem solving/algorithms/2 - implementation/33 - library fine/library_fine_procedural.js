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

    const FINE = calculate_fine(RETURN_DATE, DUE_DATE);
    console.log(FINE);
}

    function readADate() {
        const [DAY, MONTH, YEAR] = readLine().split(" ").map(Number);
        const DATE = new DateThatWorks(DAY, MONTH, YEAR);
        return DATE;
    }

    function calculate_fine(returnDate, dueDate) {
        let fine;

        if (wereBooksReturnedInTime(returnDate, dueDate))
            fine = 0;
        else if (isReturnDateLateInMoreThanOrEqualToOneYear(returnDate.getYear(), dueDate.getYear()))
            fine = HackosFine.HackosYearsFine;
        else if (isReturnDateLateInMoreThanOrEqualToOneMonth(returnDate.getMonth(), dueDate.getMonth()))
            fine = (returnDate.getMonth() - dueDate.getMonth()) * HackosFine.HackosMonthsFine;
        else
            fine = (returnDate.getDay() - dueDate.getDay()) * HackosFine.HackosDaysFine;

        return fine;
    }

        function wereBooksReturnedInTime(returnDate, dueDate) {
            if ((returnDate.getYear() < dueDate.getYear()) ||
                    ((returnDate.getYear() === dueDate.getYear()) && (returnDate.getMonth() < dueDate.getMonth())) ||
                    ((returnDate.getYear() === dueDate.getYear()) && (returnDate.getMonth() === dueDate.getMonth()) && (returnDate.getDay() <= dueDate.getDay()))
               )
                return true;
            return false;
        }

        function isReturnDateLateInMoreThanOrEqualToOneYear(returnDateYear, dueDateYear) {
            return returnDateYear > dueDateYear;
        }

        function isReturnDateLateInMoreThanOrEqualToOneMonth(returnDateMonth, dueDateMonth) {
            return returnDateMonth > dueDateMonth;
        }
