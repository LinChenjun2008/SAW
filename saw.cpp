#include<iostream>
using namespace std;

typedef union SAW_typevalue
{
    char byte;
    short word;
    int dword;
    long long qword;
} SAW_typevalue;

typedef struct Token
{
    char* name[64];
    SAW_typevalue value;
    int type;
} Token;

char* get_token(char* str,Token* token);
char* skipspace(char* str);

int main()
{
    char str[64];
    char* p = str;
    for(int i = 0; i < 64; i++)
    {
        cin.get(*p);
        if(*p == '\n')
        {
            break;
        }
        p++;
    }
    Token t;
    t.type = 2;
    p = str;
    while(t.type != 0 && p != NULL)
    {
        p = get_token(p,&t);
    }
    return 0;
}

char* get_token(char* str,Token* token)
{
    str = skipspace(str);
    while(*str >= '1' && *str <= '9')
    {
        std::cout <<  str[0];
        token->type = 1;
        return str +1;
    }
    //std::cout << "unknow:" << str[0] << std::endl;
    token->type = 2;
    if(str[0] == '\0')
    {
        token->type = 0;
        return NULL;
    }
    return str+1;
}

char* skipspace(char* p)
{
    while(*p == ' ' || *p == '\t' || *p == '\n')
    {
        p++;
    }
    return p;
}
