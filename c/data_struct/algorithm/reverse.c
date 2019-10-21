/*
    reversing the number.    
 */





#include <stdio.h>
 
int reverse_number(int num)
{
    int ret = 0, m;
    while(num)
    {
        m = num % 10;
        ret = 10 * ret + m;
        num /= 10;
    }
    return ret;
}
 
int main(void)
{
    int num = 102;
    int ret = reverse_number(num);
    printf("%d\n",ret);
    return 0;
}