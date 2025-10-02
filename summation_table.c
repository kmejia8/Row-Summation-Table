/* Author: Karla Mejia
Summation Table Project

This code is provided here solely for educational and portfolio purposes.  
No permission is granted to copy, modify, or redistribute this code.  

*/

#include <stdio.h>
#define ROWS 5
#define COLS 5 // initialized to 5 as the fifth will be determined within the code

int main(void){
    printf("\n");
    // initializing the array, leaving the last column within the array undefined

    // since it's not initialized, 0 will be the place holder in that slot until the sum
    // is found
    int arr[ROWS][COLS] = { {1, 2, 4, 8},
                            {1, 3, 9, 27},
                            {1, 4, 16, 64},
                            {1, 5, 25, 125},
                            {1, 6, 36, 216} };
    
    // determining sum and setting it as the last element/column
    int row, col, sum, i;
    for (row = 0; row < ROWS; row++) { // goes through each row
        sum = 0; // need to reinitalize sum when going to the next row
        for (col = 0; col < COLS - 1; col++) { // goes through each column
            sum += arr[row][col]; // sums up all elements/columns in row
        }
        arr[row][COLS - 1] = sum; // assigns last element/column as sum
    }
    
    // printing header for table
    // account for space where row and number are printed
    printf("         "); 

    // loop for printing column + number
    // last column will be named SUM, so doing up until COLS - 1
    for (i = 0; i < COLS - 1; i ++) {
        printf("Col%d  ", i);
    }
    // printing last column
    printf("Sum\n");


    // printing the table
    int element, n;
    for(row = 0; row < ROWS; row++) {
        // printing row + number
        printf("Row%d", row);

        // creating a control variable to fix spacing depending on how 
        // many digits the element/column in the array has
        n = 10;

        for (col = 0; col < COLS; col++) {
            element = arr[row][col];

            // adds an extra space when the number in the array increases
            // by total number of digits
            if (element > n) {
                printf("%7d", element);
                // extra space handles as number of digits increases to 2
                // and to 3
                n *= 10;
            } else {
                // no extra space needed if number of digits in current
                // element/column matches the previous element's number
                // of digits
                printf("%6d", element);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}