# Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

def main
    _ = gets
    n_loaves_of_each_person = gets.split.map(&:to_i)
    puts find_min_loaves_to_satisfy_rules(n_loaves_of_each_person)
end

    def find_min_loaves_to_satisfy_rules(n_loaves_of_each_person)
        min_loaves_to_satisfy_rules = 0

        for i in 0...(n_loaves_of_each_person.size - 1)
            if n_loaves_of_each_person[i].odd?
                n_loaves_of_each_person[i] += 1
                n_loaves_of_each_person[i + 1] += 1
                min_loaves_to_satisfy_rules += 2
            end
        end

        n_loaves_of_each_person.last.odd? ? "NO" : min_loaves_to_satisfy_rules.to_s
    end

main
