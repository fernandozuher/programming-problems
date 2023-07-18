# Source: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

def solution(range_begin, range_end, divisor)
    dividend = ((range_end - range_begin) / divisor).truncate

    if range_begin % divisor == 0 or range_end % divisor == 0 \
        or (range_begin < divisor and (range_end % divisor + divisor - range_begin) < divisor)
        dividend += 1
    end

   dividend
end
