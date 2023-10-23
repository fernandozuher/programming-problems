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

function extractEmailDomain(emailID: string): string {
    const indexArroba: number = emailID.indexOf('@');
    const emailDomain: string = emailID.substring(indexArroba);
    return emailDomain;
}

function checkAndInsertNameIfEmailDomainGmail(firstName: string, emailDomain: string, firstNames: string[]) {
    if (emailDomain.localeCompare("@gmail.com") === 0)
        firstNames.push(firstName);
}

function sortNamesOfGmailEmails(firstNames: string[]) {
    firstNames.sort();
}

function printFirstGmailNames(firstNames: string[]) {
    for (const firstName of firstNames)
        console.log(firstName);
}

function main() {
    const N: number = parseInt(readLine().trim(), 10);
    let firstNames: string[] = [];

    for (let NItr: number = 0; NItr < N; NItr++) {
        const firstMultipleInput: string[] = readLine().replace(/\s+$/g, '').split(' ');
        const firstName: string = firstMultipleInput[0];
        const emailID: string = firstMultipleInput[1];

        const emailDomain: string = extractEmailDomain(emailID);
        checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames);
    }
    sortNamesOfGmailEmails(firstNames);
    printFirstGmailNames(firstNames);
}
