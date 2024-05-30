# https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

def main():
    time = input()
    print(time_conversion(time))


def time_conversion(time):
    converted_time = time[:8]
    hour = time[:2]
    period_of_day = time[8:9]

    if hour == "12":
        if period_of_day == "A":
            midnight = "00"
            converted_time = converted_time.replace(hour, midnight, 1)
    elif period_of_day == "P":
        new_hour = int(hour)
        new_hour += 12
        converted_time = converted_time.replace(hour, str(new_hour), 1)

    return converted_time


if __name__ == '__main__':
    main()
