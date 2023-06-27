// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

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
    const [N_CITIES, _] = readAnIntArray()
    const CITIES_WITH_SPACE_STATION = readAnIntArray();
    console.log(findMaxDistanceFromSpaceStation(N_CITIES, CITIES_WITH_SPACE_STATION));
}

    function readAnIntArray() {
        return readLine().split(" ").map(Number);
    }

    function findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation) {
        citiesWithSpaceStation.sort((a, b) => a - b);
        const FIRST_CITY = 0;
        let maxDistance = citiesWithSpaceStation[0] - FIRST_CITY;
        const SIZE = citiesWithSpaceStation.length;

        for (let i = 1, previousCity = citiesWithSpaceStation[0]; i < SIZE; i++) {
            const DISTANCE = calculateDistanceBetweenCities(citiesWithSpaceStation[i], previousCity);
            maxDistance = Math.max(maxDistance, DISTANCE);
            previousCity = citiesWithSpaceStation[i];
        }

        const LAST_CITY = nCities - 1
        const LAST_CITY_WITH_SPACE_STATION = citiesWithSpaceStation[SIZE - 1]
        if (!hasLastCitySpaceStation(LAST_CITY, LAST_CITY_WITH_SPACE_STATION)) {
            const DISTANCE = calculateDistanceOfLastCity(LAST_CITY, LAST_CITY_WITH_SPACE_STATION);
            maxDistance = Math.max(maxDistance, DISTANCE);
        }

        return maxDistance;
    }

        function calculateDistanceBetweenCities(cityWithSpaceStation, previousCity) {
            return Math.trunc((cityWithSpaceStation - previousCity) / 2);
        }

        function hasLastCitySpaceStation(lastCity, lastCityWithSpaceStation) {
            return lastCity == lastCityWithSpaceStation;
        }

        function calculateDistanceOfLastCity(lastCity, lastCityWithSpaceStation) {
            return lastCity - lastCityWithSpaceStation;
        }
