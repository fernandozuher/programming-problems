// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        Input data = default;
        List<int> list = _readIntArray();

        int n = list.First();
        data.ItemAnnaDidntConsume = list.Last();
        data.CostOfEachMeal = _readIntArray();
        data.BrianChargedAnna = int.Parse(ReadLine()!);

        var obj = new BillDivision(data);
        obj.BonAppetit();
        _printOutput(obj.BrianOverchargedAnna);
    }

        private static List<int> _readIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        private static void _printOutput(int charged)
        {
            Console.WriteLine(charged > 0 ? charged : "Bon Appetit");
        }
}

    struct Input
    {
        public int ItemAnnaDidntConsume { get; set; }
        public List<int> CostOfEachMeal { get; set; }
        public int BrianChargedAnna { get; set; }
    }

    class BillDivision(Input data)
    {
        private readonly int _itemAnnaDidntConsume = data.ItemAnnaDidntConsume;
        private readonly List<int> _costOfEachMeal = data.CostOfEachMeal;
        private readonly int _brianChargedAnna = data.BrianChargedAnna;
        public int BrianOverchargedAnna { get; private set; }

        public void BonAppetit()
        {
            int annaCost = _calculateAnnaCost();
            _howMuchBrianOverchargedAnna(annaCost);
        }

            private int _calculateAnnaCost()
            {
                int sum = _costOfEachMeal.Sum();
                return (sum - _costOfEachMeal[_itemAnnaDidntConsume]) / 2;
            }

            private void _howMuchBrianOverchargedAnna(int annaCost)
            {
                if (annaCost != _brianChargedAnna)
                    BrianOverchargedAnna = _brianChargedAnna - annaCost;
            }
    }