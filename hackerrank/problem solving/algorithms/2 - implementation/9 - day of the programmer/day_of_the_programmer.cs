// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

using System;

class Solution
{
	public static void Main()
	{
		List<int> year = ReadLineAsListInt();
		
		Result result = new Result(year.First());
	}

		private static List<int> ReadLineAsListInt()
		{
			List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
			return numbers;
		}
}

	class Result
	{
		private int _year;
		private string _date;

		public Result(int year)
		{
			_year = year;
			_date = "";

			DayOfProgrammer();
			PrintResult();
		}

			private void DayOfProgrammer()
			{
				if (_year != 1918)
				{
                    bool isLeap = _year > 1918 ? _IsLeapGregorianYear() : _IsLeapJulianYear();
                    _date = isLeap ? "12.09." : "13.09.";
                }
                else
                    _date = "26.09.";
                
                _date += _year.ToString();
            }
            

            private bool _IsLeapGregorianYear()
            {
                return _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
            }
                
            private bool _IsLeapJulianYear()
            {
                return _year % 4 == 0;
            }

			public void PrintResult()
			{
				Console.WriteLine(_date);
			}
	}
