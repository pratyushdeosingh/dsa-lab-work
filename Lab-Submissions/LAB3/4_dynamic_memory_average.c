#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter size: ");
    scanf("%d", &n);

    int *p = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", p + i);

    int sum = 0;
    for(i = 0; i < n; i++)
        sum += *(p + i);

    float avg = (float)sum / n;
    printf("Average = %.2f", avg);

    free(p);
    return 0;
}
