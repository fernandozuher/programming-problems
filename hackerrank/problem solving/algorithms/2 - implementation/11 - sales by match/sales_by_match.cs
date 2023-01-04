// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        ReadLineAsListInt();
        List<int> socks = ReadLineAsListInt();
        
        Result result = new Result(socks);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return numbers;
        }
}

    class Result
    {
        private List<int> _socks;
        private int _pairs;

        public Result(List<int> socks)
        {
            _socks = socks;
            _pairs = 0;

            _SockMerchant();
            PrintResult();
        }

            private void _SockMerchant()
            {
                Dictionary<int, bool> socksPairing = new Dictionary<int, bool>();

                foreach (int sock in _socks)
                {
                    bool value;
                    if (socksPairing.TryGetValue(sock, out value) && value)
                        _pairs++;
                    socksPairing[sock] = !value;
                }
            }

            public void PrintResult()
            {
                Console.WriteLine(_pairs);
            }
    }
