// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int *arr, int n);
int preprocess_input(int *arr, int n);
void sort(int *arr, int n);
int compare(const void *a, const void *b);
int remove_duplicate(int *arr, int n);
int calculate_money_spent(const int *keyboards, int n_keyboards, const int *usb_drives, int n_usb_drives, int budget);

int main()
{
    int budget, n_keyboards, n_usb_drives;
    scanf("%d %d %d", &budget, &n_keyboards, &n_usb_drives);

    int keyboards[n_keyboards], usb_drives[n_usb_drives];
    read_numbers(keyboards, n_keyboards);
    read_numbers(usb_drives, n_usb_drives);
    int n1 = preprocess_input(keyboards, n_keyboards);
    int n2 = preprocess_input(usb_drives, n_usb_drives);

    printf("%d\n", calculate_money_spent(keyboards, n1, usb_drives, n2, budget));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int preprocess_input(int *arr, int n)
{
    sort(arr, n);
    int new_size = remove_duplicate(arr, n);
    return new_size;
}

void sort(int *arr, int n)
{
    qsort(arr, n, sizeof(int), compare);
}

int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int remove_duplicate(int *arr, int n)
{
    int w = 0;
    for (int s = 0; s < n; ++s) {
        if (s != 0 && arr[s] == arr[s - 1])
            continue;
        arr[w] = arr[s];
        ++w;
    }
    return w;
}

// n: n_keyboards
// m: n_usb_drives
// T: O(n + m)
// S: O(1) extra space
int calculate_money_spent(const int *keyboards, int n_keyboards, const int *usb_drives, int n_usb_drives, int budget)
{
    if (keyboards[0] >= budget || usb_drives[0] >= budget)
        return -1;

    int max_spent = -1;
    for (int idx_k = 0, idx_ud = n_usb_drives - 1; idx_k < n_keyboards && idx_ud >= 0;) {
        if (keyboards[idx_k] >= budget)
            break;

        int current_sum = keyboards[idx_k] + usb_drives[idx_ud];
        if (current_sum == budget)
            return budget;

        if (current_sum > budget)
            --idx_ud;
        else {
            if (current_sum > max_spent)
                max_spent = current_sum;
            ++idx_k;
        }
    }

    return max_spent;
}
