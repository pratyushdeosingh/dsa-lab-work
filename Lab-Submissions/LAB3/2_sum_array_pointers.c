#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], i;
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    int *p = a;
    int sum = 0;

    for(i = 0; i < n; i++)
        sum += *(p + i);

    printf("Sum = %d", sum);
    return 0;
}
