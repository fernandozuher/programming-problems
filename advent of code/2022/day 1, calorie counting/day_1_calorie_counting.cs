using System;

class Day1CalorieCounting
{
	public static string[] readInputFromFile()
	{
		string[] input = File.ReadAllLines("../input.txt");
		return input;
	}

	public static void findMostCalories(string[] input)
	{
		List<int> caloriesOfElves = new List<int>();

		int counter = 0;
		foreach (string line in input)
		{
			int number;
			if (int.TryParse(line, out number))
				counter += number;
			else
			{
				caloriesOfElves.Add(counter);
				counter = 0;
			}
		}

		caloriesOfElves.Sort();
		caloriesOfElves.Reverse();
		int maxCalorie = caloriesOfElves.First();
		int sumMostThreeCalories = caloriesOfElves[0] + caloriesOfElves[1] + caloriesOfElves[2];

		Console.WriteLine("maxCalorie: {0}\nsumMostThreeCalories: {1}", maxCalorie, sumMostThreeCalories);
	}
}

class Solution
{
	public static void Main()
	{
		string[] input = Day1CalorieCounting.readInputFromFile();
		Day1CalorieCounting.findMostCalories(input);
	}
}
