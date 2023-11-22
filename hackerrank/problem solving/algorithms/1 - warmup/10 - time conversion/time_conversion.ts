// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

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
    let time: string = readLine();
    console.log(timeConversion(time));
}

    function timeConversion(time: string): string {
        let convertedTime: string = time.substring(0, 8);
        let hour: string = time.substring(0, 2);
        let dayPeriod: string = time.substring(8, 9);

        if (hour === "12") {
            if (dayPeriod === "A") {
                let midnight: string = "00";
                convertedTime = convertedTime.replace(hour, midnight);
            }
        } else if (dayPeriod === "P") {
            let newHour: number = Number(hour);
            newHour += 12;
            convertedTime = convertedTime.replace(hour, newHour.toString());
        }

        return convertedTime;
    }
