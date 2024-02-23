// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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

//////////////////////////////////////////////////

const HackosFine = Object.freeze({
    HackosDaysFine: 15,
    HackosMonthsFine: 500,
    HackosYearsFine: 10000
})

class DateThatWorks {
    private dayValue: number;
    private monthValue: number;
    private yearValue: number;

    constructor(day: number, month: number, year: number) {
        this.dayValue = day;
        this.monthValue = month;
        this.yearValue = year;
    }

    day(): number {
        return this.dayValue;
    }

    month(): number {
        return this.monthValue;
    }

    year(): number {
        return this.yearValue;
    }
}

function main() {
    let returnDate: DateThatWorks = readADate();
    let dueDate: DateThatWorks = readADate();
    let obj = new LibraryFine(returnDate, dueDate);
    console.log(obj.fine());
}

    function readADate(): DateThatWorks {
        let [day, month, year]: number[] = readLine().split(' ').map(Number);
        return new DateThatWorks(day, month, year);
    }

    class LibraryFine {
        private returnDate: DateThatWorks;
        private dueDate: DateThatWorks;
        private fineAmount: number;

        constructor(returnDate: DateThatWorks, dueDate: DateThatWorks) {
            this.returnDate = returnDate;
            this.dueDate = dueDate;
            this.fineAmount = 0;
            this.calculateFine();
        }

            private calculateFine() {
                if (this.wereBooksReturnedInTime())
                    this.fineAmount = 0;
                else if (this.isReturnDateLateInMoreThanOrEqualToOneYear())
                    this.fineAmount = HackosFine.HackosYearsFine;
                else if (this.isReturnDateLateInMoreThanOrEqualToOneMonth())
                    this.fineAmount = (this.returnDate.month() - this.dueDate.month()) * HackosFine.HackosMonthsFine;
                else
                    this.fineAmount = (this.returnDate.day() - this.dueDate.day()) * HackosFine.HackosDaysFine;
            }

                private wereBooksReturnedInTime(): boolean {
                    if ((this.returnDate.year() < this.dueDate.year()) ||
                            ((this.returnDate.year() === this.dueDate.year()) && (this.returnDate.month() < this.dueDate.month())) ||
                            ((this.returnDate.year() === this.dueDate.year()) && (this.returnDate.month() === this.dueDate.month()) && (this.returnDate.day() <= this.dueDate.day()))
                       )
                        return true;
                    return false;
                }

                private isReturnDateLateInMoreThanOrEqualToOneYear(): boolean {
                    return this.returnDate.year() > this.dueDate.year();
                }

                private isReturnDateLateInMoreThanOrEqualToOneMonth(): boolean {
                    return this.returnDate.month() > this.dueDate.month();
                }

        public fine(): number {
            return this.fineAmount;
        }
    }
