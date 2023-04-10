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

    const OBJ: LibraryFine = new LibraryFine(RETURN_DATE, DUE_DATE);
    const FINE: number = OBJ.getFine();
    console.log(FINE);
}

    function readADate(): DateThatWorks {
        const [DAY, MONTH, YEAR]: Array<number> = readLine().split(" ").map(Number);
        const DATE: DateThatWorks = new DateThatWorks(DAY, MONTH, YEAR);
        return DATE;
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

    class LibraryFine {
        private _returnDate: DateThatWorks;
        private _dueDate: DateThatWorks;
        private _fine: number;

        constructor(returnDate: DateThatWorks, dueDate: DateThatWorks) {
            this._returnDate = returnDate;
            this._dueDate = dueDate;
            this._fine = 0;

            this._calculateFine();
        }

            private _calculateFine() {
                if (this._wereBooksReturnedInTime())
                    this._fine = 0;
                else if (this._isReturnDateLateInMoreThanOrEqualToOneYear())
                    this._fine = HackosFine.HackosYearsFine;
                else if (this._isReturnDateLateInMoreThanOrEqualToOneMonth())
                    this._fine = (this._returnDate.getMonth() - this._dueDate.getMonth()) * HackosFine.HackosMonthsFine;
                else
                    this._fine = (this._returnDate.getDay() - this._dueDate.getDay()) * HackosFine.HackosDaysFine;
            }

                private _wereBooksReturnedInTime(): boolean {
                    if ((this._returnDate.getYear() < this._dueDate.getYear()) ||
                            ((this._returnDate.getYear() === this._dueDate.getYear()) && (this._returnDate.getMonth() < this._dueDate.getMonth())) ||
                            ((this._returnDate.getYear() === this._dueDate.getYear()) && (this._returnDate.getMonth() === this._dueDate.getMonth()) && (this._returnDate.getDay() <= this._dueDate.getDay()))
                       )
                        return true;
                    return false;
                }

                private _isReturnDateLateInMoreThanOrEqualToOneYear(): boolean {
                    return this._returnDate.getYear() > this._dueDate.getYear();
                }

                private _isReturnDateLateInMoreThanOrEqualToOneMonth(): boolean {
                    return this._returnDate.getMonth() > this._dueDate.getMonth();
                }

        public getFine(): number {
            return this._fine;
        }
    }
