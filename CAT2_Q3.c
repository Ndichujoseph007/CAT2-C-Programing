/*

NAME :Joseph Ndichu;
Reg No.:CT100/G/26139/25
Description:CAT2_Q3.File handling
*/



#include <stdio.h>
#include <stdlib.h>

// Function to prompt the user for 10 integers and store them in "input.txt"
void writeIntegersToFile() {
    FILE *inputFile;
    int num;
    int i;

    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        perror("Error opening input.txt for writing");
        return;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &num);
        fprintf(inputFile, "%d\n", num);
    }

    fclose(inputFile);
    printf("Integers written to input.txt successfully.\n");
}

// Function to read integers from "input.txt", calculate sum and average, and write to "output.txt"
void calculateSumAndAverage() {
    FILE *inputFile, *outputFile;
    int num, sum = 0, count = 0;
    float average;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt for reading");
        return;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output.txt for writing");
        fclose(inputFile);
        return;
    }

    while (fscanf(inputFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(inputFile);

    if (count > 0) {
        average = (float)sum / count;
        fprintf(outputFile, "Sum: %d\n", sum);
        fprintf(outputFile, "Average: %.2f\n", average);
        printf("Sum and average written to output.txt successfully.\n");
    } else {
        fprintf(outputFile, "No numbers found in input.txt\n");
        printf("No numbers found in input.txt.\n");
    }

    fclose(outputFile);
}

// Function to read and display the contents of "input.txt" and "output.txt"
void displayFileContents() {
    FILE *inputFile, *outputFile;
    int ch;

    printf("\nContents of input.txt:\n");
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt for reading");
        return;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        printf("%c", ch);
    }

    fclose(inputFile);

    printf("\nContents of output.txt:\n");
    outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        perror("Error opening output.txt for reading");
        return;
    }

    while ((ch = fgetc(outputFile)) != EOF) {
        printf("%c", ch);
    }

    fclose(outputFile);
}

int main() {
    writeIntegersToFile();
    calculateSumAndAverage();
    displayFileContents();

    return 0;
}