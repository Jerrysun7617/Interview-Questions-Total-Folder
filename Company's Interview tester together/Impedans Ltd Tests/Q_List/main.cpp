
#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
using namespace std;


struct st_user
{
    int id;
};

int main()
{

    st_user a1,a2,a3;

    a1.id = 1;
    //printf(a1.name,"%s","xxxxxxxxx");
    a2.id = 2;
    //printf(a2.name,"%s","fff");
    a3.id = 3;
    //printf(a3.name,"%s","bbbb");

    list<st_user> list1;

    list1.push_back(&a1);
    list1.push_back(&a2);
    list1.push_back(&a3);


    printf("------------------------------\n");


    for(list<st_user*>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
    {
        printf("%s \n", (iter)->id);
    }


    printf("------------------------------\n");


    for(list<st_user*>::iterator iter = list1.begin(); iter != list1.end();)
    {
        if( (iter)->id == 2 )
        {
            iter = list1.erase(iter);
        }
        else
            ++iter;

    }

    printf("------------------------------\n");


    for(list<st_user*>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
    {
        printf("%s \n", (*iter)->id);
    }


    printf("------------------------------\n");


    system("pause");


    return 0;
}
