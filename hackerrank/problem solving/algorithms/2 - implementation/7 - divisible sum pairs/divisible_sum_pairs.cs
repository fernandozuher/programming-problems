// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

using System;

class Solution
{
	public static void Main()
	{
		List<int> input1 = ReadLineAsListInt();
		int k = input1[1];
		List<int> numbers = ReadLineAsListInt();

		numbers.Sort();
		
		Result result = new Result(numbers, k);
	}

		private static List<int> ReadLineAsListInt()
		{
			List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
			return numbers;
		}
}

	class Result
	{
		private List<int> _numbers;
		private int _k;
		private int _nDivisibleSumPairs;

		public Result(List<int> numbers, int k)
		{
			_numbers = numbers;
			_k = k;
			_nDivisibleSumPairs = 0;

			DivisibleSumPairs();
			PrintResult();
		}

			private void DivisibleSumPairs()
			{
				for (int i = 0, n1 = _numbers.Count - 1; i < n1; i++)
		            for (int j = i + 1; j < _numbers.Count; j++)
		                if (_numbers[i] <= _numbers[j] && (_numbers[i] + _numbers[j]) % _k == 0)
		                    _nDivisibleSumPairs++;
			}

			public void PrintResult()
			{
				Console.WriteLine(_nDivisibleSumPairs);
			}
	}
