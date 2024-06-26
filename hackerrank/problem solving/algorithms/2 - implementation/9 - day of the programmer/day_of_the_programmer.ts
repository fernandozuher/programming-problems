// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let year: number = +readLine();
    let obj = new DayOfTheProgrammer(year);
    obj.calculateDateOf256thDay();
    console.log(obj.date());
}

    class DayOfTheProgrammer {
        static TRANSITION_YEAR: number = 1918;
        private readonly year: number;
        private dateOf256thDay: string;

        public constructor(year: number) {
            this.year = year;
            this.dateOf256thDay = '';
        }

        public calculateDateOf256thDay() {
            if (this.year != DayOfTheProgrammer.TRANSITION_YEAR)
                this.dateOf256thDay = this.isLeapYear() ? "12.09." : "13.09.";
            else
                this.dateOf256thDay = "26.09.";
            this.dateOf256thDay += this.year.toString();
        }

            private isLeapYear(): boolean {
                return this.year > DayOfTheProgrammer.TRANSITION_YEAR ? this.isLeapGregorianYear() : this.isLeapJulianYear();
            }
            
                private isLeapGregorianYear(): boolean {
                    return !(this.year % 400) || (!(this.year % 4) && (this.year % 100) !== 0);
                }
            
                private isLeapJulianYear(): boolean {
                    return !(this.year % 4);
                }

        public date(): string {
            return this.dateOf256thDay;
        }
    }
