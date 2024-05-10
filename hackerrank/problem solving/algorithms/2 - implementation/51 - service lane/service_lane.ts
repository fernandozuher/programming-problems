// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    const [_, n]: number[] = readIntArray();
    findMaximumAffordableWidthsVehiclesWhileReadTestCases(n, readIntArray()).forEach(x => console.log(x));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function findMaximumAffordableWidthsVehiclesWhileReadTestCases(n: number, widthMeasurements: number[]): number[] {
        return Array(n).fill(0).map(_ => maximumAffordableWidthVehicleInRange(widthMeasurements, readIntArray()));
    }

        function maximumAffordableWidthVehicleInRange(widthMeasurements: number[], point: number[]): number {
            return Math.min(...(widthMeasurements.slice(point[0], point[1] + 1)));
        }
