/* 
NAME :Joseph Ndichu;
Reg No.:CT100/G/26139/25
Description:CAT_2,Arrays on 2D
*/


#include <stdio.h>


int main() {
    
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };
    int i,j;

    printf("Elements of the 2D array 'scores' are:\n");

    // Outer loop for rows
    for (i = 0; i < 2; i++) {
        // Inner loop for columns
        for (j = 0; j < 2; j++) {
            printf("%d \n", scores[i][j]);
        }
    }

    return 0;
}