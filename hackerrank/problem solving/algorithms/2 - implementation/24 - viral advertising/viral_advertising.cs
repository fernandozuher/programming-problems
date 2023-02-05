// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

using System;


public class Solution {

    public static void Main() {
        int days = Convert.ToInt32(Console.ReadLine());
        ViralAdvertising cumulativeLikes = new ViralAdvertising(days);
    }
}

    class ViralAdvertising {

        private int _days;
        private int _cumulativeLikes;

        public ViralAdvertising(int days) {
            _days = days;
            _cumulativeLikes = 0;

            _ViralAdvertising();
            PrintCumulativeLikes();
        }

            private void _ViralAdvertising() {
                int shared = 5, liked = 0;

                for (int i = 0; i < _days; i++) {
                    liked = shared / 2;
                    _cumulativeLikes += liked;
                    shared = liked * 3;
                }
            }

            public void PrintCumulativeLikes() {
                Console.WriteLine(_cumulativeLikes);
            }
    }
