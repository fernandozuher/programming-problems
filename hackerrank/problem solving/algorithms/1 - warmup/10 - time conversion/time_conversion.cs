using System;

class Result
{

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string timeConversion(string time)
    {
        string convertedTime = time.Substring(0, 8);
        string hourString = time.Substring(0, 2);
        string periodOfDay = time.Substring(8, 1);

        if (hourString == "12") {
            if (periodOfDay == "A")
                convertedTime = convertedTime.Replace(hourString, "00");
        }
        else if (periodOfDay == "P") {
            int hour = int.Parse(hourString);
            hour += 12;
            convertedTime = convertedTime.Replace(hourString, hour.ToString());
        }
        return convertedTime;
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.timeConversion(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
