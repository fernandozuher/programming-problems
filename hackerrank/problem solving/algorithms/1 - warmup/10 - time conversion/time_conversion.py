#!/bin/python3

import os

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(time):
    convertedTime = time[:8]
    hourString = time[:2]
    periodOfDay = time[8:9]

    if hourString == "12":
        if periodOfDay == "A":
            convertedTime = convertedTime.replace(hourString, "00", 1)
    elif periodOfDay == "P":
        hour = int(hourString)
        hour += 12
        convertedTime = convertedTime.replace(hourString, str(hour), 1)
    
    return convertedTime

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
