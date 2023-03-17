#include <stdio.h>

void merge(int *a, int *b, int *final, int n, int m)
{
    int i=0, j=0, k=0;
    while (i < n && j < m){
        if (a[i] < b[j])
            final[k++] = a[i++];
        else
            final[k++] = b[j++];
    }
    while (i < n)
        final[k++] = a[i++];
    while (j < m)
        final[k++] = b[j++];
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m], final[n + m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    merge(a, b, final, n, m);
    for (int i = 0; i < n + m; i++) printf("%d ", final[i]);
    printf("\n");
    return 0;
}