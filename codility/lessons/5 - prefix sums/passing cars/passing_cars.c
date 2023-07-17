// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

int solution(int array[], int size)
{
    int passing_cars_pairs = 0;

    for (int i = 0, east = 0, west, passing_cars_limit = 1000000000; i < size; ++i)
        if ((west = array[i])) {
            if ((passing_cars_pairs += east) > passing_cars_limit)
                return -1;
        }
        else
            east++;

    return passing_cars_pairs;
}
