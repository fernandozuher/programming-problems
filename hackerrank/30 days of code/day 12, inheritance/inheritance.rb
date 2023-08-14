# https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

def main
    first_name, last_name, id = gets.split
    _ = gets.to_i # n_scores not used
    scores = gets.split.map(&:to_i)

    student = Student.new(first_name, last_name, id, scores)
    student.print_person           
    puts "Grade: #{student.calculate}"
end

    class Person
        def initialize(first_name, last_name, id)
            @first_name = first_name
            @last_name = last_name
            @id = id
        end
        
        def print_person
            puts "Name: #{@last_name}, #{@first_name} \nID: #{@id}"
        end
    end

        class Student < Person        
            def initialize(first_name, last_name, id, scores)
                super(first_name, last_name, id)
                @scores = scores
            end

            def calculate
                avg = @scores.sum / @scores.size

                if avg >= 90 && avg <= 100
                    return 'O'
                elsif avg >= 80 && avg < 90
                    return 'E'
                elsif avg >= 70 && avg < 80
                    return 'A'
                elsif avg >= 55 && avg < 70
                    return 'P'
                elsif avg >= 40 && avg < 55
                    return 'D'
                else
                    return 'T'
                end  
            end  
        end

main
