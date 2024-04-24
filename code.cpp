#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool isValidDate(int day, int month, int year) {
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

int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int h = (day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return h;
}

int calculateDifference(const vector<int>& date1, const vector<int>& date2) {
    if (!isValidDate(date1[0], date1[1], date1[2]) || !isValidDate(date2[0], date2[1], date2[2])) {
        cerr << "Invalid date" << endl;
        return -1;
    }

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int earlierYear = date1[2], laterYear = date2[2];
    int earlierMonth = date1[1], laterMonth = date2[1];
    int earlierDay = date1[0], laterDay = date2[0];

    if (date1 > date2) {
        earlierYear = date2[2];
        laterYear = date1[2];
        earlierMonth = date2[1];
        laterMonth = date1[1];
        earlierDay = date2[0];
        laterDay = date1[0];
    }

    int days = 0;
    while (earlierYear < laterYear || earlierMonth < laterMonth || earlierDay < laterDay) {
        days++;
        earlierDay++;

        if (earlierDay > daysInMonth[earlierMonth]) {
            earlierDay = 1;
            earlierMonth++;

            if (earlierMonth > 12) {
                earlierMonth = 1;
                earlierYear++;
            }
        }
    }

    return days;
}

string printDate(const vector<int>& date) {
    string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    stringstream ss;
    ss << date[0] << "." << date[1] << "." << date[2] << " (" << daysOfWeek[getDayOfWeek(date[0], date[1], date[2])] << ")";
    return ss.str();
}

vector<int> inputDate() {
    int d, m, y;
    char dot;
    cout << " ";
    cin >> d >> dot >> m >> dot >> y;
    return {d, m, y};
}

int main() {
    cout << "Enter the first date in format DD.MM.YYYY:" << endl;
    vector<int> date1 = inputDate();

    cout << "Enter the second date in format DD.MM.YYYY:" << endl;
    vector<int> date2 = inputDate();

    cout << "\nCalculated:" << endl;
    cout << "First date: " << printDate(date1) << endl;
    cout << "Second date: " << printDate(date2) << endl;

    int diff = calculateDifference(date1, date2);
    if (diff != -1) {
        cout << "\nDifference in days between dates: " << diff << endl;
    }

    return 0;
}
