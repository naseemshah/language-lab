/* 
C program to implement a DFA for the regular expression (a/b)*abb
using IF-ELSE.
*/

#include <stdio.h>
#include <stdbool.h>  
#include <string.h>

int state0(char ch){
    if(ch == 'a')
        return 1;
    else if(ch == 'b')
        return 0;
    else 
        return -1;
}

int state1(char ch){
    if(ch == 'a')
        return 1;
    else if(ch == 'b')
        return 2;
    else 
        return -1;
}

int state2(char ch){
    if(ch == 'a')
        return 1;
    else if(ch == 'b')
        return 3;
    else 
        return -1;
}

int state3(char ch){
    if(ch == 'a')
        return 1;
    else if(ch == 'b')
        return 0;
    else 
        return -1;
}

void main() {
    char s[1000];
    bool valid = true;
    int state = 0, final_state = 3;
    printf("input string : ");
    scanf("%s", s);

    for(int i = 0; s[i] != '\0' && valid; ++i){
        switch(state){
            case 0:
                state = state0(s[i]);
                break;
            case 1:
                state = state1(s[i]);
                break;
            case 2:
                state = state2(s[i]);
                break;
            case 3:
                state = state3(s[i]);
                break;
            default:
                valid = false;
                break;
        }
    }

    if(state != final_state)
        valid = false;

    if(valid)
        printf("Valid string!\n");
    else 
        printf("Invalid string!\n");

    return;
}