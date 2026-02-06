#include <stdio.h>
void quickSort(int a[], int low, int high) {
    int i = low, j = high;
    int pivot = a[(low + high) / 2];
    int temp;
    while (i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(a, low, j);
    if (i < high)
        quickSort(a, i, high);
}
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
