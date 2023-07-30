// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

package main

import "fmt"

type person struct {
    age int
}

func (p person) NewPerson(initialAge int) person {
    if initialAge < 0 {
        p.age = 0
        fmt.Println("Age is not valid, setting age to 0.")
    } else {
        p.age = initialAge
    }

    return p
}

func (p person) amIOld() {
    if p.age < 13 {
        fmt.Println("You are young.")
    } else if p.age >= 13 && p.age < 18 {
        fmt.Println("You are a teenager.")
    } else {
        fmt.Println("You are old.")
    }
}

func (p person) yearPasses() person {
    p.age++
    return p
}

func main() {
    var nTests int
    fmt.Scan(&nTests)

    for ; nTests > 0; nTests-- {
        var age int
        fmt.Scan(&age)

        p := person{age: age}
        p = p.NewPerson(age)
        p.amIOld()

        for i := 0; i < 3; i++ {
            p = p.yearPasses()
        }
        p.amIOld()

        fmt.Println()
    }
}
