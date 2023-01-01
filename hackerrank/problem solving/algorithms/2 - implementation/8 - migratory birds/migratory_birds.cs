// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

using System;

class Solution
{
	public static void Main()
	{
		ReadLineAsListInt();
		List<int> birdSightings = ReadLineAsListInt();

		birdSightings.Sort();
		
		Result result = new Result(birdSightings);
	}

		private static List<int> ReadLineAsListInt()
		{
			List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
			return numbers;
		}
}

	class Result
	{
		private List<int> _birdSightings;
		private int _mostSpottedBird;

		public Result(List<int> birdSightings)
		{
			_birdSightings = birdSightings;

			MigratoryBirds();
			PrintResult();
		}

			private void MigratoryBirds()
			{
				_mostSpottedBird = _birdSightings.First();
		        int count_mostSpottedBird = 1;
		        int tempCountMostSpottedBird = 1;

		        for (int i = 1; i < _birdSightings.Count; i++)

		            if (_birdSightings[i] == _birdSightings[i - 1])
		                tempCountMostSpottedBird++;

		            else if (tempCountMostSpottedBird > count_mostSpottedBird) {
		                _mostSpottedBird = _birdSightings[i - 1];
		                count_mostSpottedBird = tempCountMostSpottedBird;
		                tempCountMostSpottedBird = 1;
		            }

		        if (tempCountMostSpottedBird > count_mostSpottedBird)
		            _mostSpottedBird = _birdSightings.Last();
			}

			public void PrintResult()
			{
				Console.WriteLine(_mostSpottedBird);
			}
	}
