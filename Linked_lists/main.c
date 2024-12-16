#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <math.h> // For malloc and free

// Function to convert a number to a linked list of digits
int* number_to_ll(int number, int* size) {
    int temp = number;
    int _number = number;
    *size = 0;

    // Count the number of digits
    while (temp > 0) {
        temp /= 10;
        (*size)++;
    }

    // Allocate memory for the digits (linked list)
    int* linked_list = (int*)malloc(*size * sizeof(int));

    if (linked_list == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Store the digits in reverse order
    for (int i =0; i <=  *size - 1; i++) {
        linked_list[i] = number % 10;
        number /= 10;
    }

    // Print the linked list
    printf("Linked list for number: %i ", _number);
    for (int i = 0; i < *size; i++) {
        if (i == *size - 1) {
            printf("%d", linked_list[i]);
        } else {
            printf("%d -> ", linked_list[i]);
        }
    }
    printf("\n");

    return linked_list; // Return the dynamically allocated array
}

int ll_to_number(int* ll, int size){
    int number = 0;
    for(int i = 0; i<size;i++){
        number += ll[i]*pow(10,i);
    }
    return number;
}

int main() {
    int ll1[] = {5,3,6};
    int ll2[] = {9,3,9};
    int size1 = sizeof(ll1) / sizeof(ll1[0]);
    int size2 = sizeof(ll2) / sizeof(ll2[0]);
    int num1 = ll_to_number(ll1, size1);
    int num2 = ll_to_number(ll2, size2);

    int add = num1+num2;

    int size;
    int* result = number_to_ll(add, &size);
    
    // Get the linked list representation
    //int* ll = number_to_ll(number, &size);

    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%i ", result[i]);
    }
    printf("\n");

    return 0;
}






int give_inputs_manually() {
    int size1, size2;

    // Ask the user for the size of the first array
    printf("Enter the number of digits for the first number: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for the first array
    int *l1 = (int *)malloc(size1 * sizeof(int));
    if (l1 == NULL) {
        printf("Memory allocation failed for the first number.\n");
        return 1;
    }

    // Ask the user for the size of the second array
    printf("Enter the number of digits for the second number: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        free(l1); // Free the memory for the first array
        return 1;
    }

    // Allocate memory for the second array
    int *l2 = (int *)malloc(size2 * sizeof(int));
    if (l2 == NULL) {
        printf("Memory allocation failed for the second number.\n");
        free(l1); // Free previously allocated memory
        return 1;
    }

    // Populate the first array
    printf("Enter %d digits for the first number:\n", size1);
    for (int i = 0; i < size1; i++){
        if (scanf("%d", &l1[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(l1);
            free(l2);
            return 1;
        }
    }

    // Populate the second array
    printf("Enter %d digits for the second number:\n", size2);
    for (int i = 0; i < size2; i++) {
        if (scanf("%d", &l2[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(l1);
            free(l2);
            return 1;
        }
    }

    // Print the arrays for verification
    printf("First number digits: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", l1[i]);
    }
    printf("\n");

    printf("Second number digits: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", l2[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(l1);
    free(l2);

    return 0;
}

