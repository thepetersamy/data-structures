#ifndef REPO_STACKAPPLICATIONS_H
#define REPO_STACKAPPLICATIONS_H


bool isNumber(char c){
    return c >= '0' && c <= '9';
}

// remember to add ^ operator
int priority(char op) {

    if (op == '*' || op == '/') {
        return 3;
    }
    else if (op == '+' || op == '-') {
        return 2;
    }
    else if (op == '^') {
        return 4;
    }
    return 10;
}



// ****NOT WORKING*****
void infixToPostfix(char infix[], char result[]) {

    Stack s;
    char postfix[100];

    init(&s, strlen(infix));


    int counter = 0;
    for (int i = 0; i < strlen(infix); i++) {

        if (isNumber(infix[i])) {
            postfix[counter++] = infix[i];
            //            printf("%d", infix[i]);
        }
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            char top;
            peek(s, &top);
            while (top != '(') {
                pop(&s, &top);
                //                printf("%c",top);
                postfix[counter++] = top;
                peek(s, &top);
            }
            pop(&s, &top); //dispose the )
        }

        else {
            char op;
            if (peek(s, &op) >= 0)
            {
                while (priority(op) >= priority(infix[i])) {

                    char popped;
                    pop(&s, &popped);
                    postfix[counter++] = popped;
                    //                printf("%c", popped);
                    peek(s, &op);
                }
            }
            push(&s, infix[i]); //dont forget to push the actual operator

        }
        postfix[counter + 1] = '\0';
    }
    char item;

    while (s.sp != -1) {
        pop(&s, &item);
        postfix[counter++] = item;
        postfix[counter + 1] = '\0';

    }

    strcpy(result, postfix);

        printf("%s", postfix);
}

bool isMatching(char c1, char c2){
    return  (c1 == '(' && c2 == ')') ||
            (c1 == '{' && c2 == '}') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '<' && c2 == '>');
}


bool isOpeningBracket(char c){
    return c == '(' || c == '[' || c == '{' || c == '<';
}

bool isClosingBracket(char c){
    return c == ')' || c == ']' || c == '}' || c == '>';
}

bool isBalanced(const char* exp){

    Stack s;

    init(&s, strlen(exp));

    for(int i=0; i<strlen(exp); i++){

        if(isOpeningBracket(exp[i])){
            push(&s, exp[i]);
        }

        else if(isClosingBracket(exp[i])){

            // if nothing to pop then not balanced
            if(isStackEmpty(s))
                return false;

            char popped;
            pop(&s, &popped);
            if(!isMatching(popped, exp[i]))
                return false;
        }
    }

    return s.sp == -1;

}


void reverseStingByStack(char* str){

    Stack s;
    init(&s, strlen(str));

    for(int i=0; i<strlen(str); i++){
        push(&s, str[i]);
    }

    int counter = 0;
    while(!isStackEmpty(s)){
        pop(&s, &str[counter++]);
    }
}

#endif //REPO_STACKAPPLICATIONS_H
