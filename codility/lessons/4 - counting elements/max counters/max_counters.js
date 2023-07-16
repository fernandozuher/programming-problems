// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

function solution(nCounters, array) {
    let foundMaxCounter = false;
    let max = 0, currentMax = 0;
    let counters = {};

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

    function defaultZeroValues() {
        const COUNTERS = {};
        const FOUND_MAX_COUNTER = false;
        const CURRENT_MAX = 0;
        return [COUNTERS, FOUND_MAX_COUNTER, CURRENT_MAX];
    }

    function incrementCounter(counter, counters) {
        if (!(counter in counters))
            counters[counter] = 0;
        counters[counter]++;
    }

    function compouseResult(foundMaxCounter, max, nCounters, counters) {
        const INITIAL_VALUE = (foundMaxCounter || max > 0) ? max : 0;
        const RESULT = Array(nCounters + 1).fill(INITIAL_VALUE);

        if (!foundMaxCounter)
            Object.entries(counters).forEach(entry => {
                const [KEY, VALUE] = entry;
                RESULT[KEY] += VALUE;
            });

        return RESULT.slice(1, nCounters + 1);
    }
