# https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

def main():
    input()
    steps = input()
    print(counting_valleys(steps))


def counting_valleys(steps):
    valleys = 0
    current_altitude = 0

    for step in steps:
        was_below_sea_level = current_altitude < 0
        current_altitude += -1 if step == 'D' else 1
        if is_in_sea_level_from_valley := was_below_sea_level and current_altitude == 0:
            valleys += 1

    return valleys


if __name__ == '__main__':
    main()
