#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int emptybt = 0;

    while(scanf("%d",&emptybt) != EOF)
    {
        //printf("%d\n",emptybt);
        if(emptybt <= 0)
            break;
        int enable_bot = 0;
        int current_brink = emptybt;

        while(emptybt > 2)
        {
            current_brink = (emptybt/3);
            enable_bot  += (emptybt/3);
            emptybt %= 3;
            emptybt += current_brink;
        }
        if(emptybt == 2)
            enable_bot++;
        cout<<enable_bot<<endl;
    }
    return 0;
}
