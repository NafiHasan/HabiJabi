#include <stdio.h>

void merge(int *a, int *b, int *final, int i, int j, int k, int n, int m){
    if (i>=n && j>=m) return;
    if(i < n && j < m){
        if(a[i]<b[j]){
            final[k] = a[i];
            merge(a, b, final, i+1, j, k+1, n, m);
        }
        else {
            final[k] = b[j];
            merge(a, b, final, i, j + 1, k + 1, n, m);
        }
    }
    if (i < n && j >= m) {
        final[k] = a[i];
        merge(a, b, final, i + 1, j, k + 1, n, m);
    }
    if (j < m && i >= n) {
        final[k] = b[j];
        merge(a, b, final, i, j + 1, k + 1, n, m);
    }
}
int main (){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[n], b[m], final[n+m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    merge (a,b,final,0,0,0,n,m);
    for(int i=0; i<n+m; i++)printf ("%d ",final[i]);
    printf("\n");
    return 0;
}