# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

def main
  _ = gets
  n_loaves_of_each_person = gets.split.map(&:to_i)
  if (min_loaves = find_min_loaves_to_satisfy_rules(n_loaves_of_each_person)) == -1
    puts "NO"
  else
    p min_loaves
  end
end

  def find_min_loaves_to_satisfy_rules(n_loaves_of_each_person)
    min_loaves_to_satisfy_rules = 0
    n_loaves_of_each_person[...-1].each_index { |i|
      if n_loaves_of_each_person[i].odd?
        n_loaves_of_each_person[i + 1] += 1
        min_loaves_to_satisfy_rules += 2
      end
    }
    n_loaves_of_each_person.last.odd? ? -1 : min_loaves_to_satisfy_rules
  end

main
