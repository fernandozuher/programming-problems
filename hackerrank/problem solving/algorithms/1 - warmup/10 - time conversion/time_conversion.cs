// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        string time = ReadLine();
        WriteLine(TimeConversion(time));
    }

        static string TimeConversion(string time)
        {
            string convertedTime = time.Substring(0, 8);
            string hour = time.Substring(0, 2);
            string dayPeriod = time.Substring(8, 1);

            if (hour == "12")
            {
                if (dayPeriod == "A")
                {
                    string midnight = "00";
                    convertedTime = convertedTime.Replace(hour, midnight);
                }
            }
            else if (dayPeriod == "P")
            {
                int newHour = int.Parse(hour);
                newHour += 12;
                convertedTime = convertedTime.Replace(hour, newHour.ToString());
            }

            return convertedTime;
        }
}
