// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

var arr = ReadNumbers();
int n = arr[0];
int nQueries = arr[1];
var obj = new DynamicArray(n);

for (int i = 0; i < nQueries; i++)
    obj.HandleQuery(ReadNumbers());

obj.Answers.ForEach(Console.WriteLine);


int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

public class DynamicArray
{
    private int _n;
    private List<List<int>> _arr;
    private List<int> _answers;
    private int _lastAnswer;

    public DynamicArray(int n)
    {
        _n = n;

        _arr = new List<List<int>>(n);
        for (int i = 0; i < n; ++i)
            _arr.Add([]);

        _answers = [];
        _lastAnswer = 0;
    }

    public void HandleQuery(int[] query)
    {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x ^ _lastAnswer) % _n;

        if (type == 1)
            _arr[index].Add(y);
        else
        {
            int j = y % _arr[index].Count;
            _lastAnswer = _arr[index][j];
            _answers.Add(_lastAnswer);
        }
    }

    public List<int> Answers => _answers;
}
