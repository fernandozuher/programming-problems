# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main
    n = gets.to_i
    cancelled_classes = Array.new(n)

    n.times do |i|
        n_students_arrival_time, cancellation_threshold = read_int_array
        students_arrival_time = read_int_array
        obj = AngryProfessor.new(students_arrival_time, cancellation_threshold)
        cancelled_classes[i] = obj.cancelled_class
    end

    for cancelled in cancelled_classes
        puts cancelled ? "YES" : "NO"
    end
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class AngryProfessor
        attr_reader :cancelled_class

        def initialize(students_arrival_time, cancellation_threshold)
            @students_arrival_time = students_arrival_time
            @cancellation_threshold = cancellation_threshold
            @cancelled_class = false
            check_if_class_is_cancelled
        end

            private def check_if_class_is_cancelled
               @cancelled_class = count_early_arrival_time < @cancellation_threshold
            end

                private def count_early_arrival_time
                    early_arrival_time_count = 0

                    for arrival_time in @students_arrival_time
                        if arrival_time <= 0
                            early_arrival_time_count += 1
                        end
                    end

                    early_arrival_time_count
                end
    end

main
