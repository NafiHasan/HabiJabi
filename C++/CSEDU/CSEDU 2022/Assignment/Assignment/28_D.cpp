#include <stdio.h>

// defining structure
typedef struct{
    int id, year;
    char title[30], genre[30], author[30], language[30];
}books;
// computing length of a string
int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i;
    return len + 1;
}
// minimum of 2 integers
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
//string comparison
int strcomp(char a[], char b[])
{
    int mn = min(strlen(a), strlen(b));
    for (int i = 0; i < mn; i++)
    {
        if (b[i] > a[i])
            return -1;
        else if (b[i] < a[i])
            return 1;
    }
    if (mn == strlen(a) && mn == strlen(b))
        return 0;
    return 1;
}
// binary search for strings
int binary_search_string(books gen[], char s[], int n){
    int lo=0, hi=n-1, mid;
    while (lo<=hi){
        mid=(lo+hi)/2;
        if (strcomp(gen[mid].genre,s)==0) break;
        else if (strcomp(gen[mid].genre,s)==-1)lo=mid+1;
        else hi=mid-1;
    }
    for (int i=mid; i>=0; i--){
        if (strcomp(gen[i].genre, s) == 0)mid=i;
        else break;
    }
    return mid;
}
// binary search for number
int binary_search_num(books yr[], int y, int n){
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (yr[mid].year == y)
            break;
        else if (yr[mid].year < y)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    for (int i = mid; i >= 0; i--){
        if (yr[i].year == y)
            mid=i;
        else break;
    }
    return mid;
}
// performing mergesort
void merge (books* a, int lo, int mid, int hi, int type){
    int s1=mid-lo+1 , s2 = hi-mid;    // size of the temp arrays

    books left[s1], right[s2];    // temp arrays of structure for left and right parts

    for (int i=0; i<s1; i++) left[i]=a[lo+i];
    for (int i=0; i<s2; i++) right[i]=a[mid+1+i];
    
    int i=0, j=0, k=lo;
    // merging left and right subarrays into actual array
    while(i < s1 && j < s2){
        if (type ==4){
            if (strcomp(left[i].author , right[j].author)==-1)
                a[k++] = left[i++];
            else if (strcomp(left[i].author, right[j].author) == 0 && left[i].id <= right[j].id){
                a[k++] = left[i++];
            }
            else a[k++] = right[j++];
        } 
        else if (type == 2){
            if (left[i].year < right[j].year)
                a[k++] = left[i++];
            else if (left[i].year == right[j].year && left[i].id <= right[j].id)a[k++]= left[i++];
            else
                a[k++] = right[j++];
        }
        else if (type == 3){
            if (strcomp(left[i].title, right[j].title) == -1)
                a[k++] = left[i++];
            else if (strcomp(left[i].title, right[j].title) == 0 && left[i].id <= right[j].id)
                a[k++] = left[i++];
            else
                a[k++] = right[j++];
        }
        else if (type == 1){
            if (strcomp(left[i].genre, right[j].genre) == -1)
                a[k++] = left[i++];
            else if (strcomp(left[i].genre, right[j].genre) == 0 && left[i].id <= right[j].id)
                a[k++] = left[i++];
            else
                a[k++] = right[j++];
        }
        else{
            if (strcomp(left[i].language, right[j].language) == -1)
                a[k++] = left[i++];
            else if (strcomp(left[i].language, right[j].language) == 0 && left[i].id <= right[j].id)
                a[k++] = left[i++];
            else
                a[k++] = right[j++];
        } 
    }
    
    // for remaining elements if subarrays are not equal
    while(i < s1) a[k++] = left[i++];
    while(j < s2) a[k++] = right[j++];
}

void mergesort(books* a, int lo , int hi, int type){
    if (lo >= hi) return;
    int mid=(lo+hi)/2;
    // dividing arrays until there's one element left
    mergesort(a, lo, mid, type);
    mergesort(a, mid+1, hi, type);
    // merging the elements
    merge(a, lo, mid, hi, type);
}

