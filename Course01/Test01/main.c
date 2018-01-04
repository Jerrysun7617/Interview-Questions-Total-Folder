#include <stdio.h>
#include <math.h>						//提供pow原型

/* 函数原型 */
int Algo_1_20(int a[], int x, int n);

int main(int argc, char *argv[])
{
	int a[5] = {-2, 3, 6,-8, 7};
	int n = 5;
	int Xo = 3;

	printf("作为示范，设定项数n = 5，变量Xo = 3，计算Pn(Xo)...\n");
	printf("P%d(%d) = %d\n", n, Xo, Algo_1_20(a, Xo, n));
	printf("\n");

	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题1.20：计算多项式Pn(Xo)的值┃
┗━━━━━━━━━━━━━━*/
int Algo_1_20(int a[], int x, int n)
{
	int i;
	int tmp;

	for(i=1,tmp=0; i<=n; i++){
		tmp += a[i-1]*pow(x, i-1);
        printf("tmp= %d; pow(%d,%d) = %d\n",tmp,x,i-1,(int)pow(x,i-1));
    }
	return tmp;
}
