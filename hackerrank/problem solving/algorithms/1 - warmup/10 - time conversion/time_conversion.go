// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

package main

import (
    "fmt"
    "strconv"
    "strings"
)

func main() {
    var time string
    fmt.Scan(&time)
    fmt.Print(timeConversion(time))
}

func timeConversion(time string) string {
    convertedTime := time[0:8]
    hour := time[0:2]
    dayPeriod := time[8:9]

    if hour == "12" {
        if dayPeriod == "A" {
            midnight := "00"
            convertedTime = strings.Replace(convertedTime, hour, midnight, 1)
        }
    } else if dayPeriod == "P" {
        newHour, _ := strconv.Atoi(hour)
        newHour += 12
        convertedTime = strings.Replace(convertedTime, hour, strconv.Itoa(newHour), 1)
    }

    return convertedTime
}
