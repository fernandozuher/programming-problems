// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

using System;

class Solution
{
	public static void Main()
	{
		readLineAsListInt();
		List<int> chocolateSquares = readLineAsListInt();
		List<int> dayMonth = readLineAsListInt();

		Result result = new Result(chocolateSquares, dayMonth);
	}

		private static List<int> readLineAsListInt()
		{
			List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
			return numbers;
		}
}

	class Result
	{
		private List<int> _chocolateSquares;
		private int _day, _month;
		private int _waysBarCanBeDivided;

		public Result(List<int> chocolateSquares, List<int> dayMonth)
		{
			_chocolateSquares = chocolateSquares;
			_day = dayMonth.First();
			_month = dayMonth.Last();
			_waysBarCanBeDivided = 0;

			Birthday();
			PrintResult();
		}

			private void Birthday()
			{
				for (int i = 0, n1 = _chocolateSquares.Count - _month + 1; i < n1; i++)
				{
					int sum = 0;
					for (int j = i, n2 = i + _month; j < n2; sum += _chocolateSquares[j++]);
					if (sum == _day)
						_waysBarCanBeDivided++;
				}
			}

			public void PrintResult()
			{
				Console.WriteLine(_waysBarCanBeDivided);
			}
	}
