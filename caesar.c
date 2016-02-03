/*
check50 2015.fall.pset2.caesar caesar.c
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int k;
int n;

int main(int argc, string argv[]){
    
    if(argv[1]==NULL){
            printf("Usage: /caesar <key>\n");
        }
        
    //get and validate input k
    if(argc == 2){
        k = atoi(argv[1]);
        if(k < 0){
            printf("Key must be a non-negative integer.\n");
            return 1;
        }       
    }else{
       return 1;
    }
    
    //get plaintext
    string pText = GetString();
    n = strlen(pText);
    int asciiText[n];
    
    //convert pText to asciiText  
    for(int i = 0; i < n; i++){     
        asciiText[i] = pText[i];
    }
    
    //encryption
    int cText[n];
    for(int i = 0; i < n; i++){
        if(65 <= asciiText[i] && asciiText[i] <= 90){
            cText[n] = ((((pText[i]) + k) - 65) % 26) + 65;
            printf("%c", cText[n]);
        }else if(97 <= asciiText[i] && asciiText[i] <= 122){
            cText[n] = ((((pText[i]) + k) - 97) % 26) + 97;
            printf("%c", cText[n]);
        }else{
            cText[n] = pText[i];
            printf("%c", cText[n]);
        }
    }
    
    printf("\n");
    return 0;
}
