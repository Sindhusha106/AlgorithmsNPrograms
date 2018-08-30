#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * stringCompress(char *str);
void main()
{
    char *str = "abcdefg";
    printf("%s", stringCompress(str));
}

char * stringCompress(char *str){
    
    char *res =(char*)malloc(sizeof(strlen(str))*2+1);
    int count;
    int index = 0;
    for(int i=0; i<strlen(str); i++)
    {
        res[index++] = str[i];
        count = 1;
        while(str[i]==str[i+1]&&i+1<strlen(str))
        {
            count++;
            i++;
        }
        
        res[index++] = count+'0';
    }
res[index] = '\0';
    if(strlen(res)>strlen(str)) return str;
    
    return res;
}
