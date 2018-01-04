#include <stdio.h>
#include <stdlib.h>
#include <stack>

int main()
{
    char test[100][20];
    int numi,numy,numz;
    stack <char *> s;
    while(1){
            numi = 0;
        while(scanf("%s",test[numi++]) != '\n');

        for(numy = 0;numy < numi;numy++)
         printf("%s ",test[numy]);
        //s.push();

    }
    printf("Hello world!\n");
    return 0;
}
