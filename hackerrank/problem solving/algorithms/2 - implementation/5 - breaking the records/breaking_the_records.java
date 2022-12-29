// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {
	private List<Integer> _scores;
	private int _breakingMostPointsRecords, _breakingLeastPointsRecords;

	private void breakingRecords() {
		int mostPoints = _scores.get(0);
		int leastPoints = _scores.get(0);

		for (int score : _scores)
			if (score > mostPoints) {
				mostPoints = score;
				_breakingMostPointsRecords++;
			} else if (score < leastPoints) {
				leastPoints = score;
				_breakingLeastPointsRecords++;
			}
	}

	public Result(List<Integer> setA) {
		_scores = new ArrayList<Integer>(setA);
		_breakingMostPointsRecords = _breakingLeastPointsRecords = 0;
		breakingRecords();
		printResult();
	}

		public void printResult() {
			System.out.println(_breakingMostPointsRecords + " " + _breakingLeastPointsRecords);
		}
}

public class Solution {

	private static List<Integer> readLineAsIntegerList(BufferedReader bufferedReader)  {
		try {
			var numbers = Stream.of(bufferedReader.readLine().split(" "))
			              .map(Integer::parseInt)
			              .collect(toList());

			return numbers;
		} catch (Exception e) {
			System.out.println("Exception caught during reading");
		}
		return null;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		readLineAsIntegerList(bufferedReader);
		List<Integer> setA = readLineAsIntegerList(bufferedReader);

		Result result = new Result(setA);
	}
}
