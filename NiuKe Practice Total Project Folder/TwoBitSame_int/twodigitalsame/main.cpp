#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int digital = 0;
    while(scanf("%d",&digital) != EOF)
    {
        int diarray[100];
        int numi = 0;
        int result = 0;

        //using the array to store every bit of digital
        do{
            diarray[numi++] = digital%10;
            digital /= 10;
        }
        while(digital);

        cout<<numi<<endl;

        int ni,nj,nk;
        for(ni = numi - 1;ni > 1;ni--)
            for(nj = ni -1;nj > 0;nj--)
            {
                if(diarray[ni] == diarray[nj])
                {
                    if(diarray[ni - 1] == diarray[nj - 1])
                    {
                        result = 1;
                        break;
                    }
                }
            }
        cout<<result<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
