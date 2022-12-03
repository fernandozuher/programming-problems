process.stdin.resume()
process.stdin.setEncoding("ascii")
_input = ""
process.stdin.on("data", function (input) {
    _input += input
})

process.stdin.on("end", function () {
   processData(_input)
})

const HackosFine = Object.freeze({
    HackosDaysFine: 15,
    HackosMonthsFine: 500,
    HackosYearsFine: 10000
})

class DateThatWorks {
    __day = 0
    __month = 0
    __year = 0

    constructor(day, month, year) {
        this.__day = day
        this.__month = month
        this.__year = year
    }

    getDay() {
        return this.__day
    }

    getMonth() {
        return this.__month
    }

    getYear() {
        return this.__year
    }
}

class BookReturnDate {
    __returnedRealDate = Object
    __dueDate = Object
    __fine = 0

    __calculateFine() {
        if (this.__returnedRealDate.getYear() < this.__dueDate.getYear())
            this.__fine = 0
        else if (this.__returnedRealDate.getYear() === this.__dueDate.getYear()) {
            if (this.__returnedRealDate.getMonth() < this.__dueDate.getMonth())
                this.__fine = 0
            else if (this.__returnedRealDate.getMonth() === this.__dueDate.getMonth()) {
                if (this.__returnedRealDate.getDay() < this.__dueDate.getDay())
                    this.__fine = 0
                else
                    this.__fine = (this.__returnedRealDate.getDay() - this.__dueDate.getDay()) * HackosFine.HackosDaysFine
            }
            else
                this.__fine = (this.__returnedRealDate.getMonth() - this.__dueDate.getMonth()) * HackosFine.HackosMonthsFine
        } else
            this.__fine = HackosFine.HackosYearsFine
    }

    constructor(returnedRealDate, dueDate) {
        this.__returnedRealDate = returnedRealDate
        this.__dueDate = dueDate
        this.__calculateFine()
    }

    getFine() {
        return this.__fine
    }
}

function readStdinDates(input) {
    const numbers = input.split(/\s+/g).map(Number)
    const returnedRealDate = new DateThatWorks(numbers[0], numbers[1], numbers[2])
    const dueDate = new DateThatWorks(numbers[3], numbers[4], numbers[5])
    return [returnedRealDate, dueDate]
}

function processData(input) {
    [returnedRealDate, dueDate] = readStdinDates(input)
    const bookReturnDateObj = new BookReturnDate(returnedRealDate, dueDate)
    console.log(bookReturnDateObj.getFine())
}
