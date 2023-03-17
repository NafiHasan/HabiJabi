#include <bits/stdc++.h>

int char_to_int(char a[]){
    int num=0;
    num+=(a[0]-97)*26*26*26 + (a[1]-97) * 26*26 + (a[2]-97)*26 + a[3]-97;
    return num;
}

void int_to_char(int n){
    char a[5];
    a[3]=(n%26)+97;
    if (n%26==0)a[3]='a'; 
    n/=26;
    a[2]= (n%26)+97;
    if (n % 26 == 0)
        a[2] = 'a';
    n/=26;
    a[1]= (n%26)+97;
    if (n % 26 == 0)
        a[1] = 'a';
    n/=26;
    a[0]=n+97;
    if (n==0)a[0]='a';
    printf("%s\n",a);
}

int main(){
    char s;
    int cnt[500000];  //counter for the strings
    for (int i = 0; i < 500000; i++) cnt[i] = 0;

    int mx = 0,a=0;
    while(1){
        s=getchar();
        if (s == EOF)
            break;            //taking inputs until end of line
        char tmp[5];          // temp string to keep the 4 length strings
        if (a<=3)tmp[a]=s;
        else {
            tmp[0] = tmp[1], tmp[1] = tmp[2], tmp[2] = tmp[3], tmp[3] = s;   //taking new inputs in the char array
        }
        a++;
        
        if (a>3){
            cnt[char_to_int(tmp)]++;     //converting string into number to keep the track in array
            if (cnt[char_to_int(tmp)] > mx) mx = cnt[char_to_int(tmp)];
        }
    }
    for (int i = 0; i<500000 ; i++){
        if (cnt[i] != mx)
            cnt[i] = 0;
    }
    for (int i = 0; i<500000; i++){
        if (cnt[i]) int_to_char(i);
    }
    return 0;
}