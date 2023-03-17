#include <stdio.h>

bool isvowel(char x){
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')return true;
    else return false;
}
int main()
{
    int a[26];
    for(int i=0; i<26; i++)a[i]=0;
    char c=getchar();
    while(c!=EOF){
        int x = c - 97;
        if (x>=0 && x<26)a[x]++;
        c=getchar();
    }
    char ansv[26], ansc[26], ansc2[26], ansv2[26];
    for (int i=0; i<26; i++){
        ansv[i]='0',ansc[i]='0';
        ansv2[i] = '0', ansc2[i] = '0';
    }
    int mxv=0,mxc=0;
    for (int i=0; i<26; i++){
        char x=i+97;
        if (isvowel(x) && mxv<a[i])
            mxv=a[i];
        else if (!isvowel(x) && mxc < a[i])
            mxc=a[i];
    }
    for (int i=0; i<26; i++){
        char x = i + 97;
        if (isvowel(x) && mxv==a[i]){
            ansv[i] = x;
            a[i]=0;
        }
        else if (!isvowel(x) && mxc == a[i]){
            ansc[i] = x;
            a[i]=0;
        }
    }
    mxv=0,mxc=0;
    for (int i = 0; i < 26; i++){
        char x = i + 97;
        if (isvowel(x) && mxv < a[i])
            mxv = a[i];
        else if (!isvowel(x) && mxc < a[i])
            mxc = a[i];
    }
    for (int i = 0; i < 26; i++){
        char x = i + 97;
        if (isvowel(x) && mxv == a[i])
            ansv2[i] = x;
        else if (!isvowel(x) && mxc == a[i])
            ansc2[i] = x;
    }
    bool found=false;
    if(mxv>0 && mxc>0){
        for (int i = 0; i < 26; i++){
            if (ansc[i] != '0'){
                for (int j = 0; j < 26; j++){
                    if (ansv[j] != '0'){
                        for (int k = 0; k < 26; k++){
                            if (mxv > mxc){
                                if (ansv2[k] != '0'){
                                    for (int l = 0; l < 26; l++){
                                        if (ansc2[l] != '0'){
                                            printf("%c%c%c%c\n", ansc[i] - 32, ansv[j] - 32, ansv2[k] - 32, ansc2[l] - 32);
                                            found = true;
                                        }
                                    }
                                }
                            }
                            else if (mxv < mxc){
                                if (ansc2[k] != '0'){
                                    for (int l = 0; l < 26; l++){
                                        if (ansv2[l] != '0'){
                                            printf("%c%c%c%c\n", ansc[i] - 32, ansv[j] - 32, ansc2[k] - 32, ansv2[l] - 32);
                                            found = true;
                                        }
                                    }
                                }
                            }
                            else{
                                if (ansv2[k] != '0' || ansc2[k] != '0'){
                                    char x;
                                    if (ansv2[k] != '0')
                                        x = ansv2[k];
                                    else
                                        x = ansc2[k];
                                    if (isvowel(x) == true){
                                        if (ansv2[k] != '0'){
                                            for (int l = 0; l < 26; l++){
                                                if (ansc2[l] != '0'){
                                                    printf("%c%c%c%c\n", ansc[i] - 32, ansv[j] - 32, ansv2[k] - 32, ansc2[l] - 32);
                                                    found = true;
                                                }
                                            }
                                        }
                                    }
                                    else{
                                        if (ansc2[k] != '0'){
                                            for (int l = 0; l < 26; l++){
                                                if (ansv2[l] != '0'){
                                                    printf("%c%c%c%c\n", ansc[i] - 32, ansv[j] - 32, ansc2[k] - 32, ansv2[l] - 32);
                                                    found = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!found){
        printf("Warning!! Insufficient Text!!\n");
    }
    return 0;
}