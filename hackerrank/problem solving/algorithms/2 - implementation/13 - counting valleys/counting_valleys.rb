# https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

def main
    n = gets.to_i
    array = gets
    obj = Count_valleys.new(array)
    puts obj.traversed_valleys
end

    class Count_valleys

        attr_reader :traversed_valleys

        def initialize(steps)
            @steps = steps
            @traversed_valleys = 0
            counting_valleys
        end

            private def counting_valleys
                current_altitude = 0

                for step in @steps.split('')
                    was_travessing_a_valley = current_altitude < 0
                    current_altitude += step == 'D' ? -1 : 1
                    
                    if is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude)
                        @traversed_valleys += 1
                    end
                end
            end

            private def is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude)
                was_travessing_a_valley && current_altitude == 0
            end
    end

main
