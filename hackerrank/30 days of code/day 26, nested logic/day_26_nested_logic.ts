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

enum HackosFine {
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000
}

class DateThatWorks {
    #day: number
    #month: number
    #year: number

    constructor(day: number, month: number, year: number) {
        this.#day = day
        this.#month = month
        this.#year = year
    }

    getDay() {
        return this.#day
    }

    getMonth() {
        return this.#month
    }

    getYear() {
        return this.#year
    }
}

class BookReturnDate {
    #returnedRealDate: DateThatWorks
    #dueDate: DateThatWorks
    #fine: number

    private calculateFine() {
        if (this.#returnedRealDate.getYear() < this.#dueDate.getYear())
            this.#fine = 0
        else if (this.#returnedRealDate.getYear() === this.#dueDate.getYear()) {
            if (this.#returnedRealDate.getMonth() < this.#dueDate.getMonth())
                this.#fine = 0
            else if (this.#returnedRealDate.getMonth() === this.#dueDate.getMonth()) {
                if (this.#returnedRealDate.getDay() < this.#dueDate.getDay())
                    this.#fine = 0
                else
                    this.#fine = (this.#returnedRealDate.getDay() - this.#dueDate.getDay()) * HackosFine.HackosDaysFine
            }
            else
                this.#fine = (this.#returnedRealDate.getMonth() - this.#dueDate.getMonth()) * HackosFine.HackosMonthsFine
        } else
            this.#fine = HackosFine.HackosYearsFine
    }

    constructor(returnedRealDate: DateThatWorks, dueDate: DateThatWorks) {
        this.#returnedRealDate = returnedRealDate
        this.#dueDate = dueDate
        this.calculateFine()
    }

    getFine() {
        return this.#fine
    }
}

function formatStringDate(input: string) {
    const numbers: number[] = input.split(/\s+/g).map(Number)
    const date: DateThatWorks = new DateThatWorks(numbers[0], numbers[1], numbers[2])
    return date
}

function main() {
    const returnedRealDate: DateThatWorks = formatStringDate(readLine())
    const dueDate: DateThatWorks = formatStringDate(readLine())
    const bookReturnDateObj: BookReturnDate = new BookReturnDate(returnedRealDate, dueDate)
    console.log(bookReturnDateObj.getFine())
}
