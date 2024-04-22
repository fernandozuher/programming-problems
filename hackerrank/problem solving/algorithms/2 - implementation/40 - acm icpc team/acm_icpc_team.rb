# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

def main
    attendees, topics = read_int_array
    binaries = read_binaries(attendees)
    obj = ACM_ICPC_TEAM.new(binaries)
    obj.find_maximum_subjects_and_teams_that_know_them
    p obj.maximum_subjects_known_by_teams, obj.teams_that_know_maximum_subjects
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def read_binaries(n)
        Array.new(n).map{gets.strip}
    end

    class ACM_ICPC_TEAM
        attr_reader :maximum_subjects_known_by_teams, :teams_that_know_maximum_subjects

        def initialize(binaries)
            @binaries = binaries
            @maximum_subjects_known_by_teams = 0
            @teams_that_know_maximum_subjects = 0
        end

        def find_maximum_subjects_and_teams_that_know_them
            @binaries[..-1].each_with_index { |previous, i|
                @binaries[i + 1..].each{ |current|
                    subjects_known_by_2_teams = count_subjects_known_by_2_teams(previous, current)
                    update_maximum_subjects_and_teams_that_know_them(subjects_known_by_2_teams)
                }
            }
        end

            def count_subjects_known_by_2_teams(binary1, binary2)
                (binary1.to_i(2) | binary2.to_i(2)).to_s(2).count('1')
            end

            def update_maximum_subjects_and_teams_that_know_them(subjects_known_by_2_teams)
                if subjects_known_by_2_teams > @maximum_subjects_known_by_teams
                    @maximum_subjects_known_by_teams = subjects_known_by_2_teams
                    @teams_that_know_maximum_subjects = 1
                elsif subjects_known_by_2_teams == @maximum_subjects_known_by_teams
                    @teams_that_know_maximum_subjects += 1
                end
            end
    end

main
