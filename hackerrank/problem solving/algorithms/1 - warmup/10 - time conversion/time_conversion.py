# https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

def main():
    time = input()
    print(time_conversion(time))


# T: O(1)
# S: O(1) extra space
def time_conversion(time):
    converted_time = time[:8]
    hour = time[:2]
    day_period = time[8:9]

    if hour == "12":
        if day_period == "A":
            midnight = "00"
            converted_time = converted_time.replace(hour, midnight, 1)
    elif day_period == "P":
        new_hour = int(hour)
        new_hour += 12
        converted_time = converted_time.replace(hour, str(new_hour), 1)

    return converted_time


if __name__ == '__main__':
    main()
