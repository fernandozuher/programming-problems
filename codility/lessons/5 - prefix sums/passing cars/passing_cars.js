// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

function solution(array) {
    let passingCarsPairs = 0;

    for (let i = 0, east = 0, west, passingCarsLimit = 1000000000; i < array.length; i++)
        if ((west = array[i])) {
            if ((passingCarsPairs += east) > passingCarsLimit)
                return -1;
        } else
            east++;

    return passingCarsPairs;
}
