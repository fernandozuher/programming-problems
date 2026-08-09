# https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input_ln()
    steps = morfo.read(str)
    print(counting_valleys(steps))


# n: length of steps
# T: O(n)
# S: O(1) extra space
def counting_valleys(steps):
    valleys = 0
    current_altitude = 0

    for step in steps:
        was_below_sea_level = current_altitude < 0
        current_altitude += -1 if step == 'D' else 1
        is_in_sea_level_from_valley = was_below_sea_level and current_altitude == 0
        if is_in_sea_level_from_valley:
            valleys += 1

    return valleys


if __name__ == '__main__':
    main()
