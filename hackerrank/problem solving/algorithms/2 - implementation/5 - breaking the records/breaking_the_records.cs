// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

using System;

class Result
{
	private List<int> _scores;
	private int _breakingMostPointsRecords, _breakingLeastPointsRecords;

	public Result(List<int> setA)
	{
		_scores = setA;
		_breakingMostPointsRecords = _breakingLeastPointsRecords = 0;
		BreakingRecords();
		PrintResult();
	}

		private void BreakingRecords()
		{
			int mostPoints = _scores.First();
			int leastPoints = _scores.First();

			foreach (int score in _scores)
				if (score > mostPoints)
				{
					mostPoints = score;
					_breakingMostPointsRecords++;
				}
				else if (score < leastPoints)
				{
					leastPoints = score;
					_breakingLeastPointsRecords++;
				}
		}

		public void PrintResult()
		{
			Console.WriteLine("{0} {1}", _breakingMostPointsRecords, _breakingLeastPointsRecords);
		}
}

class Solution
{
	private static List<int> readAsIntList()
	{
		List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
		return numbers;
	}

	public static void Main()
	{
		readAsIntList();
		List<int> setA = readAsIntList();

		Result result = new Result(setA);
	}
}
