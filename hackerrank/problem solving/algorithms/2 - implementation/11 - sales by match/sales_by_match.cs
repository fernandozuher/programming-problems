// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int _ = int.Parse(ReadLine()!);
        List<int> array = _readIntArray();
        WriteLine(_sockMerchant(array));
    }

        private static List<int> _readIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        private static int _sockMerchant(List<int> socks)
        {
            int pairs = 0;
            var socksPairing = new Dictionary<int, bool>();

            foreach (int sock in socks)
            {
                if (socksPairing.TryGetValue(sock, out var value) && value)
                    ++pairs;
                socksPairing[sock] = !value;
            }

            return pairs;
        }
}