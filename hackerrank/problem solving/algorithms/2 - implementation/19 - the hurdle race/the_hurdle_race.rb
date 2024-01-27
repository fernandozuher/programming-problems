# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main
    n, maximum_height_can_jump = read_int_array
    hurdles_heights = read_int_array
    obj = Hurdle_race.new(hurdles_heights, maximum_height_can_jump)
    puts obj.doses
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class Hurdle_race
        attr_reader :doses

        def initialize(hurdles_heights, maximum_height_can_jump)
            @hurdles_heights = hurdles_heights
            @maximum_height_can_jump = maximum_height_can_jump
            @doses = 0
            hurdle_race
        end

            private def hurdle_race
                highest_hurdle = @hurdles_heights.max
                @doses = highest_hurdle > @maximum_height_can_jump ? highest_hurdle - @maximum_height_can_jump : 0
            end
    end

main
