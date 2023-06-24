// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

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

function main() {
    const [_, N_TEST_CASES] = readAnIntArray();
    const WIDTH_MEASUREMENTS = readAnIntArray();
    const MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES = findMaximumAffordableWidthsVehiclesWhileReadTestCases(N_TEST_CASES, WIDTH_MEASUREMENTS);
    MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES.forEach(element => console.log(element));
}

    function readAnIntArray() {
        return readLine().split(" ").map(Number);
    }

    function findMaximumAffordableWidthsVehiclesWhileReadTestCases(nTestCases, widthMeasurements) {
        return Array(nTestCases).fill(0).map(element => maximumAffordableWidthVehicleInRange(widthMeasurements, readAnIntArray()));
    }

        function maximumAffordableWidthVehicleInRange(widthMeasurements, point) {
            return Math.min(...(widthMeasurements.slice(point[0], point[1] + 1)));
        }
