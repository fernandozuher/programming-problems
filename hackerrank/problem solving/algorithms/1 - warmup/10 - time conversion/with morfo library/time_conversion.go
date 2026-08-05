// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "strconv"
    "strings"
)

func main() {
    time := morfoio.Read[string]()
    fmt.Println(to24HourTime(time))
}

// T: O(1)
// S: O(1) extra space
func to24HourTime(hour12 string) string {
    hour24 := hour12[0:8]
    hour := hour12[0:2]
    dayPeriod := hour12[8:9]

    if (hour == "12" && dayPeriod == "A") || (hour != "12" && dayPeriod == "P") {
        newHour := genNewHour(dayPeriod, hour)
        hour24 = strings.Replace(hour24, hour, newHour, 1)
    }

    return hour24
}

func genNewHour(dayPeriod, hour string) string {
    if dayPeriod == "A" {
        return "00"
    }
    newHour, _ := strconv.Atoi(hour)
    newHour += 12
    return strconv.Itoa(newHour)
}
