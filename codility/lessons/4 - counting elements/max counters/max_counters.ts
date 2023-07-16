// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

interface INumberIndex {
    [key: number]: number
}

function solution(nCounters: number, array: number[]): number[] {
    let foundMaxCounter: boolean = false;
    let max: number = 0, currentMax: number = 0;
    let counters: INumberIndex = {};

    for (let element of array)
        if (element <= nCounters) {
            if (foundMaxCounter)
                [counters, foundMaxCounter, currentMax] = defaultZeroValues();

            incrementCounter(element, counters);
            if (counters[element] > currentMax)
                currentMax++;
        }
        else if (!foundMaxCounter) {
            max += currentMax;
            foundMaxCounter = true;
        }

    return compouseResult(foundMaxCounter, max, nCounters, counters);
}

    function defaultZeroValues(): any[] {
        const COUNTERS: INumberIndex = {};
        const FOUND_MAX_COUNTER: boolean = false;
        const CURRENT_MAX: number = 0;
        return [COUNTERS, FOUND_MAX_COUNTER, CURRENT_MAX];
    }

    function incrementCounter(element: number, counters: INumberIndex) {
        if (!(element in counters))
            counters[element] = 0;
        counters[element]++;
    }

    function compouseResult(foundMaxCounter: boolean, max: number, nCounters: number, counters: INumberIndex): number[] {
        const INITIAL_VALUE: number = (foundMaxCounter || max > 0) ? max : 0;
        const RESULT: number[] = Array(nCounters + 1).fill(INITIAL_VALUE);

        if (!foundMaxCounter)
            Object.entries(counters).forEach(entry => {
                const [KEY, VALUE]: number[] = entry;
                RESULT[KEY] += VALUE;
            });

        return RESULT.slice(1, nCounters + 1);
    }
