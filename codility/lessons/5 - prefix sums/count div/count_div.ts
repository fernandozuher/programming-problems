// Source: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

function solution(begin: number, end: number, divisor: number): number {
    let dividend: number = (end - begin) / divisor | 0;

    if (!(begin % divisor) || !(end % divisor)
            || (begin < divisor && (end % divisor + divisor - begin) < divisor))
        dividend++;

    return dividend;
}
