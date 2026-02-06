#include <stdio.h>

int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(*(a + mid) == key) {
            printf("Element found at position %d", mid + 1);
            return 0;
        }

        if(*(a + mid) < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found");
    return 0;
}
