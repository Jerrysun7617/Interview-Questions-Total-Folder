#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void divide_str(char * str)
{
    int i,j,k;
    char * pt = str;
    int length = strlen(str);

    if(length < 8)
    {
        cout<<str;
        for(i = 0; i < 8 - length;i++)
            cout<<'0';
        cout<<endl;
    }
    else
    {
        j = length;
        k = 0;
        while(j >= 8){
            for( i = 0 + k*8; i < 8 + k*8;i++)
                cout<<pt[i];
            cout<<endl;
            k++;
            j -= 8;
        }


        for(i = k*8; i < length;i++)
            cout<<pt[i];
        for(i = 0; i < 8 - j;i++)
            cout<<'0';
        cout<<endl;
    }

}
void search_q13(char * str,char c)
{
        int num = 0;
        for(int i = 0; i <strlen(str);i++)
            if(c == str[i] || c == str[i] + 32 || c == str[i] - 32)
                 num++;
        cout<<num<<endl;
}
int main()
{

    char str[1000];
    char c;

    while(scanf("%s %c",str,&c) != EOF)
    {
        //cin>>c;

        search_q13(str,c);
        //divide_str(str);
    }


    cout << "Hello world!" << endl;
    return 0;
}
