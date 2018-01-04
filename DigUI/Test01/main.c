#include <stdio.h>
#include <stdlib.h>

int fundigui(int n)
{
    int t = 0;
    printf(" first = %d \n",t);
    if(n == 1)
    {
        t += 1;
    }
    else
        t += n+fundigui(n-1);
     printf("second = %d \n",t);
    return t;
}
int foo(int x, int y){
    int t = 0;
     printf("%d %d %d\n",x,y,t);
    if (x <= 0 || y <= 0)
        return 1;

    t = 3 * foo( x-6, y/2 );
   printf("%d %d %d\n",x,y,t);

    return t;
}
int main()
{
    int numi = 10;
   //for(numi = 0;numi < 10;numi++)
     //printf("\n%d\n",fundigui(numi));

     printf("\n%d\n", foo(20, 13));
    return 0;
}
