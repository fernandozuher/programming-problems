// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        var obj = new SalesByMatch(array);
        Console.WriteLine(obj.Pairs);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class SalesByMatch
    {
        private List<int> _socks;
        private int _pairs;

        public SalesByMatch(List<int> socks)
        {
            _socks = socks;
            _pairs = 0;
            _sockMerchant();
        }

            private void _sockMerchant()
            {
                var socksPairing = new Dictionary<int, bool>();

                foreach (int sock in _socks)
                {
                    bool value;
                    if (socksPairing.TryGetValue(sock, out value) && value)
                        _pairs++;
                    socksPairing[sock] = !value;
                }
            }

        public int Pairs
        {
            get { return _pairs; }
        }
    }
