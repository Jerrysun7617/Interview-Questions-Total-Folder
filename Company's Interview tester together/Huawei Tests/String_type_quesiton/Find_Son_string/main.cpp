#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int deletestr( char * str,  char * sub_str,char * result)
{
     char *p  = str;
     char *p1 = str;
     char *q = sub_str;
    int k = 0;

    int sub_strlen = strlen(q);
    int same_num = 0;
    int flag = 0; //when find the same, put it 1
    while(*p != '\0')
    {
       if(*p == *sub_str && *sub_str != '\0')
       {
            int equal_num = 0;
            p1 = p;
            q = sub_str;
            while(*p1 == *q && *p1 != '\0' && *q != '\0'){
                equal_num++;
                p1++;
                q++;
            }
            if(equal_num >= sub_strlen){
                p += sub_strlen;
                same_num++;
            }
            else
               *result++ = *p++;
       }
       else{
        *result++ = *p++;
       }
    }
    return same_num;
}

int main()
{
    char str[1000] = " ";
    char result[1000] = " ";
    char sub_str[20] = " ";

    while(cin>>str>>sub_str)
    {
        cout<<deletestr(str,sub_str,result)<<endl;
        cout<<result<<endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
