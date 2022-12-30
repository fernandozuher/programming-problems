// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		readLineAsListInteger(bufferedReader);
		List<Integer> chocolateSquares = readLineAsListInteger(bufferedReader);
		List<Integer> dayMonth = readLineAsListInteger(bufferedReader);

		Result result = new Result(chocolateSquares, dayMonth);
	}

		private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader)  {
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
}

	class Result {
		private List<Integer> _chocolateSquares;
		private int _day, _month;
		private int _waysBarCanBeDivided;

		public Result(List<Integer> chocolateSquares, List<Integer> dayMonth) {
			_chocolateSquares = chocolateSquares;
			_day = dayMonth.get(0);
			_month = dayMonth.get(1);
			_waysBarCanBeDivided = 0;

			birthday();
			printResult();
		}

			private void birthday() {
				for (int i = 0, n1 = _chocolateSquares.size() - _month + 1; i < n1; i++) {
					int sum = 0;
					for (int j = i, n2 = i + _month; j < n2; sum += _chocolateSquares.get(j++));
					if (sum == _day)
						_waysBarCanBeDivided++;
				}
			}

			public void printResult() {
				System.out.println(_waysBarCanBeDivided);
			}
	}
