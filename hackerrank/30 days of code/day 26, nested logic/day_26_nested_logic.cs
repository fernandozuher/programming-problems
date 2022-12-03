using System;

namespace Application
{
enum HackosFine
{
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000
}

public class BookReturnDate
{
    private DateTime returnedRealDate, dueDate;
    private int fine;

    private void calculateFine()
    {
        if (returnedRealDate <= dueDate)
            fine = 0;
        else if (returnedRealDate.Year == dueDate.Year)
        {
            if (returnedRealDate.Month == dueDate.Month)
                fine = (returnedRealDate.Day - dueDate.Day) * (int) HackosFine.HackosDaysFine;
            else
                fine = (returnedRealDate.Month - dueDate.Month) * (int) HackosFine.HackosMonthsFine;
        }
        else
            fine = (int) HackosFine.HackosYearsFine;
    }

    public BookReturnDate(DateTime returnedRealDate, DateTime dueDate)
    {
        this.returnedRealDate = returnedRealDate;
        this.dueDate = dueDate;
        calculateFine();
    }

    public int getFine()
    {
        return fine;
    }
}

class Execution
{
    static void readStdinDates(ref DateTime returnedRealDate, ref DateTime dueDate)
    {
        string[] line;
        int[] numbers;

        line = Console.ReadLine().Split(' ');
        numbers = Array.ConvertAll(line, int.Parse);
        returnedRealDate = new DateTime(numbers[2], numbers[1], numbers[0]);

        line = Console.ReadLine().Split(' ');
        numbers = Array.ConvertAll(line, int.Parse);
        dueDate = new DateTime(numbers[2], numbers[1], numbers[0]);
    }

    static void Main(String[] args)
    {
        DateTime returnedRealDate = new DateTime(), dueDate = new DateTime();
        readStdinDates(ref returnedRealDate, ref dueDate);

        BookReturnDate bookReturnDateObj = new BookReturnDate(returnedRealDate, dueDate);
        Console.WriteLine(bookReturnDateObj.getFine());
    }
}
}
