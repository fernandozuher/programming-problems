// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

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

class Result {    
    #scores;
    #breakingMostPointsRecords;
    #breakingLeastPointsRecords;

    constructor(setA) {
        this.#scores = [...setA];
        this.#breakingMostPointsRecords = 0;
        this.#breakingLeastPointsRecords = 0;
        this.#breakingRecords();
        this.printResult();
    }

	    #breakingRecords() {
			let mostPoints = this.#scores[0];
			let leastPoints = this.#scores[0];

			for (let score of this.#scores)
				if (score > mostPoints) {
					mostPoints = score;
					this.#breakingMostPointsRecords++;
				} else if (score < leastPoints) {
					leastPoints = score;
					this.#breakingLeastPointsRecords++;
				}
		}
    
        printResult() {
            console.log(`${this.#breakingMostPointsRecords} ${this.#breakingLeastPointsRecords}`);
        }
}

function readLineAsNumericArray() {
    const numbers = readLine().split(" ").map(Number);
    return numbers;
}

function main() {
    readLineAsNumericArray();
    const setA = readLineAsNumericArray();
    const result = new Result(setA);
}
