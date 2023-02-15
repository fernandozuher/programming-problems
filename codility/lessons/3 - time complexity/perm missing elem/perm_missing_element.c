// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

void sort_array_in_place(int *array, const int SIZE);
    int compare (const void *a, const void *b);
int find_missing_element(const int ARRAY[], const int SIZE);


int solution(int array[], const int SIZE) {
    sort_array_in_place(array, SIZE);
    const int MISSING_ELEMENT = find_missing_element(array, SIZE);
    return MISSING_ELEMENT;
}

    void sort_array_in_place(int *array, const int SIZE) {
        qsort(array, SIZE, sizeof(int), compare);
    }

        int compare (const void *a, const void *b) {
            return (*(int*) a - *(int*) b);
        }

    int find_missing_element(const int ARRAY[], const int SIZE) {
        int i;

        for (i = 0; i < SIZE; i++)
            if (ARRAY[i] != i + 1)
                break;

        return i + 1;
    }
