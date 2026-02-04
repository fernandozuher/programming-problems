# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main
  n, _ = read_numbers
  binaries = read_binaries(n)
  puts acm_team(binaries)
end

def read_numbers
  gets.split.map!(&:to_i)
end

def read_binaries(n)
  n.times.map { gets.strip.to_i(2) }
end

def acm_team(binaries)
  max_subjects = 0
  teams_with_max = 0

  binaries.combination(2).each do |a, b|
    known_subjects = (a | b).to_s(2).count('1')

    if known_subjects > max_subjects
      max_subjects = known_subjects
      teams_with_max = 1
    elsif known_subjects == max_subjects
      teams_with_max += 1
    end
  end

  [max_subjects, teams_with_max]
end

main if __FILE__ == $0
