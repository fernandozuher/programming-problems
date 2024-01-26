// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        List<int> ranked = _readIntArray();
        ranked = _removeDuplicates<int>(ranked);

        n = int.Parse(Console.ReadLine());
        List<int> player = _readIntArray();

        var obj = new ClimbingTheLeaderboard(ranked, player);
        PrintArray<int>(obj.PlayerRank);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }

        private static List<T> _removeDuplicates<T>(List<T> array)
        {
            return array.Distinct().ToList();
        }

    public static int BinarySearchDescendingOrder(List<int> array, int low, int high, int key)
    {
        if (high >= low)
        {
            int middle = low + (high - low) / 2;

            if (key == array[middle])
                return middle;
            else if (key > array[middle])
                return Solution.BinarySearchDescendingOrder(array, low, middle - 1, key);
            else
                return Solution.BinarySearchDescendingOrder(array, middle + 1, high, key);
        }
        return low;
    }

        public static void PrintArray<T>(List<T> array)
        {
            foreach (T element in array)
                Console.WriteLine(element);
        }
}

    public class ClimbingTheLeaderboard
    {
        private List<int> _ranked;
        private List<int> _player;
        private List<int> _playerRank;

        public ClimbingTheLeaderboard(List<int> ranked, List<int> player)
        {
            _ranked = ranked;
            _player = player;
            _playerRank = new List<int>(new int[_player.Count]);
            _climbingLeaderboard();
        }

        private void _climbingLeaderboard()
        {
            for (int i = 0, lastIndex = _ranked.Count - 1, n = _player.Count; i < n; ++i)
            {
                int index = Solution.BinarySearchDescendingOrder(_ranked, 0, lastIndex, _player[i]);
                _playerRank[i] = ++index;
            }
        }

        public List<int> PlayerRank
        {
            get { return _playerRank; }
        }
    }
