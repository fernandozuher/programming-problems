# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main
    n = gets.to_i
    ranked = read_int_array
    ranked = remove_duplicates(ranked)

    n = gets.to_i
    player = read_int_array

    obj = Climbing_the_leaderboard.new(ranked, player)
    puts obj.player_rank
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def remove_duplicates(array)
       array.uniq
    end

    def binary_search_descending_order(array, low, high, key)
        if high >= low
            middle = low + ((high - low) / 2).to_i

            if key == array[middle]
                return middle
            elsif key > array[middle]
                return binary_search_descending_order(array, low, middle - 1, key)
            else
                return binary_search_descending_order(array, middle + 1, high, key)
            end
        end
        low
    end

    class Climbing_the_leaderboard
        attr_reader :player_rank

        def initialize(ranked, player)
            @ranked = ranked
            @player = player
            @player_rank = Array.new(@player.size)
            climbing_leaderboard
        end

            private def climbing_leaderboard
                @player.each_with_index do |player_score, i| 
                    index = binary_search_descending_order(@ranked, 0, @ranked.size - 1, player_score)
                    @player_rank[i] = index + 1
                end
            end
    end

main
