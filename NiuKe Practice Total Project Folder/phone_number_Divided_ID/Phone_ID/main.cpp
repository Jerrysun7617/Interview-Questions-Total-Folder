#include <iostream>ii
#include<stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int count_Z;
    int count_W;
    int count_X;
    int count_G;
    int count_S;
    int count_V;
    int count_H;
    int count_O;
    int count_I;
    int count_F;

    int count_0;
    int count_1;
    int count_2;
    int count_3;
    int count_4;
    int count_5;
    int count_6;
    int count_7;
    int count_8;
    int count_9;

}get_data;

int main()
{
    //string test = "hello";
   //int numc =  count(test.begin(),test.end(),'l');
   //printf("%d\n",numc);

    int i , j;
    int numbit =0;
    vector <string>  getc;
    string teststr;
    get_data get_value[200];
    while(scanf("%d",&numbit) != EOF)
    {
        for(i = 0; i < numbit ;i++){
                cin>>teststr;
            getc.push_back(teststr);
        }
        for(i = 0; i < numbit;i++){
            //cout << getc[i] <<endl;
           get_value[i].count_Z = count(getc[i].begin(),getc[i].end(),'Z');
           get_value[i].count_W = count(getc[i].begin(),getc[i].end(),'W');
           get_value[i].count_X = count(getc[i].begin(),getc[i].end(),'X');
           get_value[i].count_G = count(getc[i].begin(),getc[i].end(),'G');
           get_value[i].count_S = count(getc[i].begin(),getc[i].end(),'S');

           get_value[i].count_V = count(getc[i].begin(),getc[i].end(),'V');
           get_value[i].count_F = count(getc[i].begin(),getc[i].end(),'F');
           get_value[i].count_H = count(getc[i].begin(),getc[i].end(),'H');
           get_value[i].count_O = count(getc[i].begin(),getc[i].end(),'O');
           get_value[i].count_I = count(getc[i].begin(),getc[i].end(),'I');

           get_value[i].count_0 = get_value[i].count_Z;
           get_value[i].count_2 = get_value[i].count_W;
           get_value[i].count_6 = get_value[i].count_X;
           get_value[i].count_8 = get_value[i].count_G;
           get_value[i].count_7 = get_value[i].count_S - get_value[i].count_6;
           get_value[i].count_5 = get_value[i].count_V - get_value[i].count_7;
           get_value[i].count_4 = get_value[i].count_F - get_value[i].count_5;
           get_value[i].count_3 = get_value[i].count_H - get_value[i].count_8;
           get_value[i].count_1 = get_value[i].count_O - get_value[i].count_0 - get_value[i].count_2 - get_value[i].count_4;
           get_value[i].count_9 = get_value[i].count_I - get_value[i].count_5 - get_value[i].count_6 - get_value[i].count_8;
        }
        //before the number is added by 8 to 0 -9 , here 0-7 equal to 2-9, 8-9 equal to 0 - 1
        for(i = 0; i < numbit;i++)
        {
            //sort again following the rule above
            for(j = 0; j < get_value[i].count_8;j++) // 8 - 0
                printf("0");
            for(j = 0; j < get_value[i].count_9;j++) // 8 - 0
                printf("1");
            for(j = 0; j < get_value[i].count_0;j++) // 8 - 0
                printf("2");
            for(j = 0; j < get_value[i].count_1;j++) // 8 - 0
                printf("3");
            for(j = 0; j < get_value[i].count_2;j++) // 8 - 0
                printf("4");
            for(j = 0; j < get_value[i].count_3;j++) // 8 - 0
                printf("5");
            for(j = 0; j < get_value[i].count_4;j++) // 8 - 0
                printf("6");
            for(j = 0; j < get_value[i].count_5;j++) // 8 - 0
                printf("7");
            for(j = 0; j < get_value[i].count_6;j++) // 8 - 0
                printf("8");
            for(j = 0; j < get_value[i].count_7;j++) // 8 - 0
                printf("9");
            printf("\n");
        }

    }
    return 0;
}
