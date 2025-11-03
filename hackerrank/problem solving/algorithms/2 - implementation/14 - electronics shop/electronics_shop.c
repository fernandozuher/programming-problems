// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

int *read_numbers(int n);
int compare(const void *a, const void *b);
int calculate_money_spent(const int keyboards[], int n_keyboards, const int usb_drives[], int n_usb_drives, int budget);

int main()
{
    int budget, n_keyboards, n_usb_drives;
    scanf("%d %d %d", &budget, &n_keyboards, &n_usb_drives);

    int *keyboards = read_numbers(n_keyboards);
    int *usb_drives = read_numbers(n_usb_drives);
    qsort(keyboards, n_keyboards, sizeof(int), compare);
    qsort(usb_drives, n_usb_drives, sizeof(int), compare);

    printf("%d\n", calculate_money_spent(keyboards, n_keyboards, usb_drives, n_usb_drives, budget));

    free(keyboards);
    free(usb_drives);

    return 0;
}

int *read_numbers(int n)
{
    auto numbers = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
    return numbers;
}

int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int calculate_money_spent(const int keyboards[], int n_keyboards, const int usb_drives[], int n_usb_drives, int budget)
{
    int max_spent = -1, i = 0, j = n_usb_drives - 1;

    while (i < n_keyboards && j >= 0) {
        if (keyboards[i] >= budget)
            break;

        int sum = keyboards[i] + usb_drives[j];
        if (sum > budget)
            --j;
        else if (sum == budget)
            return budget;
        else {
            if (sum > max_spent)
                max_spent = sum;
            ++i;
        }
    }

    return max_spent;
}
