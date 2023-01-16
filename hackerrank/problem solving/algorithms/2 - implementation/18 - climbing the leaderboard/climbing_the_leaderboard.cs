// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        ReadLineAsListInt();
        List<int> ranked = ReadLineAsListInt();

        ReadLineAsListInt();
        List<int> player = ReadLineAsListInt();

        Result result = new Result(ranked, player);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class Result
    {
        private List<int> _ranked;
        private List<int> _player;
        private List<int> _playerRank;

        public Result(List<int> ranked, List<int> player)
        {
            _ranked = ranked;
            _player = player;
            _playerRank = new List<int>(new int[_player.Count]);

            _RemoveDuplicatesFromRankedList();
            _ClimbingLeaderboard();
            PrintResult();
        }

            private void _RemoveDuplicatesFromRankedList()
            {
                _ranked = _ranked.Distinct().ToList();
            }

            private void _ClimbingLeaderboard()
            {
                for (int i = 0, n = _player.Count, lastIndex = _ranked.Count - 1; i < n; i++)
                {
                    int index = _BinarySearchDescendingOrder(0, lastIndex, _player[i]);
                    _playerRank[i] = ++index;
                }
            }

                private int _BinarySearchDescendingOrder(int low, int high, int key)
                {
                    if (high >= low)
                    {
                        int middle = low + (high - low) / 2;

                        if (key == _ranked[middle])
                            return middle;
                        else if (key > _ranked[middle])
                            return _BinarySearchDescendingOrder(low, middle - 1, key);
                        else
                            return _BinarySearchDescendingOrder(middle + 1, high, key);
                    }
                    return low;
                }

            public void PrintResult()
            {
                foreach (int playerRank in _playerRank)
                    Console.WriteLine(playerRank);
            }
    }
