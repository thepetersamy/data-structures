#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CharArrayStack.h"
#include "StackApplications.h"


int main(){

    char exp[] = "1+2*(8-9)";
    char res[100];
    infixToPostfix(exp, res);
//    printf("%s", res);


    return 0;
}
