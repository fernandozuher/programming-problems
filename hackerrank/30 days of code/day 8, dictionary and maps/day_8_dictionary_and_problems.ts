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
    const n = +readLine()
    let phoneBook: any = []

    for (let i = 1; i <= n; i++) {
        const [name, phone] = readLine().split(" ")
        phoneBook[name] = phone
    }

    for (let query; query = readLine(); )
        if (phoneBook.hasOwnProperty(query))
            console.log(`${query}=${phoneBook[query]}`)
        else
            console.log("Not found")
}
