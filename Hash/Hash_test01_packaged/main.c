    //============================================================================
    // Name        : hash算法演示程序
    // Author      : @CodingGeek
    // Version     : 1.0
    // Time        : 2016-03-27
    // Description :hash数据结构代码示例
    //============================================================================
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_WORD_LENGTH 32
    typedef unsigned int UINT32;

    //定义维护的数据信息
    typedef struct tagNode
    {
        char word[MAX_WORD_LENGTH]; //单词
        UINT32 uiLength;//单词词频
    }Node_S;

    //定义hash结点信息数据结构
    typedef struct tagHash_Entry
    {
        void *data; //数据域
        struct tagHash_Entry *pstNext; //指针域
    } Hash_Entry_S;

    //定义冲突链表
    typedef struct tagHash_List
    {
        UINT32 uiLength; //链表长度
        Hash_Entry_S *pstEntry; //链表首结点
    } Hash_List_S;

    //定义hash表
    typedef struct tagHash_Table
    {
        UINT32 (*pHashFunc)(void *, UINT32); //hash函数
        UINT32 (*pCmpFunc)(void*, void*, UINT32); //hash比较函数
        UINT32 uiHashSize; //hash bucket大小
        Hash_List_S *pstHashList; //hash表头指针
    } Hash_Table_S;

    //下面定义hash散列的常见操作
    UINT32 Hash_Function(void *pKey, UINT32 uiHashSize)
    {
        if (NULL == pKey || 0 == uiHashSize)
        {
            return -1;
        }
        UINT32 uiIndex = 0;
        char *pChar = (char*) pKey;
        while (*pChar != '\0')
        {
            uiIndex = uiIndex * 31 + *pChar++;
            if (uiIndex > uiHashSize)
            {
                uiIndex %= uiHashSize;
            }
        }

        return uiIndex;
    }

    UINT32 Hash_MatchFunc(void *pKey1, void *pKey2, UINT32 uiKeySize)
    {
        if (memcmp(pKey1, pKey2, uiKeySize) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //创建一个hash桶大小为uiHashSize的hash表，同时外界挂接回调函数来指定hash函数与比较函数

    Hash_Table_S *Hash_Create(UINT32 uiHashSize, UINT32 (*pHashFunc)(void*, UINT32),
            UINT32 (*pCmpFunc)(void*, void*, UINT32))
    {
        Hash_Table_S *pstTable = NULL;
        pstTable = (Hash_Table_S*)malloc(sizeof(Hash_Table_S));
        if (NULL == pstTable)
        {
            return NULL;
        }
        pstTable->pstHashList = (Hash_List_S*) malloc(
                sizeof(Hash_List_S) * uiHashSize);
        if (NULL == pstTable->pstHashList)
        {
            free(pstTable);
            return NULL;
        }
        int uiLoop = 0;
        for ( ; uiLoop < uiHashSize; uiLoop++)
        {
            pstTable->pstHashList[uiLoop].pstEntry = NULL;
            pstTable->pstHashList[uiLoop].uiLength = 0;
        }

        //挂接外部指定的回调接口
        pstTable->pHashFunc = pHashFunc;
        pstTable->pCmpFunc = pCmpFunc;
        pstTable->uiHashSize = uiHashSize;

        return pstTable;
    }

    //释放所有hash数据结点，清空hash数据结构
    UINT32 Hash_Free(Hash_Table_S *pstTable)
    {
        if (NULL == pstTable)
        {
            return -1;
        }
        if (NULL == pstTable->pstHashList)
        {
            free(pstTable);
            return 0;
        }
        int uiIndex ;
        for ( uiIndex = 0; uiIndex < pstTable->uiHashSize; uiIndex++)
        {
            Hash_Entry_S *pstHead = pstTable->pstHashList[uiIndex].pstEntry;
            while (pstHead != NULL)
            {
                Hash_Entry_S *pTemp = pstHead;
                pstHead = pstHead->pstNext;
                if (pTemp->data)
                {
                    free(pTemp->data);
                    pTemp->data = NULL;
                }
                free(pTemp);
            }
        }
        free(pstTable->pstHashList);
        pstTable->pstHashList = NULL;
        free(pstTable);
        pstTable = NULL;

        return 0;
    }

    //Hash查找，通过key来查找某个元素是否存在，存在返回列表元素，找不到返回NULL
    Hash_Entry_S *Hash_Find_ByKey(Hash_Table_S *pstTable, void *pKey, UINT32 uiKeySize)
    {
        if (NULL == pstTable || pKey == NULL || uiKeySize == 0)
        {
            return NULL;
        }
        if (NULL == pstTable->pstHashList || pstTable->uiHashSize == 0)
        {
            return NULL;
        }
        UINT32 uiIndex = pstTable->pHashFunc(pKey, pstTable->uiHashSize);
        Hash_Entry_S *pstEntry = pstTable->pstHashList[uiIndex].pstEntry;

        UINT32 uiLoop = 0;
        while (uiLoop < pstTable->pstHashList[uiIndex].uiLength && pstEntry)
        {
            void *pEntryKey = pstEntry->data;

            if (pstTable->pCmpFunc(pKey, ((Node_S *)pEntryKey)->word, uiKeySize))
            {
                return pstEntry; //找到返回冲突链表中结点地址
            }
            uiLoop++;
            pstEntry = pstEntry->pstNext;
        }
        return NULL; //没有找到

    }

    //增加一个元素到hash表中
    UINT32 Hash_Insert(Hash_Table_S *pstTable, void *pKey, UINT32 uiKeySize)
    {
        if (NULL == pstTable || pKey == NULL || uiKeySize == 0)
        {
            return -1;
        }
        if (NULL == pstTable->pstHashList || pstTable->uiHashSize == 0)
        {
            return -1;
        }

        Hash_Entry_S *pstEntry = Hash_Find_ByKey(pstTable, pKey, uiKeySize);
        if (pstEntry) //如果找到了，更新数据域，比如词频数加1
        {
            ((Node_S*)pstEntry->data)->uiLength++; //词频计数加1
            return 1;
        }

        //没有找到，申请新结点，挂接到该链上
        Hash_Entry_S *pstNew = (Hash_Entry_S*)malloc(sizeof(Hash_Entry_S));
        if (pstNew == NULL)
        {
            return -1;
        }
        Node_S *pNode = (Node_S*)malloc(sizeof(Node_S));
        if (pNode == NULL)
        {
            free(pstNew);
            return -1;
        }
        memset(pNode, 0x0, sizeof(Node_S));
        memcpy(pNode->word, pKey, uiKeySize);
        pNode->uiLength = 1;
        pstNew->data = pNode;

        UINT32 uiIndex = pstTable->pHashFunc(pKey, pstTable->uiHashSize);
        pstNew->pstNext = pstTable->pstHashList[uiIndex].pstEntry;
        pstTable->pstHashList[uiIndex].pstEntry = pstNew;
        pstTable->pstHashList[uiIndex].uiLength++; //长度加1
        return 0;

    }


    //hash表中删除一个元素
    UINT32 Hash_Delete(Hash_Table_S *pstTable, void *pKey, UINT32 uiKeySize)
    {
        if (NULL == pstTable || pKey == NULL || uiKeySize == 0)
        {
            return -1;
        }
        if (NULL == pstTable->pstHashList || pstTable->uiHashSize == 0)
        {
            return -1;
        }
        UINT32 uiIndex = pstTable->pHashFunc(pKey, pstTable->uiHashSize);
        Hash_Entry_S *pHead = pstTable->pstHashList[uiIndex].pstEntry;
        Hash_Entry_S *preHead = NULL;
        while (pHead != NULL)
        {
            void *pEntryKey = pHead->data;
            //比较key根据实际情况来确定
            if (pstTable->pCmpFunc(pKey, ((Node_S*)pEntryKey)->word, uiKeySize))
            {
                Hash_Entry_S *delEntry = pHead;
                pHead = pHead->pstNext;
                if (NULL != preHead)
                {
                    preHead->pstNext = pHead;
                }
                else
                {
                    pstTable->pstHashList[uiIndex].pstEntry = pHead;
                }
                if (delEntry->data)
                {
                    free(delEntry->data);
                    delEntry->data = NULL;
                }
                free(delEntry);
                delEntry = NULL;
                pstTable->pstHashList[uiIndex].uiLength--;
                return 0;
            }
            else
            {
                preHead = pHead;
                pHead = pHead->pstNext;
            }
        }

        return -1;
    }

    //hash遍历所有结点
    void Hash_Traverse(Hash_Table_S *pstTable)
    {
        UINT32 uiIndex = 0;
        Hash_Entry_S *pstEntry = NULL;
        if (NULL == pstTable)
        {
            return;
        }

        if (NULL == pstTable->pstHashList)
        {
            return;
        }

        for (uiIndex = 0; uiIndex < pstTable->uiHashSize; uiIndex++)
        {
            pstEntry = pstTable->pstHashList[uiIndex].pstEntry;
            while (NULL != pstEntry)
            {
                printf("%s:%d->",
                        ((Node_S*)pstEntry->data)->word,
                        ((Node_S*)pstEntry->data)->uiLength);
                pstEntry = pstEntry->pstNext;
            }
            printf("NULL\n");
        }

        printf("=========END============\n");

    }


    int main(void)
    {
        Hash_Table_S *pstTable = Hash_Create(15, Hash_Function, Hash_MatchFunc);
        char *str[] = {"hello", "world", "I", "Like", "Programming", "world", "this", "is",
        "a", "test", "programming", "demo", "you", "should","write","more","and", "more","test",
        "cases","you","want"};
        int uiLoop;
        for ( uiLoop = 0; uiLoop < (sizeof(str)/sizeof(str[0])); uiLoop++)
        {
            Hash_Insert(pstTable, str[uiLoop], strlen(str[uiLoop]));
        }
        Hash_Traverse(pstTable);
        Hash_Delete(pstTable, (void*)"more", strlen("more"));
        Hash_Traverse(pstTable);
        Hash_Free(pstTable);
        pstTable = NULL;

        return 0;
    }
