// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

string time = Console.ReadLine()!;
Console.WriteLine(To24HourTime(time));

// T: O(1)
// S: O(1) extra space
string To24HourTime(string hour12)
{
    string hour24 = hour12.Substring(0, 8);
    string hour = hour12.Substring(0, 2);
    string dayPeriod = hour12.Substring(8, 1);

    if ((hour == "12" && dayPeriod == "A") || (hour != "12" && dayPeriod == "P"))
    {
        string newHour = GenNewHour(dayPeriod, hour);
        hour24 = hour24.Replace(hour, newHour);
    }

    return hour24;
}

string GenNewHour(string dayPeriod, string hour)
{
    if (dayPeriod == "A")
        return "00";
    int newHour = int.Parse(hour);
    newHour += 12;
    return newHour.ToString();
}
