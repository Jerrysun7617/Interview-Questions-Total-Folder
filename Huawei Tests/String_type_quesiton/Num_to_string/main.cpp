//题目： 高精度整数加法
#include <iostream>
#include <stdlib.h>
using namespace std;


void add(const char *num1,const char*num2,char*result){
   const char * n1 = num1;
   const char * n2 = num2;

    long numb1 = atol(n1);
    long numb2 = atol(n2);


    long result_num = numb1 + numb2;

    if(result_num < 0)
    {
        result_num = 0 - result_num;
        result[0] = '-';
        ltoa(result_num,&result[1],10);
    }
    else{
        ltoa(result_num,result,10);
    }
}
int main()
{
    char num1[100];
    char num2[100];
    char result[200];

    while(cin>>num1>>num2)
    {
        add(num1,num2,result);
        cout<<result<<endl;
    }

    cout << "Hello world!" << endl;
    return 0;
}
