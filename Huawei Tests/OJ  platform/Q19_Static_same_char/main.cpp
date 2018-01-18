#ifdef test

#include <iostream>
#include <cstring>
using namespace std;


int ProcessString(char * strInput,char * strOutput)
{
	int len=(int) strlen(strInput);
	char    *start = strInput;
	char    *end = strInput + len - 1;
	char    ch;

	if (strInput != NULL)
	{
		while (start < end)
		{
			ch = *start;
			*start++ = *end;
			*end-- = ch;
		}
	}
	strcpy(strOutput, strInput);
	return 0;
}

int main()
{
	char str[100],output[100];
	while(cin.getline(str,100)){
	 ProcessString(str,output);
	 cout << output << endl;
	}


}



#else

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct  reverse_string{
    int num;
    char ch;
};
int main()
{


    char str[1000];
    while(gets(str) != NULL)
    {
        int i,j = 0,k;
         int arr[256];
        struct  reverse_string answer[1000];


        for(i = 0; i <strlen(str);i++)
            if((str[i]>= '0' && str[i] <='9')
               ||(str[i]>= 'a' && str[i] <='z')
               ||(str[i]>= 'A' && str[i] <='Z')
               ||str[i] == ' '
               )
            {
                arr[str[i]]++;
            }
        for(i = 0; i < 256;i++)
            if(arr[i] != 0){
               answer[j].ch  = i;
               answer[j].num =  arr[i];
               j++;
            }

        for( i = 0; i < j - 1;i++)  //notice
            for(k = i + 1;k < j;k++)
            {
                if((answer[i].num < answer[k].num )|| ((answer[i].num == answer[k].num) && (answer[i].ch < answer[k].ch)))
                {
                    //change
                    struct reverse_string mid;
                    mid = answer[i];
                    answer[i] = answer[k];
                    answer[k] = mid;
                }
            }
        for( i = 0; i < j;i++)
            cout<<answer[i].ch;
        cout<<endl;
    }

    return 0;
}
#endif
