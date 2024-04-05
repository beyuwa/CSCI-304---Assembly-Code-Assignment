// Benjamin Y.
// CSCI 304 ('24 01)
// April Fools, 2024
// Section 1 (TR 2-3.5)
// Synopsis: Assignment 7, Summing 5i - 2!


#include <stdio.h>
#include <stdlib.h>


// Notes:
// (1) the major difference is that the array, instead of being offset in summation
// is handled in main with a "base" variabl reallocated as 10-n/10-i
// (2) assembly did not have a great way of for looping intuitively, so i had to add
// 25 + 5 = 30 to accomodate the run in the same loop as initilisation in y86


int summation(int n) // in y86 impl, it is explicit n = k
{   
    // Iter
    int sum = 0;
    int k = -1;
    int i;

    //Single
    while (k<n){
        
        k++;

        //Five
        for (i = 25; i > 0; i += -5){

            sum += k;

        }

        //Sum
        sum += -2;
        i = 25;

    }

    //Single cont. (post Five/Sum)
    return sum;
}



int main() 
{   
    int n = 10;         // << **hard codable location!!**
    int arr[n+1];
    n++;
    

    while (n>0){

        n--;
        arr[10-n] = summation(n);

    }

    // **not included in the y86 program**, but necessary to print
    
    for (int i = 0; i <= 10; i++){

        printf("%02d :   %03d   0x%08X\n", i, arr[10-i], arr[10-i]);
    
    }

    return EXIT_SUCCESS;
}