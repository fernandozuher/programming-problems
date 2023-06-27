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
    const OBJ = new FlatlandSpaceStations(N_CITIES, CITIES_WITH_SPACE_STATION);
    console.log(OBJ.getMaxDistanceFromSpaceStation());
}

    function readAnIntArray() {
        return readLine().split(" ").map(Number);
    }

    class FlatlandSpaceStations {
        #nCities;
        #citiesWithSpaceStation;
        #maxDistanceFromSpaceStation;

        constructor(nCities, citiesWithSpaceStation) {
            this.#nCities = nCities;
            this.#citiesWithSpaceStation = citiesWithSpaceStation;
            this.#maxDistanceFromSpaceStation = 0;

            this.#citiesWithSpaceStation.sort((a, b) => a - b);
            this.#findMaxDistanceFromSpaceStation();
        }

            #findMaxDistanceFromSpaceStation() {
                const FIRST_CITY = 0;
                this.#maxDistanceFromSpaceStation = this.#citiesWithSpaceStation[0] - FIRST_CITY;
                const SIZE = this.#citiesWithSpaceStation.length;

                for (let i = 1, previousCity = this.#citiesWithSpaceStation[0]; i < SIZE; i++) {
                    const DISTANCE = this.#calculateDistanceBetweenCities(this.#citiesWithSpaceStation[i], previousCity);
                    this.#maxDistanceFromSpaceStation = Math.max(this.#maxDistanceFromSpaceStation, DISTANCE);
                    previousCity = this.#citiesWithSpaceStation[i];
                }

                if (!this.#hasLastCitySpaceStation()) {
                    const DISTANCE = this.#calculateDistanceOfLastCity();
                    this.#maxDistanceFromSpaceStation = Math.max(this.#maxDistanceFromSpaceStation, DISTANCE);
                }
            }

                #calculateDistanceBetweenCities(cityWithSpaceStation, previousCity) {
                    return Math.trunc((cityWithSpaceStation - previousCity) / 2);
                }

                #hasLastCitySpaceStation() {
                    return this.#nCities-1 == this.#citiesWithSpaceStation[this.#citiesWithSpaceStation.length - 1]
                }

                #calculateDistanceOfLastCity() {
                    return this.#nCities-1 - this.#citiesWithSpaceStation[this.#citiesWithSpaceStation.length - 1]
                }


        getMaxDistanceFromSpaceStation() {
            return this.#maxDistanceFromSpaceStation;
        }
    }
