#include <iostream>
using namespace std;
int fun(int m,int n)
{
	if(m<=0 || n<=0)
		return 0;
	else if(1==m)
		return n+1;
	else if(1==n)
		return m+1;
	else return fun(m-1,n)+fun(m,n-1);
}
int main()
{
	int m,n;
	while(cin>>m>>n)
        cout<<fun(m,n)<<endl;
	return 0;
}
