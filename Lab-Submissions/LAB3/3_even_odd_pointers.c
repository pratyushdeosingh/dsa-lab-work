#include <stdio.h>

int main() {
    int n, i, even = 0, odd = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    int *p = a;

    for(i = 0; i < n; i++) {
        if(*(p + i) % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even = %d\nOdd = %d", even, odd);
    return 0;
}
