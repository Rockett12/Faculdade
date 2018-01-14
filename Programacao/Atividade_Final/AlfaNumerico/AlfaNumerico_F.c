#include<stdio.h>

int main()
{
    int i, j;
    char str[1005], num_str[1005];
    scanf("%s", str);

    for(i=0; str[i]!='\0'; ++i)
    {
        num_str[i]= '0';
        for(j=i-1; j>=0 && i-j<=9; --j)
        {
            if(str[i]==str[j])
            {
                num_str[i]= (char) i-j + '0';
                break;
            }
        }
    }
    num_str[i] = '\0';

    printf("%s\n", num_str);

    return 0;
}
