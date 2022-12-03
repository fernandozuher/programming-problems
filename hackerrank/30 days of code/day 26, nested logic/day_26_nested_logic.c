#include <stdio.h>
#include <stdlib.h>

enum hackos_fine {
    hackos_days_fine = 15,
    hackos_months_fine = 500,
    hackos_years_fine = 10000
};

typedef struct date_struct {
    int day, month, year;
} date;

void read_stdin_dates(date* dates) {
    scanf("%d %d %d %d %d %d",
          &dates[0].day, &dates[0].month, &dates[0].year,
          &dates[1].day, &dates[1].month, &dates[1].year);
}

int calculate_fine(date* dates) {
    int fine;

    if (dates[0].year < dates[1].year)
        fine = 0;
    else if (dates[0].year == dates[1].year) {
        if (dates[0].month < dates[1].month)
            fine = 0;
        else if (dates[0].month == dates[1].month)
            fine = (dates[0].day < dates[1].day) ? 0 : (dates[0].day - dates[1].day) * hackos_days_fine;
        else
            fine = (dates[0].month - dates[1].month) * hackos_months_fine;
    }
    else
        fine = hackos_years_fine;

    return fine;
}

int main() {
    date* dates = calloc(2, sizeof(date));
    read_stdin_dates(dates);
    int fine = calculate_fine(dates);
    printf("%d\n", fine);
    return 0;
}
