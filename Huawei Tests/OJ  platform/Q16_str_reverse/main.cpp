#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct reverseT{
    char Rstr[100];
};
int main()
{
    int i,j,k;
    reverseT rev[1000];
    char Tstr[1000];

    while(gets(Tstr))
    {
        j = 0,k = 0;
        for(i = 0;i < strlen(Tstr);i++)
        {
            if(Tstr[i] == ' '){
                k  = 0;
                j++;
            }
             else{
                rev[j].Rstr[k++] = Tstr[i];
             }
        }
        while(j>=0)
        {
            cout<<rev[j--].Rstr<<' ';
        }
        cout<<endl;
    }


    cout << "Hello world!" << endl;
    return 0;
}
