# https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main():

    n, jump_length = read_int_array()
    array = read_int_array()
    obj = JumpingOnTheClouds(array, jump_length)
    print(obj.remaining_energy())


def read_int_array():

    return list(map(int, input().split()))


class JumpingOnTheClouds:

    def __init__(self, clouds, jump_length):

        self.clouds = clouds
        self._jump_length = jump_length
        self._energy = 100
        self._calculate_remaining_energy()


    def _calculate_remaining_energy(self):

        cloud_index = 0
        while True:
            self._energy -= self._spent_energy_according_to_type_of_cloud(self.clouds[cloud_index])
            cloud_index = self._generate_new_cloud_index(cloud_index)
            if self._is_cloud_index_back_to_first_cloud(cloud_index):
                break


    def _spent_energy_according_to_type_of_cloud(self, cloud_type):

        return 1 if cloud_type == 0 else 3


    def _generate_new_cloud_index(self, cloud_index):

        return (cloud_index + self._jump_length) % len(self.clouds)


    def _is_cloud_index_back_to_first_cloud(self, cloud_index):

        return cloud_index == 0


    def remaining_energy(self):

        return self._energy


if __name__ == '__main__':
    main()
