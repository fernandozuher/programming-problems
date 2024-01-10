# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array
    obj = SalesByMatch.new(array)
    puts obj.pairs
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class SalesByMatch
        attr_reader :pairs

        def initialize(socks)
            @socks = socks
            @pairs = 0
            sockMerchant
        end

            private def sockMerchant
                socksPairing = Hash.new
                for sock in @socks
                    if socksPairing[sock]
                        @pairs += 1
                    end
                    socksPairing[sock] = !socksPairing[sock]
                end
            end
    end

main
