#include <stdio.h>
#include <time.h>

int a[20], n;

void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[high + 1];

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i];
            i++;
        } else {
            c[k++] = a[j];
            j++;
        }
    }

    while (i <= mid) {
        c[k++] = a[i];
        i++;
    }

    while (j <= high) {
        c[k++] = a[j];
        j++;
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_sort(a, low, mid, high);
    }
}

int main() {
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nTime taken to sort elements: %f seconds\n", time_taken);

    return 0;
}

