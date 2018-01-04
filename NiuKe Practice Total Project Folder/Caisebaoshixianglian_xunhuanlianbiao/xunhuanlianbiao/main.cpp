#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
/*
typedef struct Node
{
    char data;
    struct Node *pNext;
}NODE, *pNODE;

pNODE CreateSgCcLinkList(void)
{
    int i, length = 0, data = 0;
    pNODE pTail = NULL, p_new = NULL;
    pNODE pHead = (pNODE)malloc(sizeof(NODE));

    if (NULL == pHead)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    pHead->data = 0;
    pHead->pNext = pHead;
    pTail = pHead;

    printf("请输入要创建链表的长度：");
    scanf("%d", &length);

    for (i=1; i<length+1; i++)
    {
        p_new = (pNODE)malloc(sizeof(NODE));

        if (NULL == p_new)
        {
            printf("内存分配失败！\n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的元素值：", i);
        scanf("%d", &data);

        p_new->data = data;
        p_new->pNext = pHead;    //这里一定是pHead，因为最后一个节点总是指着头节点
        pTail->pNext = p_new;
        pTail = p_new;
    }

    return pHead;
}
*/
int main()
{
   string diamond = "hello world";

   char * p = (char *)diamond.data();
   char  q[30] = "yes here";
   //diamond = q;
    cout<<diamond<<endl;

    for(int i = 0; i < diamond.length();i++){
        q[i] = diamond[i];
    }
    cout<<q<<endl;

    //char Diamond[1000] = "";
    string diamonds =" ";
    int numi,numj,numk;
    while(cin >> diamonds){
        int mark_a,mark_b,mark_c,mark_d,mark_e;
        int mark_num = 0;
        int biggest_num = 0;
        diamonds += diamonds;

        //cout<<diamonds<<endl;

        for(numi = 0;numi < diamonds.length() - 4;numi++){
            mark_num = 0;
            mark_a = 0x0000;
            for(numj = numi; numj < diamonds.length();numj++){
                mark_num++;
                switch(diamonds[numj]){
                    case 'A':
                        mark_a |= 1;
                        break;
                    case 'B':
                        mark_a |= 0x02;
                        break;
                    case 'C':
                        mark_a |= 0x04;
                        break;
                    case 'D':
                        mark_a |= 0x08;
                        break;
                    case 'E':
                        mark_a |= 0x10;
                        break;
                    default:
                        break;
                }
                if(mark_a == 0x1f)
                {
                    if(biggest_num < diamonds.length()/2 - mark_num)
                        biggest_num = diamonds.length()/2 - mark_num;
                    break;
                }
            }
        }
        printf("%d\n",biggest_num);
    }
    return 0;
}
