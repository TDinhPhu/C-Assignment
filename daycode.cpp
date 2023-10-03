#include <stdio.h>
#include <stdint.h>

struct Date {
    uint8_t day;
    uint8_t month;
    uint16_t year;
};

const char* daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calculateDayOfWeek(struct Date date) {
    int day = date.day;
    int month = date.month;
    int year = date.year;

    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;

    if (isLeapYear(year)) {
        dayOfWeek += 7; 
    }

    return dayOfWeek;
}

int main() {
    struct Date date;
    while(1){
    printf("Enter day (1-31): ");
    scanf("%hhu", &date.day);

    printf("Enter month (1-12): ");
    scanf("%hhu", &date.month);

    printf("Enter year: ");
    scanf("%hu", &date.year);

    if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12) {
        printf("Invalid input. Please enter a valid day and month.\n");
        return 1;
    }

    if (date.month == 2) {
        if (isLeapYear(date.year) && date.day > 29) {
            printf("Invalid. February have 29 days in a leap year.\n");
            return 1;
        } else if (!isLeapYear(date.year) && date.day > 28) {
            printf("Invalid. February have 28 days in a non-leap year.\n");
            return 1;
        }
    }

    int dayOfWeek = calculateDayOfWeek(date);
    printf("The day of the week is: %s\n", daysOfWeek[dayOfWeek]);
    }

    return 0;
}
