#include <stdio.h>

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0; 
    int fib1 = 1; 
    int fib = fib1 + fib2;

    // Find the smallest Fibonacci Number greater than or equal to n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        // If x is greater than the value at index fib2 , Move Backward by 1 step
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        // If x is less than the value at index fib2, Move Backward by 2 step
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        // If x is found
        else
            return i;
    }

    if (fib1 && arr[offset + 1] == x){
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;
    int result = fibonacciSearch(arr, n, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");
    return 0;
}