#include <stdio.h>

int main() {
    int r, c, i, j, key, found = 0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    printf("Enter elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (arr[i][j] == key) {
                printf("Element found at position (%d, %d)", i + 1, j + 1);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Element not found");
    }

    return 0;
}
