# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  Morfo.skip_input
  binaries = read_binaries(n)
  puts acm_team(binaries)
end

def read_binaries(n) = Morfo.read(n) { |s| s.to_i(2) }

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
