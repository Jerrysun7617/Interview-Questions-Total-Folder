#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int numi = 0;

    while(scanf("%d",&numi) != EOF)
    {
        if(numi == 0)
            break;
        int i,j,k;
        int arrayN[1000];

        for(i = 0; i <numi;i++)
            cin>>arrayN[i];

         // delete the same num;
         for(i = 0; i < numi;i++)
            for(j = i+1;j<numi;j++)
            {
                if(arrayN[i] == arrayN[j])
                {
                    for(k = j; k <numi- 1;k++)
                        arrayN[k] = arrayN[k+1];
                    j--; // here should be careful
                    numi--;
                }
            }

        for(i = 0; i < numi - 1;i++)
            for(j = i+1;j<numi;j++)
            {
                if(arrayN[i] > arrayN[j])
                {
                     int exchange = arrayN[i];
                     arrayN[i] = arrayN[j];
                     arrayN[j] = exchange;

                    /*
                    arrayN[i] = arrayN[i] + arrayN[j];
                    arrayN[j] = arrayN[i] - arrayN[j];
                    arrayN[i] = arrayN[i] - arrayN[j];
                    */
                }
            }

        for(i = 0;i<numi;i++)
            cout<<arrayN[i]<<endl;
    }

    return 0;
}
