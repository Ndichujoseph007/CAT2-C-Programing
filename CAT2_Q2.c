/*

NAME :Joseph Ndichu;
Reg No.:CT100/G/26139/25
Description:CAT2_Q2.Wage and tax calculation
*/



#include <stdio.h>

int main() {
    float hoursWorked, hourlyWage, grossPay, taxes, netPay;
    
    
   // Get input from the user
   // Maximum hours in a week
   
        do {
        printf("Enter hours worked in a week (maximum 168 hours): ");
        scanf("%f", &hoursWorked);
        if (hoursWorked > 168) {
            printf("Error: Hours worked cannot exceed 168. Please enter again.\n");
        }
    } while (hoursWorked > 168);

    
    printf("Enter hourly wage: ");
    scanf("%f", &hourlyWage);

    // Calculate gross pay
    if (hoursWorked <= 40) {
        grossPay = hoursWorked * hourlyWage;
    } else {
        grossPay = 40 * hourlyWage + (hoursWorked - 40) * 1.5 * hourlyWage;
    }

    // Calculate taxes
    if (grossPay <= 600) {
        taxes = 0.15 * grossPay;
    } else {
        taxes = 0.15 * 600 + 0.20 * (grossPay - 600);
    }

    // Calculate net pay
    netPay = grossPay - taxes;

    // Print the results
    printf("Gross pay: $%.2f\n", grossPay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", netPay);

    return 0;
}