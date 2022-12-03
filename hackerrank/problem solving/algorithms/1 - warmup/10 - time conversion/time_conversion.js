'use strict';
const fs = require('fs');
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
/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
function timeConversion(time) {
    let convertedTime = time.substring(0, 8);
    const hourString = time.substring(0, 2);
    const periodOfDay = time.substring(8, 9);

    if (hourString === "12") {
        if (periodOfDay === "A")
            convertedTime = convertedTime.replace(hourString, "00");
    }
    else if (periodOfDay === "P") {
        let hour = Number(hourString);
        hour += 12;
        convertedTime = convertedTime.replace(hourString, hour.toString());
    }
    return convertedTime;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    const s = readLine();
    const result = timeConversion(s);
    ws.write(result + '\n');
    ws.end();
}