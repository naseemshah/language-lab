/*  
C program to implement a DFA for the regular expression 1*2*3* using
transition table.
*/
#include <stdio.h>
#include <stdbool.h>  
#include <string.h>

const int transition_table[][3] = {
    {1, 2, 3},  // state 0, initial & final state
    {1, 2, 3},  // state 1, final state
    {4, 2, 3},  // state 2, final state
    {4, 4, 3},  // state 3, final state
    {4, 4, 4}   // dead state
};

const int final_state[] = {0, 1, 2, 3};
const int num_final_states = sizeof(final_state)/sizeof(final_state[0]);

void main() {
    char s[1000];
    bool valid = false;
    int state = 1;
    printf("input string : ");
    scanf("%s", s);

    for(int i=0; s[i] != '\0' ; i++){
        if(s[i] != '1' && s[i] != '2' && s[i] != '3')
            state = 4;
            
        if(state == 4)
            break;

        state = transition_table[state][s[i] - '1'];
    }

    for(int i=0; i<num_final_states; i++)
        if(state == final_state[i]){
            valid = true;
            break;
        }

    if(valid)
        printf("Valid string!\n");
    else 
        printf("Invalid string!\n");

    return;
}