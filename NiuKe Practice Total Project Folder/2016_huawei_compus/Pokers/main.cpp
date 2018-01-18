#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct poker{
    int lth;
    char pai[50];
};
int main()
{
    char str[100];
    //3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
    while(gets(str) != NULL){
        //compare two pockers
        //关系
        int state = 0; // 0 error 1 front 2 after
        struct poker pfr ={0};;
        struct poker paf ={0};;
        int i,j = 0,k = 0;
        int lth = strlen(str);

        bool flag = true;
        for(i = 0; i < lth;i++)
        {
             if(str[i] == '-')
                flag = false;
            else{
                 if(flag)
                 {
                    pfr.pai[j++] = str[i];
                 }
                 else{
                    paf.pai[k++] = str[i];
                 }
            }
        }

        //分开了 个子 1  对子 3 顺子 9 三个 5 炸弹  7 对王 11 6种情况
        pfr.lth = strlen(pfr.pai);
        paf.lth = strlen(paf.pai);
        switch(pfr.lth)
        {
            case 1:
                if(paf.lth == 1)
                {
                    if(pfr.pai[0] == 'A')
                        state = 1;
                    else if(paf.pai[0] == 'A')
                        state = 2;
                    else if(pfr.pai[0] > paf.pai[0])
                        state = 1;
                    else
                        state = 2;
                }
                else if (paf.lth == 2)
                {
                    if(pfr.pai[0] <= '9')
                        state = 2;
                    else
                        state = 1;
                }
                else if (paf.lth == 7 || paf.lth  == 11)
                    state = 2;
                break;
             case 2:
                if(paf.lth == 1)
                {
                    if(paf.pai[0] <= '9')
                        state = 1;
                    else
                        state = 2;
                }
                else if (paf.lth == 7 || paf.lth  == 11)
                    state = 2;
                break;
            case 3:
                if(paf.lth == 3)
                {
                    if(pfr.pai[0] > paf.pai[0]){
                        state = 1;
                    }
                    else
                        state = 2;
                }
                else if (paf.lth == 5)
                {
                    if(paf.pai[0] == paf.pai[3])
                    {
                        if(paf.pai[0] <= '9')
                            state = 2;
                        else
                            state = 1;
                    }
                }
                else if (paf.lth == 7 || paf.lth  == 11)
                    state = 2;
                break;
             case 9:
                if(paf.lth == 9)
                {
                    if(pfr.pai[0] > paf.pai[0]){
                        state = 1;
                    }
                    else
                        state = 2;
                }
                else if(paf.lth == 10)
                    state = 2;
                else if (paf.lth == 7 || paf.lth  == 11)
                    state = 2;
                break;
             case 10:
                 state = 1;
                 break;
             case 5:
                 //2
                 if(pfr.pai[0] == pfr.pai[3]) // 10 10
                 {
                    if(paf.lth == 3)
                    {
                        if(paf.pai[0] <= '9')
                            state = 1;
                        else
                            state = 2;
                    }
                 }
                else{
                    if(paf.lth == 5)
                    {
                        if(pfr.pai[0] > paf.pai[0]){
                            state = 1;
                        }
                        else
                            state = 2;
                    }
                    else if (paf.lth == 7 || paf.lth  == 11)
                        state = 2;
                }
                break;
             case 7:
                if(paf.lth == 7)
                {
                    if(pfr.pai[0] > paf.pai[0]){
                        state = 1;
                    }
                    else
                        state = 2;
                }
                else if ( paf.lth  == 11)
                    state = 2;
                else
                     state = 1;
                break;
             case 11:
                state = 1;
                break;
        }

        if(state == 0)
            cout<<"ERROR"<<endl;
        else if (state == 1)
            cout<<pfr.pai<<endl;
        else
             cout<<paf.pai<<endl;

    }


    return 0;
}
