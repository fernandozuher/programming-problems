# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main
    gets
    array = read_int_array

    records = BreakingBestAndWorstRecords.new(array)
    puts "#{records.most_points_records} #{records.least_points_records}"
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class BreakingBestAndWorstRecords

        def initialize(array)
            @scores = array
            @breaking_most_points_records = 0
            @breaking_least_points_records = 0
            breaking_records
        end

            private def breaking_records
                most_points = @scores.first
                least_points = @scores.first

                for score in @scores
                    if score > most_points 
                        most_points = score
                        @breaking_most_points_records += 1
                    elsif score < least_points
                        least_points = score
                        @breaking_least_points_records += 1
                    end
                end
            end

        def most_points_records
            @breaking_most_points_records
        end

        def least_points_records
            @breaking_least_points_records
        end 
    end

main
