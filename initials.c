/*
check50 2015.fall.pset2.initials initials.c
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    
    string name = GetString();
    int m = strlen(name);

    for(int i = 0; i < m; i++){
        name[i] = toupper(name[i]); //convert name to uppercase

    }    

    char initials[m/2]; //creat initials array that is half the size of name
    initials[0] = name[0]; //save first initial
    int z = 1; //initials counter
    for(int i = 0; i < m; i++){
        int ch = name[i]; //check each char in name
        if((ch >= 'A' && ch <= 'Z') || ch == ' '){
            if(ch == ' '){ //if there is a space, copy next letter to initials array
                initials[z] = name[i+1];
            }
        }
        z++;
    }
    
    for(int i = 0; i < z; i++){
        if(initials[i] >= 'A' && initials[i] <= 'Z'){
            printf("%c", initials[i]);
        }
    }
    printf("\n");
}
