#include <iostream>
#include <string.h>
using namespace std;

struct symetry{
    int num;
    int position;
};
int main()
{
    char  str[1000];

    while(cin>>str)
    {
        int i,j,k;
        int length = strlen(str);
        struct symetry sy[1000] ={0};;
        //choose the centre
        for(i = 1;i < length - 1; i++)
        {
            j = i - 1;
            k = i + 1;
            sy[i].num = 0;
            sy[i].position = i;
            while(j>=0 && k<length)
            {
                if(str[j--] == str[k++]){
                     sy[ i].num++;
                }
                else
                    break;
            }
        }

        for(i = 0; i < length - 1;i++)
            for(j = i +1;j <length; j++)
        {
            if(sy[i].num < sy[j].num)
            {
                struct symetry md;
                md = sy[i];
                sy[i] = sy[j];
                sy[j] = md ;
            }
        }
        // the 0
        for(i = 0; i < length;i++)
        {
            if(sy[0].num == sy[i].num){
                for(j = sy[i].position - sy[i].num; j < 1 + sy[i].num  + sy[i].position;j++)
                    cout<<str[j];
                cout<<endl;
            }
        }

    }

    cout << "Hello world!" << endl;
    return 0;
}
