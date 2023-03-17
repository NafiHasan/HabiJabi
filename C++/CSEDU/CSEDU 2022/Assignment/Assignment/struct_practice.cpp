#include <stdio.h>
#include <string.h>

typedef struct{
    char first[20];
    char second[20];
} namepart;

typedef struct{
    int id;
    namepart name;
    char grade[3];
}student;

int main()
{
    student one;
    
    scanf("%d ",&one.id);
    scanf("%s",one.name.first);
    scanf("%s",one.name.second);

    printf("id : %d\n",one.id);
    printf("Name : %s %s\n",one.name.first, one.name.second);

    return 0;
}