// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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


const HackosFine = Object.freeze({
    HackosDaysFine: 15,
    HackosMonthsFine: 500,
    HackosYearsFine: 10000
})

function main() {
    const RETURN_DATE: DateThatWorks = readADate();
    const DUE_DATE: DateThatWorks = readADate();

    const FINE: number = calculate_fine(RETURN_DATE, DUE_DATE);
    console.log(FINE);
}

    class DateThatWorks {
        _day: number;
        _month: number;
        _year: number;

        constructor(day: number, month: number, year: number) {
            this._day = day;
            this._month = month;
            this._year = year;
        }

        getDay(): number {
            return this._day;
        }

        getMonth(): number {
            return this._month;
        }

        getYear(): number {
            return this._year;
        }
    }

    function readADate(): DateThatWorks {
        const [DAY, MONTH, YEAR]: Array<number> = readLine().split(" ").map(Number);
        const DATE: DateThatWorks = new DateThatWorks(DAY, MONTH, YEAR);
        return DATE;
    }

    function calculate_fine(returnDate: DateThatWorks, dueDate: DateThatWorks): number {
        let fine: number;

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

        function wereBooksReturnedInTime(returnDate: DateThatWorks, dueDate: DateThatWorks): boolean {
            if ((returnDate.getYear() < dueDate.getYear()) ||
                    ((returnDate.getYear() === dueDate.getYear()) && (returnDate.getMonth() < dueDate.getMonth())) ||
                    ((returnDate.getYear() === dueDate.getYear()) && (returnDate.getMonth() === dueDate.getMonth()) && (returnDate.getDay() <= dueDate.getDay()))
               )
                return true;
            return false;
        }

        function isReturnDateLateInMoreThanOrEqualToOneYear(returnDateYear: number, dueDateYear: number): boolean {
            return returnDateYear > dueDateYear;
        }

        function isReturnDateLateInMoreThanOrEqualToOneMonth(returnDateMonth: number, dueDateMonth: number): boolean {
            return returnDateMonth > dueDateMonth;
        }
