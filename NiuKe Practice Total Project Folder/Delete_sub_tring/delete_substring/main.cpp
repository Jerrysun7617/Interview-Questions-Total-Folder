#include <iostream>
#include <string>
using namespace std;


//delete
int main()
{
    string mather, sub;
    int num = 100;
    while(num--){
        getline(cin,mather);
        getline(cin,sub);   //clear getline

        int lns = sub.length();
        int m = 0, flag = 0,num = 0;
        while(flag == 0){
             m = mather.find(sub);
            if(m < 0)
                    break;
            else{
                mather.erase(m,lns);
                num++;
            }
        }
        cout<<num<<endl;
        cout<<mather<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
