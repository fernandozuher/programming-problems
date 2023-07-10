// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

int compare (const void *a, const void *b);
int find_missing_element(const int* array, const int size);

int solution(int* array, const int size)
{
    qsort(array, size, sizeof(int), compare);
    return find_missing_element(array, size);
}

    int compare (const void *a, const void *b)
    {
        return (*(int*) a - *(int*) b);
    }

    int find_missing_element(const int* array, const int size)
    {
        int i;
        for (i = 0; i < size; i++)
            if (array[i] != i + 1)
                break;
        return i + 1;
    }
