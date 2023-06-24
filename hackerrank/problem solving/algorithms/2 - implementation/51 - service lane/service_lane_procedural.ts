// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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
    const [_, N_TEST_CASES]: Array<number> = readAnIntArray();
    const WIDTH_MEASUREMENTS: Array<number> = readAnIntArray();
    const MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES: Array<number> = findAffordableMaximumWidthsVehiclesWhileReadTestCases(N_TEST_CASES, WIDTH_MEASUREMENTS);
    MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES.forEach(element => console.log(element));
}

    function readAnIntArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    function findAffordableMaximumWidthsVehiclesWhileReadTestCases(nTestCases: number, widthMeasurements: Array<number>): Array<number> {
        return Array(nTestCases).fill(0).map(element => maximumAffordableWidthVehicleInRange(widthMeasurements, readAnIntArray()));
    }

        function maximumAffordableWidthVehicleInRange(widthMeasurements: Array<number>, point: Array<number>): number {
            return Math.min(...(widthMeasurements.slice(point[0], point[1] + 1)));
        }
