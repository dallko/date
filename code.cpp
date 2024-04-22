#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent a Date
struct Date {
    int day;
    int month;
    int year;

    // Default constructor
    Date() : day(0), month(0), year(0) {}

    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Function to check if the date is valid
    bool isValidDate() const {
        if (year < 0 || month < 1 || month > 12 || day < 1)
            return false;

        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return day <= 29;
            else
                return day <= 28;
        }

        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return day <= daysInMonth[month];
    }

    // Function to update the date
    void newDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Function to get the day of the week (0 - Saturday, 1 - Sunday, ..., 6 - Friday)
    int getDayOfWeek() const {
        int tempMonth = month;
        int tempYear = year;
        if (tempMonth < 3) {
            tempMonth += 12;
            tempYear -= 1;
        }
        int h = (day + 13 * (tempMonth + 1) / 5 + tempYear + tempYear / 4 - tempYear / 100 + tempYear / 400) % 7;
        return h;
    }

    // Function to calculate the difference in days between two dates
    int calculateDifference(const Date& date) const {
        if (!isValidDate() || !date.isValidDate()) {
            cerr << "Invalid date" << endl;
            return -1;
        }

        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int days = 0;
        Date earlierDate = (*this < date) ? *this : date;
        Date laterDate = (*this < date) ? date : *this;

        while (earlierDate < laterDate) {
            days++;
            earlierDate.day++;

            if (earlierDate.day > daysInMonth[earlierDate.month]) {
                earlierDate.day = 1;
                earlierDate.month++;

                if (earlierDate.month > 12) {
                    earlierDate.month = 1;
                    earlierDate.year++;
                }
            }
        }

        return days;
    }

    // Function to print the date in DD.MM.YYYY format along with the day of the week
    void printDate() const {
        string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        cout << day << "." << month << "." << year << " (" << daysOfWeek[getDayOfWeek()] << ")";
    }

    // Comparison operator to compare two dates
    bool operator<(const Date& date) const {
        if (year != date.year)
            return year < date.year;
        if (month != date.month)
            return month < date.month;
        return day < date.day;
    }
};

// Function to input a date from the user
Date inputDate() {
    int d, m, y;
    char dot;
    cout << "Enter date in format DD.MM.YYYY: ";
    cin >> d >> dot >> m >> dot >> y;
    return Date(d, m, y);
}

// Main function
int main() {
    // Input the first date from the user
    cout << "Enter the first date:" << endl;
    Date date1 = inputDate();

    // Input the second date from the user
    cout << "Enter the second date:" << endl;
    Date date2 = inputDate();

    // Print the entered dates
    cout << "\nEntered dates:" << endl;
    cout << "First date: ";
    date1.printDate();
    cout << endl;
    cout << "Second date: ";
    date2.printDate();
    cout << endl;

    // Calculate and print the difference in days between the dates
    int diff = date1.calculateDifference(date2);
    if (diff != -1) {
        cout << "\nDifference in days between dates: " << diff << endl;
    }

    return 0;
}
