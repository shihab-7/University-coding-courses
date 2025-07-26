%{
    #include<stdio.h>
%}

%%
int|float|if|while|for|do|return               {printf("'%s' is a keyword\n",yytext);} 
[a-zA-Z_][a-zA-Z0-9_]*                         {printf("'%s' is an identifier\n",yytext);}
[0-9]+(\.[0-9]*)?([eE][+-]?[0-9]+)?            {printf("'%s' is a number\n",yytext);}
.                                              {printf("others\n");}
\n {return 0;}
%%

int yywrap() { return 1; }

int main()
{
    printf("Enter your string:\n");
    yylex();
    return 0;
}