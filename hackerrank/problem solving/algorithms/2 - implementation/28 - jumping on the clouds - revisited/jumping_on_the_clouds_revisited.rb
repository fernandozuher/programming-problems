# https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main
    n, jump_length = read_int_array
    array = read_int_array
    obj = JumpingOnTheClouds.new(array, jump_length)
    puts obj.remaining_energy
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class JumpingOnTheClouds
        @clouds
        @jump_length
        @remaining_energy

        attr_reader :remaining_energy

        def initialize(clouds, jump_length)
            @clouds = clouds
            @jump_length = jump_length
            @remaining_energy = 100
            calculate_remaining_energy
        end

            private def calculate_remaining_energy
                cloud_index = 0

                while true
                    @remaining_energy -= spent_energy_according_to_type_of_cloud(@clouds[cloud_index])
                    cloud_index = generate_new_cloud_index(cloud_index)
                    if is_cloud_index_back_to_first_cloud(cloud_index)
                        break
                    end
                end
            end

                private def spent_energy_according_to_type_of_cloud(cloud_type)
                    cloud_type == 0 ? 1 : 3
                end

                private def generate_new_cloud_index(cloud_index)
                    (cloud_index + @jump_length) % @clouds.size
                end

                private def is_cloud_index_back_to_first_cloud(cloud_index)
                    cloud_index == 0
                end
    end

main
