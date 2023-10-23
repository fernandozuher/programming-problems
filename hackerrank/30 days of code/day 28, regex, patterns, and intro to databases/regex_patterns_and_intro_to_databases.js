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

function extractEmailDomain(emailID) {
    const indexArroba = emailID.indexOf('@');
    const emailDomain = emailID.substring(indexArroba);
    return emailDomain;
}

function checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames) {
    if (emailDomain.localeCompare("@gmail.com") === 0)
        firstNames.push(firstName);
}

function sortNamesOfGmailEmails(firstNames) {
    firstNames.sort();
}

function printFirstGmailNames(firstNames) {
    for (const firstName of firstNames)
        console.log(firstName);
}

function main() {
    const N = parseInt(readLine().trim(), 10);
    let firstNames = [];

    for (let NItr = 0; NItr < N; NItr++) {
        const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');
        const firstName = firstMultipleInput[0];
        const emailID = firstMultipleInput[1];

        const emailDomain = extractEmailDomain(emailID);
        checkAndInsertNameIfEmailDomainGmail(firstName, emailDomain, firstNames);
    }
    sortNamesOfGmailEmails(firstNames);
    printFirstGmailNames(firstNames);
}
