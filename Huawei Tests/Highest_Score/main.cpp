#include <iostream>
#include <stdio.h>
using namespace std;
int scores[30000];

int Find_Max(int x, int y)
{
    int Max = scores[x];
    for(int i = x+1;i <= y;i++){
        if(Max < scores[i])
            Max = scores[i];
    }

    return Max;
}
int main()
{
    int N = 0,M = 0;
    int K = 20;
    while(cin>>N>>M)
    {
        int Ni;

        int Highest = 0;

        for(Ni = 0; Ni < N;Ni++)
            cin>>scores[Ni];

        char com = ' ';
        int C1 = 0,C2 = 0;
        while(M--)
        {
            cin>>com>>C1>>C2;
            if(com == 'Q'){
                    if(C1 > C2)
                    {
                        int temp = C1;
                        C1 = C2;
                        C2 = temp;
                    }
                    Highest = Find_Max(C1-1,C2-1);
                    cout<<Highest<<endl;
            }
            else if (com == 'U')
                    scores[C1 - 1] = C2;
            else
                cout<<"input wrong"<<endl;

        }
    }

    return 0;
}
