#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int num = A.size();
    int i,j,k;
    cout<<num<<endl;
}
int solution(int  A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    //first of all to sort the array
    int i,j,k;
    int arr[1000000] ={0};

    for(i = 0 ; i < N;i++)
    {
        if(A[i]>0)
            arr[A[i] - 1]++;
    }
    for(j = 1; j < 1000000;j++)
        if(arr[j - 1] == 0)
            break;
    return j;
}
int main()
{
    int test[6] = {1, 3, 6, 4, 1, 2};
    solution(test,6);

    vector <int>  vc;
    solution(vc);
    //cout << "Hello world!" << endl;

    int i;
    cin>>i;
    return 0;
}
