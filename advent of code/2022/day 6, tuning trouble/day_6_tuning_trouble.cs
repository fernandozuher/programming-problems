using System;
using System.IO;
using System.Collections.Generic;

class TuningTrouble
{
	private int charactersBeforeEndOfPacketMaker;
	private int charactersBeforeEndOfMessageMaker;

	private int CountCharactersBeforeEndOfSomeMaker(string[] input, int sizePacket)
	{
		int initialIndex = sizePacket - 1;
		int lastIndexOfSomeMaker = -1;

		for (int i = initialIndex, n = input[0].Length; i < n; i++)
		{
			int initSubstring = i - initialIndex;
			string substring = input[0].Substring(initSubstring, sizePacket);

			if (IsSubstringLikeASet(substring))
			{
				lastIndexOfSomeMaker = i;
				break;
			}
		}
		return lastIndexOfSomeMaker + 1;
	}

	private bool IsSubstringLikeASet(string substring)
	{
		HashSet<char> charSet = new HashSet<char>();
		foreach (char character in substring)
			if (!charSet.Add(character))
				return false;
		return true;
	}

	public TuningTrouble(string[] input)
	{
		this.charactersBeforeEndOfPacketMaker = CountCharactersBeforeEndOfSomeMaker(input, 4);
		this.charactersBeforeEndOfMessageMaker = CountCharactersBeforeEndOfSomeMaker(input, 14);
		PrintOutput();
	}

	public void PrintOutput()
	{
		Console.WriteLine("{0}\n{1}", charactersBeforeEndOfPacketMaker, charactersBeforeEndOfMessageMaker);
	}
}

class Solution
{
	public static string[] ReadInputFromFile()
	{
		string[] input = File.ReadAllLines("input.txt");
		return input;
	}

	public static void Main()
	{
		string[] input = ReadInputFromFile();
		TuningTrouble tuningTrouble = new TuningTrouble(input);
	}
}
