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
                for (let cityI = 0; cityI < this.#nCities; cityI++) {
                    const DISTANCE = this.#findMinDistanceBetweenCurrentCityAndNearestSpaceStation(cityI);
                    this.#maxDistanceFromSpaceStation = Math.max(this.#maxDistanceFromSpaceStation, DISTANCE);
                }
            }

                #findMinDistanceBetweenCurrentCityAndNearestSpaceStation(cityI) {
                    const ELEMENT = this.#findElementOrNearest(cityI, this.#citiesWithSpaceStation);
                    const MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION = Math.abs(cityI - ELEMENT);
                    return MIN_DISTANCE_BETWEEN_CITY_AND_NEAREST_SPACE_STATION;
                }

                    #findElementOrNearest(n, array) {
                        let max = array.length - 1;
                        let min = 0;

                        let minDistance = Number.MAX_SAFE_INTEGER;
                        let nearestElement = n;

                        while (min <= max) {
                            const MID = Math.trunc((min + max) / 2);

                            const DISTANCE = Math.abs(array[MID] - n);
                            if (DISTANCE < minDistance) {
                                nearestElement = array[MID];
                                minDistance = DISTANCE;
                            }

                            if (array[MID] == n)
                                return n;
                            else if (array[MID] > n)
                                max = MID - 1;
                            else
                                min = MID + 1;
                        }

                        return nearestElement;
                    }

        getMaxDistanceFromSpaceStation() {
            return this.#maxDistanceFromSpaceStation;
        }
    }
