#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    int *p = a;
    int max = *p;

    for(i = 1; i < n; i++) {
        p++;
        if(*p > max)
            max = *p;
    }

    printf("Largest element = %d", max);
    return 0;
}
