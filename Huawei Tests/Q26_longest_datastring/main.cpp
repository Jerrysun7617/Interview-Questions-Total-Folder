#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct num_str{
    int num;
    char nums[1000];
};
int main()
{
    char str[1000];

    while(gets(str)){
        int i= 0,j = 0,k = -1;
       bool flag = false;
        int length = strlen(str);
       int longest_num = 0;
       struct num_str ns[1000] ={0};;
       for(i = 0;i < length;i++)
       {
           if(str[i] >= '0' && str[i] <= '9')
           {
               if(!flag){
                flag = true;
                k++;
               }

                ns[k].num++;
                ns[k].nums[j++] = str[i];
           }
           else{
            j = 0;
            flag = false;
           }
       }
        struct num_str maxs;
        for(i = 0;i < k;i++) // may there is more one the biggest
            for(j=i+1;j<k + 1;j++)

            {
                if(ns[i].num<ns[j].num)
                {
                    maxs= ns[i];
                    ns[i] = ns[j];
                    ns[j] = maxs;
                }
            }

        cout<<ns[0].nums<<endl;
        for(i = 1;i < k + 1;i++)
            if(ns[i].num == ns[0].num)
                cout<<ns[i].nums<<endl;
            else
                break;

    }


    cout << "Hello world!" << endl;
    return 0;
}
