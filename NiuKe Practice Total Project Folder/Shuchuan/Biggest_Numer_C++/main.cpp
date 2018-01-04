#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>   //getline 包含在 sstream 中，要include！
#include <malloc.h>
using namespace std;


typedef struct {
    int num_bit;
    int num_data[3];
    int data_value;
}data_struct;


void divide_array(data_struct * str , int * data,int numi)
{
    int i,j,k;
    for( i = 0; i < numi;i++)
    {
        j = 0;
        str[i].data_value = data[i];
        while(data[i]/10)
        {
            str[i].num_data[j++] = data[i]%10;
            data[i] /= 10;
            str[i].num_bit = j;
        }
        if(data[i]%10)
        {
            str[i].num_data[j++] = data[i]%10;
            data[i] /= 10;
            str[i].num_bit = j;
        }
    }
}
void  calculate_biggest(data_struct * str,int numi)
{
    int i ,y, j = 1,k = 1;
    data_struct middle_value;
    for(i = 0 ;i < numi-1;i++){
        for(y = i; y <numi;y++){
            j = 1,k = 1;
            if(str[i].num_data[str[i].num_bit -j] <  str[y].num_data[str[y].num_bit -k])
            {
                middle_value = str[i];
                str[i] = str[y];
                str[y] = middle_value;
            }
            else if(str[i].num_data[str[i].num_bit -j] ==  str[y].num_data[str[y].num_bit -k])
            {
                while(j <  str[i].num_bit || k < str[y].num_bit)
                {
                    if(j <  str[i].num_bit)
                        j++;
                    if(k <  str[y].num_bit)
                        k++;
                     if(str[i].num_data[str[i].num_bit -j] <  str[y].num_data[str[y].num_bit -k])
                    {
                        middle_value = str[i];
                        str[i] = str[y];
                        str[y] = middle_value;
                        break;
                    }
                    else if (str[i].num_data[str[i].num_bit -j] >  str[y].num_data[str[y].num_bit -k])
                   {
                       break;
                   }
                }
            }
        }
    }
}
int main()
{
    data_struct data_gether[100];
    int num = 1 , i,j;
    int data[100];
    long biggest_data = 0;

    while(cin>>num){

        if(num <= 0 || num > 100)
            break;
        for(i = 0;i < num;i++)
            cin>>data[i];

        divide_array((data_struct *)data_gether,(int *)data,num);

        calculate_biggest((data_struct *)data_gether,num);

        biggest_data = 0;
        for(i = 0;i < num;i++)
            cout <<data_gether[i].data_value;

            /*
            for(j = data_gether[i].num_bit - 1; j >= 0;j--)
            {
                biggest_data += data_gether[i].num_data[j];
                if(i ！= num && j ！= 0)
                  biggest_data *= 10;
            }
            */
        //biggest_data /= 10;
        //cout << biggest_data<<endl;
        //printf("%d",biggest_data);

    }
    return 0;
}

