#include <stdio.h>

void merge(int *a, int s, int m, int e)
{
    int i = s, j = m+1, k = 0;
    int final[e-s+1];
    while (i <= m && j <= e){
        if (a[i] < a[j])
            final[k++] = a[i++];
        else
            final[k++] = a[j++];
    }
    while (i <= m)
        final[k++] = a[i++];
    while (j <= e)
        final[k++] = a[j++];
    for (int ii=s,jj=0; ii<=e; ii++,jj++) a[ii]=final[jj];
}
int main()
{
    return 0;
}