#include <iostream>
#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

//first think is using stack,
//typedef
float ask_pingfanggen(float * previous_data)
{
    return sqrt(*previous_data);
}
int main()
{
    stack <float> ShuLie_stack;
    float Datum = 0.0,Sum = 0.0;
    int   Num = 0, i = 0;
    while(scanf("%f %d",&Datum,&Num) != EOF){
        Sum = 0.0;
        for(i = 0; i< Num;i++){
            Sum += Datum;
            Datum = ask_pingfanggen(&Datum);
        }
        printf("%0.2f\n",Sum);
    }

    return 0;
}
