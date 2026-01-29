// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

Console.ReadLine();
int[] arr = ReadNumbers();
Array.Sort(arr);
CutTheSticks(arr).ForEach(Console.WriteLine);

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
List<int> CutTheSticks(int[] arr)
{
    var res = new List<int>();
    int slow = 0, n = arr.Length;

    for (int fast = 0; fast < n; fast++)
    {
        if (arr[slow] == arr[fast])
            continue;
        res.Add(n - slow);
        slow = fast;
    }

    res.Add(n - slow);
    return res;
}
