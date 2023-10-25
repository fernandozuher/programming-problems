// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

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
    let names: string[] = findNamesWithGmailDomainsEmailsFromStdin(n);
    sortInPlaceAndPrintNames(names);
}

    function findNamesWithGmailDomainsEmailsFromStdin(n: number): string[] {
        let names: string[] = [];
        while (n--) {
            let [name, emailId] = readLine().split(' ');
            if (emailId.includes('@gmail.com'))
                names.push(name);
        }
        return names;
    }

    function sortInPlaceAndPrintNames(names: string[]) {
        names.sort();
        for (const name of names)
            console.log(name);
    }
