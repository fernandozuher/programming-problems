'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8')

let inputString: string = ''
let inputLines: string[] = []
let currentLine: number = 0

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n')
    inputString = ''

    main()
});

function readLine(): string {
    return inputLines[currentLine++]
}

function bubbleSort(a: number[]) {
        
    let numberOfSwaps = 0

    for (let _ in a) {
        for (let j = 0, N = a.length - 1; j < N; j++)

            if (a[j] > a[j + 1]) {
                let temp = a[j]
                a[j] = a[j + 1]
                a[j + 1] = temp
                numberOfSwaps++
            }

        if (!numberOfSwaps)
            break
    }
    return numberOfSwaps
}

function main() {
    readLine()

    const list = readLine().replace(/\s+$/g, '').split(' ').map(temp => parseInt(temp, 10))

    console.log(`Array is sorted in ${bubbleSort(list)} swaps.`)
    console.log(`First Element: ${list[0]}`)
    console.log(`Last Element: ${list[list.length - 1]}`)
}
