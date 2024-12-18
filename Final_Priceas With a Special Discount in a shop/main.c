#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int key = 0;
    int *prices = NULL;
    int input;
    int size = 0;
    while(key == 0)
    {

        printf("Enter the price: ");
        scanf("%d", &input);
        // Stop if the user enters -1
        if (input == -1) {
            break;
        }
        
        // Allocate space for one more integer
        int *temp = (int *)realloc(prices, (size + 1) * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(prices); // Free memory before exiting in case of failure
            return 1;
        }
        prices = temp;

        // Add the new integer to the list
        prices[size++] = input;
    }

    for(int i=0; i<size; i++)
    {
        printf("%d \n", prices[i]);
    }
    if (size == 0) {
        printf("The list is empty.\n");
        return 0;
    }
    int newprice[size];

    for(int i = 0; i < size-1; i++)
    {
        int cont = 1;
        for(int j = i+1; j < size; j++)
        {
            if(prices[j] <= prices[i])
            {
                printf("prices[%d] = %d <= prices[%d] = %d\n", j, prices[j], i, prices[i]);
                for(int k = j-cont;k<j;k++)
                {
                    
                    newprice[k] = prices[k] - prices[j];
                    printf("newprice[%d] = %d - %d = %d\n", k, prices[k], prices[j], newprice[k]);
                }
                break;
            }
            else
            {
                printf("de brhka tipots mprosta mou\n");
                cont+=1;
            }
            printf("bghka apo to j loop\n");
        }
        for(int k = size-cont;k<size;k++)
        {
            newprice[k] = prices[k];
            printf("newprice[%d] = %d\n", k, prices[k]);
        }
    }
    for(int i = 0; i < size; i++)
    {
       printf("%d ", newprice[i]);
    
    }
    printf("Done");

    free(prices);
    return 0;
}