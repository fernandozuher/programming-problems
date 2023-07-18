# Source: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

def solution(begin, end, divisor):
    dividend = int((end - begin) / divisor)

    if not(begin % divisor) or not(end % divisor) \
        or (begin < divisor and (end % divisor + divisor - begin) < divisor):
        dividend += 1

    return dividend
