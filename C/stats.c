#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calculate_mean(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

float calculate_median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void calculate_mode(int arr[], int n) {
    int maxCount = 0;
    int modeValue[MAX];
    int modeIndex = 0;
    
    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j])
                count++;
        }

        if(count > maxCount) {
            maxCount = count;
            modeValue[0] = arr[i];
            modeIndex = 1;
        } else if(count == maxCount && arr[i] != modeValue[modeIndex-1]) {
            modeValue[modeIndex++] = arr[i];
        }
    }

    if (maxCount == 1) {
        printf("No mode found.\n");
    } else {
        printf("Mode(s): ");
        for(int i = 0; i < modeIndex; i++)
            printf("%d ", modeValue[i]);
        printf("\n");
    }
}

int main() {
    int arr[MAX], n;

    printf("Enter the total count of numbers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Mean: %.2f\n", calculate_mean(arr, n));
    printf("Median: %.2f\n", calculate_median(arr, n));
    calculate_mode(arr, n);

    return 0;
}
