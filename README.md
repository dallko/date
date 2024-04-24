The function isValidDate(int day, int month, int year) determines the validity of a given date. By taking into account leap years for February, it guarantees that the day falls between the acceptable range for the specified month and year, the month is between 1 and 12, and the year is positive.

getDayOfWeek(int day, int month, int year)
This function uses Zeller's Congruence method to determine the day of the week for a given date. The day of the week is represented by an integer that is returned (0 for Saturday, 1 for Sunday,..., 6 for Friday).

printDate(const vector<int>, date)
This function converts a date represented by a vector of numbers (day, month, year) into a string of the type "DD.MM.YYYY (DayOfWeek)".

inputDate()
This function asks the user to provide a date in the "DD.MM.YYYY" format and outputs the day, month, and year as a vector of numbers.

calculateDifference(const vector<int>& date1, const vector<int>& date2)
This function computes the difference in days between two dates. It first checks the input dates with isValidDate() before iterating through them and incrementing a counter until it reaches the later date.

Once both dates are validated and formatted, the program prints the entered dates along with their corresponding day of the week.
It then calculates and displays the difference in days between the dates.

If any error occurs during input processing, date validation, or difference calculation, the program displays an error message and terminates.

The main() function orchestrates the execution flow by coordinating input, processing, and output operations.
It ensures that the program follows a logical sequence of steps to provide the user with the desired functionality.