int main (){
    int n,t;
    scanf("%d", &n);
    books auth[n], gen[n], titl[n], lang[n], yr[n];
    for (int i=0; i<n; i++){
        scanf("%d %s %s %s %s %d", &auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, &auth[i].year);
        gen[i]=auth[i];
        titl[i]=auth[i];
        lang[i]=auth[i];
        yr[i]=auth[i];
    }
    mergesort(auth,0,n-1,4);
    mergesort(yr,0,n-1,2);
    mergesort(titl,0,n-1,3);
    mergesort(gen,0,n-1,1);
    mergesort(lang,0,n-1,5);
    // for (int i=0; i<n; i++){
    //     printf("%d %s %s %s %s %d\n", auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, auth[i].year);
    // }
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        if(x<6 && x!=2){
            char next[30];
            scanf("%s",next);
            if (x==1){
                int ind=binary_search_string(gen,next, n);
                for (int i = ind; i < min(n, ind + 60); i++){
                    if (strcomp(next,gen[i].genre)==0)
                        printf("%d %s %s %s %s %d\n", gen[i].id, gen[i].title, gen[i].genre, gen[i].author, gen[i].language, gen[i].year);
                }
            }
            else if (x==3){
                int ind = binary_search_string(titl, next, n);
                for (int i = ind; i < min(n, ind + 60); i++){
                    if (strcomp(next, titl[i].title) == 0)
                        printf("%d %s %s %s %s %d\n", titl[i].id, titl[i].title, titl[i].genre, titl[i].author, titl[i].language, titl[i].year);
                }
            }
            else if (x == 4){
                int ind = binary_search_string(auth, next, n);
                for (int i = ind; i < min(n, ind + 60); i++)
                {
                    if (strcomp(next, auth[i].title) == 0)
                        printf("%d %s %s %s %s %d\n", auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, auth[i].year);
                }
            }
            else if (x == 5)
            {
                int ind = binary_search_string(lang, next, n);
                for (int i = ind; i < min(n, ind + 60); i++)
                {
                    if (strcomp(next,lang[i].title) == 0)
                        printf("%d %s %s %s %s %d\n", lang[i].id, lang[i].title, lang[i].genre, lang[i].author, lang[i].language, lang[i].year);
                }
            }
        }
        else if (x==2){
            int y;
            scanf("%d",&y);
            int ind = binary_search_num(yr, y, n);
            for (int i = ind; i < min(n, ind + 60); i++)
            {
                if (yr[i].year == y)
                    printf("%d %s %s %s %s %d\n", yr[i].id, yr[i].title, yr[i].genre, yr[i].author, yr[i].language, yr[i].year);
            }
        }
        else if(x==6){
            char next1[30],next2[30];
            scanf("%s",next1);
            scanf("%s",next2);
            int ind = binary_search_string(auth, next1, n);
            for (int i=ind ; i<min(n,ind +110); i++){
                if (strcomp(next1, auth[i].author) == 0 && strcomp(next2,auth[i].language)==0)
                    printf("%d %s %s %s %s %d\n", auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, auth[i].year);
            }
        }
        else if (x==7){
            char next1[30], next2[30];
            scanf("%s", next1);
            scanf("%s", next2);
            int ind = binary_search_string(auth, next1, n);
            for (int i = ind; i < min(n, ind + 110); i++){
                if (strcomp(next1, auth[i].author) == 0 && strcomp(next2, auth[i].title) == 0)
                    printf("%d %s %s %s %s %d\n", auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, auth[i].year);
            }
        }
        else if (x == 8){
            char next1[30], next2[30];
            scanf("%s", next1);
            scanf("%s", next2);
            int ind = binary_search_string(auth, next1, n);
            for (int i = ind; i < min(n, ind + 110); i++)
            {
                if (strcomp(next1, auth[i].author) == 0 && strcomp(next2, auth[i].genre) == 0)
                    printf("%d %s %s %s %s %d\n", auth[i].id, auth[i].title, auth[i].genre, auth[i].author, auth[i].language, auth[i].year);
            }
        }
        else {
            char next1[30], next2[30];
            scanf("%s", next1);
            scanf("%s", next2);
            int ind = binary_search_string(gen, next1, n);
            for (int i = ind; i < min(n, ind + 110); i++){
                if (strcomp(next1, gen[i].genre) == 0 && strcomp(next2, gen[i].language) == 0)
                    printf("%d %s %s %s %s %d\n", gen[i].id, gen[i].title, gen[i].genre, gen[i].author, gen[i].language, gen[i].year);
            }
        }
    }
    return 0;
}