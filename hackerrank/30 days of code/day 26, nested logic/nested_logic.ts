// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

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
    let returnedRealDate: DateThatWorks = formatStringDate(readLine());
    let dueDate: DateThatWorks = formatStringDate(readLine());
    let bookReturnDateObj: BookReturnDate = new BookReturnDate(returnedRealDate, dueDate);
    console.log(bookReturnDateObj.fine());
}

    function formatStringDate(input: string) {
        let numbers: number[] = input.split(' ').map(Number);
        let date: DateThatWorks = new DateThatWorks(numbers[0], numbers[1], numbers[2]);
        return date;
    }

    class DateThatWorks {
        private dayValue: number;
        private monthValue: number;
        private yearValue: number;

        public constructor(day: number, month: number, year: number) {
            this.dayValue = day;
            this.monthValue = month;
            this.yearValue = year;
        }

        public day(): number {
            return this.dayValue;
        }

        public month(): number {
            return this.monthValue;
        }

        public year(): number {
            return this.yearValue;
        }
    }

    class BookReturnDate {
        private returnedRealDate: DateThatWorks | null;
        private dueDate: DateThatWorks | null;
        private fineAmount: number | null;

        public constructor(returnedRealDate: DateThatWorks, dueDate: DateThatWorks) {
            this.returnedRealDate = returnedRealDate;
            this.dueDate = dueDate;
            this.calculateFine();
        }

            private calculateFine() {
                if (this.returnedRealDate.year() < this.dueDate.year())
                    this.fineAmount = 0;
                else if (this.returnedRealDate.year() === this.dueDate.year()) {
                    if (this.returnedRealDate.month() < this.dueDate.month())
                        this.fineAmount = 0;
                    else if (this.returnedRealDate.month() === this.dueDate.month()) {
                        if (this.returnedRealDate.day() < this.dueDate.day())
                            this.fineAmount = 0;
                        else
                            this.fineAmount = (this.returnedRealDate.day() - this.dueDate.day()) * HackosFine.HackosDaysFine;
                    }
                    else
                        this.fineAmount = (this.returnedRealDate.month() - this.dueDate.month()) * HackosFine.HackosMonthsFine;
                } else
                    this.fineAmount = HackosFine.HackosYearsFine;
            }

        public fine(): number {
            return this.fineAmount;
        }
    }

        enum HackosFine {
            HackosDaysFine = 15,
            HackosMonthsFine = 500,
            HackosYearsFine = 10000
        }
