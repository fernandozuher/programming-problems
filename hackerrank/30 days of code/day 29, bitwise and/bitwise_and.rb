# https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

def main
    n = gets.to_i
    n.times do
        count, lim = gets.split.map(&:to_i)
        puts bitwise_and(count, lim)
    end
end

    def bitwise_and(n, k)
        maximum_value_less_than_k = 0

        for i in 1..n
            for j in (i+1)..n
                operation = i & j

                if operation < k && operation > maximum_value_less_than_k
                    if operation == k-1
                        return operation
                    else
                        maximum_value_less_than_k = operation
                    end
                end
            end
        end

        maximum_value_less_than_k
    end

main
