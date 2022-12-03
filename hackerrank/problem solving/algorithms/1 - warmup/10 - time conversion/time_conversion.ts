'use strict';

import { WriteStream, createWriteStream } from "fs";
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

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function timeConversion(time: string): string {
    let convertedTime: string = time.substring(0, 8);
    const hourString: string = time.substring(0, 2);
    const periodOfDay: string = time.substring(8, 9);

    if (hourString === "12") {
        if (periodOfDay === "A")
            convertedTime = convertedTime.replace(hourString, "00");
    }
    else if (periodOfDay === "P") {
        let hour: number = Number(hourString);
        hour += 12;
        convertedTime = convertedTime.replace(hourString, hour.toString());
    }
    return convertedTime;
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);
    const s: string = readLine();
    const result: string = timeConversion(s);
    ws.write(result + '\n');
    ws.end();
}
