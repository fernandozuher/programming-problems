// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let year = +readLine();
    let obj = new DayOfTheProgrammer(year);
    obj.calculateDateOf256thDay()
    console.log(obj.date());
}

    class DayOfTheProgrammer {
        static TRANSITION_YEAR = 1918;
        #year;
        #date;
    
        constructor(year) {
            this.#year = year;
            this.#date = '';
        }
    
        calculateDateOf256thDay() {
            if (this.#year !== DayOfTheProgrammer.TRANSITION_YEAR)
                this.#date = this.#isLeapYear() ? "12.09." : "13.09.";
            else
                this.#date = "26.09.";
            this.#date += this.#year.toString();
        }
        
            #isLeapYear() {
                return this.#year > DayOfTheProgrammer.TRANSITION_YEAR ? this.#isLeapGregorianYear() : this.#isLeapJulianYear();
            }
            
                #isLeapGregorianYear() {
                    return !(this.#year % 400) || (!(this.#year % 4) && this.#year % 100);
                }
            
                #isLeapJulianYear() {
                    return !(this.#year % 4);
                }
        
        date() {
            return this.#date;
        }
    }
