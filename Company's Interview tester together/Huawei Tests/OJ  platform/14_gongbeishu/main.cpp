
#include <iostream>
using namespace std;
int gdc(int x,int y)
{
	return (!y)?x:gdc(y,x%y);
}
int main()
{
	int a,b;
	while(cin>>a>>b)
        cout<<(a*b)/gdc(a,b)<<endl;
	return 0;
}
