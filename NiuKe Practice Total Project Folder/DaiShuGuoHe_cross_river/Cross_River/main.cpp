#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct{
    int Step_num;
    int Jump_value;
}Recorders;

int main()
{
    int Num = 0;
    int i , j ,k;
    int Sum = 0;
    int Sum_steps = 0;
    bool fail_tag = true;
    Recorders  Recorder[10000];
    while(scanf("%d",&Num) != EOF)
    {
        Sum = 0;
        Sum_steps = 0;
        fail_tag = true;
        if(Num < 1)
            Sum_steps = -1; //failed

        for(i = 0; i < Num;i++)
        {
            Recorder[i].Step_num = i;
            scanf("%d",&Recorder[i].Jump_value);
            Sum += Recorder[i].Jump_value;
        }

        if(Sum < Num)
            Sum_steps = -1; //failed
        else{
            for(i = 0; i < Num;i++){
                if(Recorder[i].Jump_value == 0)
                {
                    Sum_steps = -1; //failed
                    break;
                }
                else if (Recorder[i].Jump_value == 1)
                {
                    //i++;
                }
                else
                {   int distance = 0;
                    int tag = Recorder[i].Jump_value;
                    if(Recorder[i].Jump_value + i < Num)
                        for(j = 1; j <= Recorder[i].Jump_value; j++)
                        {

                            //printf(" i = %d,distance = %d , tag = %d ,step_num = %d, Recorder[i].Jump_value = %d, step_num = %d,Recorder[i].Jump_value = %d\n ", i , distance, tag, Recorder[i].Step_num,Recorder[i].Jump_value,Recorder[i + j].Step_num,Recorder[i + j].Jump_value);
                            // find the biggest one
                            if(i + j < Num)
                                if(distance < Recorder[i + j].Jump_value - (Recorder[i].Jump_value - j) )
                                {
                                    distance = Recorder[i + j].Jump_value - (Recorder[i].Jump_value - j);
                                    tag = j;
                                }
                        }
                    i = i + tag -1;
                }
                Sum_steps++;
            }
        }
        printf("%d\n",Sum_steps);

    }

    //cout << "Hello world!" << endl;
    return 0;
}
