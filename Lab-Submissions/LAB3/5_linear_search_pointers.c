#include <stdio.h>

int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int *p = a;

    for(i = 0; i < n; i++) {
        if(*(p + i) == key) {
            printf("Element found at position %d", i + 1);
            return 0;
        }
    }

    printf("Element not found");
    return 0;
}
