// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let time = readLine();
    console.log(timeConversion(time));
}

    function timeConversion(time) {
        let convertedTime = time.substring(0, 8);
        let hour = time.substring(0, 2);
        let dayPeriod = time.substring(8, 9);

        if (hour === "12") {
            if (dayPeriod === "A") {
                let midnight = "00";
                convertedTime = convertedTime.replace(hour, midnight);
            }
        } else if (dayPeriod === "P") {
            let newHour = Number(hour);
            newHour += 12;
            convertedTime = convertedTime.replace(hour, newHour.toString());
        }

        return convertedTime;
    }
