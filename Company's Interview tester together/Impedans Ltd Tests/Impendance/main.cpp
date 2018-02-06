#include <stdio.h>
#include <string.h>
char input_string[] = "Example String!!";
void prnt_lc(char *psz_str);
int main()
{
    prnt_lc(input_string);
    char test = getchar();
    return 0;
}
void prnt_lc(char *psz_str)
{
    int sz = strlen(psz_str);
    printf("sz = %d\r\n",sz);
    for (sz=0; psz_str[sz]!=0; sz++);
    char *p_str = new char[sz];
    for (int i=0; i<sz; i++)
    {
        p_str[i]=psz_str[i];
        if ( p_str[i]>='a' && p_str[i] <='z') p_str[i]-= 'a'-'A';
    }
    printf(p_str);
}
