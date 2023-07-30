# https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

def main
    n_tests = gets.to_i

    n_tests.times {
        age = gets.to_i
        p = Person.new(age)
        p.am_i_old

        3.times { p.year_passes }
        p.am_i_old

        puts ""
    }
end

    class Person
        def initialize(initial_age)
            if initial_age < 0
                @age = 0
                puts "Age is not valid, setting age to 0."
            else
                @age = initial_age
            end
        end

        def am_i_old
            if @age < 13
                puts "You are young."
            elsif @age >= 13 and @age < 18
                puts "You are a teenager."
            else
                puts "You are old."
            end
        end

        def year_passes
            @age += 1
        end
    end

main
