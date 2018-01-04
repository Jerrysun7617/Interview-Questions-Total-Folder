//在STL中unique函数是一个去重函数， unique的功能是去除相邻的重复元素(只保留一个),其实它并不真正把重复的元素删除，
//是把重复的元素移到后面去了，然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址，
//因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
     int a[9]= {0,1,2,3,4,8,9,3,5};
     vector<int> vec(a,a+9);

     sort(vec.begin(), vec.end());   //一定要排序！！！！！！
     vector<int>::iterator iter = unique(vec.begin(),vec.end());
     vec.erase(iter,vec.end());
     for( iter = vec.begin() ; iter != vec.end() ; iter ++ )
         cout<<*iter<<" ";

         while(1);
    return 0;
}
