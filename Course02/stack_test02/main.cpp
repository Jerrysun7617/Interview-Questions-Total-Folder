#include <iostream>
#include<vector>
#include <stack>

using namespace std;

 struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> data;
        int numi = 0;
       std::stack<ListNode *> s;
        ListNode * pNode = head;
        while(pNode != NULL)
        {
            s.push(pNode);
            pNode = pNode->next;
        }
        while(!s.empty())
        {
            //data.push_back[pNode->val];
            cout<<pNode->val<<" ";
            s.pop();
        }

        return data;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
