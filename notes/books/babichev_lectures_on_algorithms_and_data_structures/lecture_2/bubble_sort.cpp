void bubblesort(int *a, int n) { bool sorted = false; while (!sorted) { sorted = true; for (int i = 0; i < n-1; i++) { if (a[i] > a[i+1]) { int tmp = a[i]; a[i] = a[i+1]; a[i+1] = tmp; sorted = false;
} } } }





void insertion(int *a, int n) { for (int i = n-1; i > 0; i--) { if (a[i-1] > a[i]) { int tmp = a[i-1]; a[i-1] = a[i]; a[i] = tmp;
} }
for (int i = 2; i < n; i++) { int j = i; int tmp = a[i]; while (tmp < a[j-1]) { a[j] = a[j-1]; j--;
}
a[j] = tmp; } }