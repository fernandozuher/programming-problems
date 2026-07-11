# https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

def main():
    time = input()
    print(to_24_hour_time(time))


# T: O(1)
# S: O(1) extra space
def to_24_hour_time(hour_12):
    hour_24 = hour_12[:8]
    hour = hour_12[:2]
    day_period = hour_12[8:9]

    if (hour == '12' and day_period == 'A') or (hour != '12' and day_period == 'P'):
        new_hour = gen_new_hour(day_period, hour)
        hour_24 = hour_24.replace(hour, new_hour, 1)

    return hour_24


def gen_new_hour(day_period, hour):
    if day_period == 'A':
        return '00'
    new_hour = int(hour)
    new_hour += 12
    return str(new_hour)


if __name__ == '__main__':
    main()
