#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N = 0,M = 0;
    int K = 20;
    while(scanf("%d %d",&N,&M) != EOF)
    {
        int Ni = 0;
        int scores[30000] = {0};
        int Highest = 0;

        for(Ni = 0; Ni < N; Ni++)
            cin>>scores[Ni];

        char com = ' ';
        int C1 = 0,C2 = 0;
        while(M--)
        {
            cin>>com>>C1>>C2;
            if(com == 'Q')
            {
                if(C1 > C2)
                {
                    C1 = C1 + C2;
                    C2 = C1 - C2;
                    C1 = C1 - C2;
                }
                //cout<<"C1 = "<<C1<<";C2 = "<<C2<<endl;
                Highest = scores[C1 -1];
                for(Ni = C1; Ni < C2; Ni++)
                    if(Highest < scores[Ni])
                        Highest  = scores[Ni];
                cout<<Highest<<endl;
            }
            else if(C1 <= N)
                scores[C1 - 1] = C2;

        }
    }

    return 0;
}
