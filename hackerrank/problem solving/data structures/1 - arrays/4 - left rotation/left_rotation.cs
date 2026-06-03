// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

var arr = ReadNumbers();
int n = arr[0];
int rotateBy = arr[1];
arr = ReadNumbers();
Rotate(arr, rotateBy);
Console.WriteLine(string.Join(" ", arr));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(n) extra space
void Rotate(int[] arr, int rotateBy)
{
    if (rotateBy >= n)
        rotateBy %= n;
    var rotated = arr.Skip(rotateBy).Concat(arr.Take(rotateBy)).ToArray();
    Array.Copy(rotated, arr, arr.Length);
}
