// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

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
    let n: number = +readLine();
    let phoneBook: {[key: string]: string} = {};

    while (n-- > 0) {
        const [NAME, PHONE]: string[] = readLine().split(' ');
        phoneBook[NAME] = PHONE;
    }

    for (let name: string; name = readLine();) {
        if (phoneBook[name])
            console.log(`${name}=${phoneBook[name]}`)
        else
            console.log('Not found');
    }
}
