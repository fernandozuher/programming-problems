// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// Baseline 2022

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    const [nCities, _] = readIntArray();
    let citiesWithSpaceStation = readIntArray().sort((a, b) => a - b);
    console.log(findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation) {
        let maxDistanceFromSpaceStation, previousCity;
        maxDistanceFromSpaceStation = previousCity = citiesWithSpaceStation[0];

        citiesWithSpaceStation.slice(1).forEach(cityWithSpaceStation => {
            let distanceBetweenCities = Math.trunc((cityWithSpaceStation - previousCity) / 2);
            maxDistanceFromSpaceStation = Math.max(maxDistanceFromSpaceStation, distanceBetweenCities);
            previousCity = cityWithSpaceStation;
        });

        let hasLastCitySpaceStation = nCities - 1 === citiesWithSpaceStation.findLast();
        if (!hasLastCitySpaceStation) {
            let distanceOfLastCity = nCities - 1 - citiesWithSpaceStation.findLast();
            maxDistanceFromSpaceStation = Math.max(maxDistanceFromSpaceStation, distanceOfLastCity);
        }

        return maxDistanceFromSpaceStation;
    }
