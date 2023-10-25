// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

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

function main() {
    let n = +readLine();
    let names = findNamesWithGmailDomainsEmailsFromStdin(n);
    sortInPlaceAndPrintNames(names);
}

    function findNamesWithGmailDomainsEmailsFromStdin(n) {
        let names = [];
        while (n--) {
            let [name, emailId] = readLine().split(' ');
            if (emailId.includes('@gmail.com'))
                names.push(name);
        }
        return names;
    }

    function sortInPlaceAndPrintNames(names) {
        names.sort();
        for (const name of names)
            console.log(name);
    }
