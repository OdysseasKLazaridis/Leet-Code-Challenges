#include <stdio.h>

int maxChunksToSorted(int* arr, int n) {
    int max_seen = 0;
    int chunks = 0;
    
    for (int i = 0; i < n; i++) {
        max_seen = (arr[i] > max_seen) ? arr[i] : max_seen; // Update the max seen
        if (max_seen == i) {
            chunks++; // Found a valid chunk
        }
    }
    
    return chunks;
}

int main() {
    int arr[] = {1,0,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = maxChunksToSorted(arr, n);
    printf("The largest number of chunks is: %d\n", result);
    
    return 0;
}
