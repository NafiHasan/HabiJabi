#include <stdio.h>

int main()
{
    int X,N;
    scanf("%d %d", &X, &N);
    int turn = 1, found = 0;
    while (turn <= N)
    {
        int a;
        scanf("%d", &a);
        if (a != X)
            printf("Wrong, %d Chance(s) Left!\n", N - turn);
        else if (a == X)
        {
            printf("Right, Player-2 wins!\n");
            found = 1;
            break;
        }
        turn++;
    }
    if (!found)
        printf("Player-1 wins!\n");
    return 0;
}