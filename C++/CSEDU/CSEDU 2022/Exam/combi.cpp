#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void compfiles(FILE *file1, FILE *file2){
	char ch1 = getc(file1);
	char ch2 = getc(file2);

	int error = 0, line = 1, pos = 0 ;
	while(ch1 != EOF && ch2 != EOF){
		pos++;
		if(ch1 == '\n' && ch2 == '\n'){
			line++;
			pos = 0;
		}
		if(ch1 != ch2){
			error++;
			cout << "Line and pos = " << line << ' ' << pos<< '\n';
			cout << "You wrote " << ch2 << " instead of " << ch1 << '\n';
		}
		ch1 = getc(file1);
		ch2 = getc(file2);
	}
	cout << "Total Errors: " << error << '\n';
}



int main()
{
	fast_io();
 	FILE *file1= fopen("file1.txt", "r");
 	FILE *file2 = fopen ("file2.txt", "r");
 	if(file1 == NULL || file2 == NULL){
 		cout << "ERROR in file opening\n";
 	}
 	compfiles(file1, file2);
 	fclose(file1);
 	fclose(file2);
    return 0;
}