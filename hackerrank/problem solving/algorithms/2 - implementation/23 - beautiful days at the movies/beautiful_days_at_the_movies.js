// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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


function main() {
    const [startingDayNumber, endingDayNumber, divisor] = readLineAsNumberArray();
    const beautifulDays = new BeautifulDays(startingDayNumber, endingDayNumber, divisor);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class BeautifulDays {
        #startingDayNumber;
        #endingDayNumber;
        #divisor;
        #nBeautifulDays;
        
        constructor(startingDayNumber, endingDayNumber, divisor) {
            this.#startingDayNumber = startingDayNumber;
            this.#endingDayNumber = endingDayNumber;
            this.#divisor = divisor;
            this.#nBeautifulDays = 0;
        
            this.#beautifulDays();
            this.printNBeautifulDays();
        }
        
            #beautifulDays() {
                for (let number = this.#startingDayNumber; number <= this.#endingDayNumber; number++) {
                    const reverseNumber = this.#generateReverseNumber(number);

                    if (this.#isDayBeautiful(number, reverseNumber))
                        this.#nBeautifulDays++;
                }
            }
            
                #generateReverseNumber(number) {
                    let reverseNumber = 0;
                    for (; number > 0; number = Math.trunc(number / 10))
                        reverseNumber = (reverseNumber * 10) + (number % 10);
                    return reverseNumber;
                }
                
                #isDayBeautiful(number, reverseNumber) {
                    const beautifulDay = Math.abs(number - reverseNumber) % this.#divisor == 0;
                    return beautifulDay;
                }
            
            printNBeautifulDays() {
                console.log(this.#nBeautifulDays);
            }
    }
