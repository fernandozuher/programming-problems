# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main
  attendees, _ = read_numbers
  binaries = read_binaries(attendees)
  puts acm_team(binaries)
end

def read_numbers
  gets.split.map(&:to_i)
end

def read_binaries(n)
  n.times.map { gets.strip }
end

def acm_team(binaries)
  max_subjects = 0
  teams_with_max = 0

  binaries.combination(2).each do |a, b|
    known_subjects = count_subjects_known_by_2_teams(a, b)

    if known_subjects > max_subjects
      max_subjects = known_subjects
      teams_with_max = 1
    elsif known_subjects == max_subjects
      teams_with_max += 1
    end
  end

  [max_subjects, teams_with_max]
end

def count_subjects_known_by_2_teams(a, b)
  (a.to_i(2) | b.to_i(2)).to_s(2).count('1')
end

main if __FILE__ == $PROGRAM_NAME
