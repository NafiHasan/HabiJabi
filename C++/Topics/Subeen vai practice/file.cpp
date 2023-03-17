#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    FILE *fp;
    char filename[] = "my_file.txt";

    fp = fopen(filename, "w");


    fprintf(fp , "This is a file created by my program! ");
    fprintf( fp, "NIce.");

    fclose(fp);   
    
    return 0;
}