#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct Student
{
	int id, roll, number1, number2;
	char name[50], subject1[50];
};

void sort_structure(Student *ara){
	for (int i=0; i<4; i++){
		for (int j=i+1; j<5; j++){
			if(ara[i].roll > ara[j].roll){
				Student temp = ara[i];
				ara[i] = ara[j];
				ara[j] = temp;
			}
			else if(ara[i].roll == ara[j].roll){
				for (int ii=0; ara[i].name[ii] != '\0'; ii++){
					
				}
			}
		}
	}
}


int main()
{
	fast_io();
 	Student ara[5];
 	for (int i=0; i<5; i++){
 		cin >>  ara[i].roll >> ara[i].name;
 	}
 	sort_structure(ara);
 	for (int i=0; i<5; i++){
 		cout << ara[i].name << '\n';
 	}
    return 0;
}