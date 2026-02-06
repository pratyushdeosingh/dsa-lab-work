#include <stdio.h>

int main() {
    int r, c, i, j, sum = 0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    printf("Enter elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    printf("Sum = %d", sum);
    return 0;
}
