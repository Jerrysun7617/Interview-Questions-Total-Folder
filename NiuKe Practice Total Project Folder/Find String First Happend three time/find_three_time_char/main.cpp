#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char input[1000];
    while(gets(input) != NULL){
       int length = strlen(input);


        int data[1000];
       int i;
       for(i = 0; i <length;i++)
       {
           if((input[i] >= 'a' && input[i] <= 'z')|| (input[i] >= 'A' && input[i] <= 'Z'))
           ++data[input[i]];
            if(data[input[i]] >=3)
            {
                cout<<input[i]<<endl;
                break;
            }
       }
    }

    return 0;
}
