// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

import java.util.Scanner;


public class Solution {

	public static void main(String[] args) {
		final Scanner scanner = new Scanner(System.in);
		final int days = scanner.nextInt();
		final ViralAdvertising cumulativeLikes = new ViralAdvertising(days);
	}
}

	class ViralAdvertising {

		private int _days;
		private int _cumulativeLikes;

		public ViralAdvertising(int days) {
			_days = days;
			_cumulativeLikes = 0;

			_viralAdvertising();
			printCumulativeLikes();
		}

			private void _viralAdvertising() {
				int shared = 5, liked = 0;

				for (int i = 0; i < _days; i++) {
					liked = shared / 2;
					_cumulativeLikes += liked;
					shared = liked * 3;
				}
			}

			public void printCumulativeLikes() {
				System.out.println(_cumulativeLikes);
			}
	}
