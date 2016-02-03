/*
check50 2015.fall.pset2.vigenere vigenere.c
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string keyword;
int n;
int m;

int main(int argc, string argv[]){
    
    if(argv[1]==NULL){
        printf("Usage: /vigenere <key>\n");
        return 1;
    }
        
    //get and validate input keyword
    if(argc > 2){
        printf("Usage: /vigenere <key>\n");
        return 1;
    }
    if(argc == 2){
        keyword = argv[1];
        m = strlen(keyword);
        
        //test if keyword[i] is alpha
        for(int i = 0; i < m; i++){
            if(isalpha(keyword[i])){
                keyword[i] = toupper(keyword[i]);
            } else{
                printf("Keyword must only contain letters A-Z and a-z.\n");
                return 1;
            }
        }
    }
    
    //get plaintext
    string pText = GetString();
    n = strlen(pText);
    
    int asciiText[n];
    int cText[n];
    int keyCode[n];
    
    //make keyCode as long as pText and repeat keyword
    for(int i = 0; i < n; i++){
        keyCode[i] = keyword[i % m];
    }
    
    //convert pText to asciiText  
    for(int i = 0; i < n; i++){     
        asciiText[i] = pText[i];
    }
    
    //encryption
    int kcounter=0;
    for(int i = 0; i < n; i++){
        if(65 <= asciiText[i] && asciiText[i] <= 90){
            cText[n] = (((pText[i]-65) + (keyCode[kcounter]-65)) % 26) + 65;
            printf("%c", cText[n]);
            kcounter++;
        }else if(97 <= asciiText[i] && asciiText[i] <= 122){
            cText[n] = (((pText[i]-97) + (keyCode[kcounter]-65)) % 26) + 97;
            printf("%c", cText[n]);
            kcounter++;
        }else{
            cText[n] = pText[i];
            printf("%c", cText[n]);
        }
    }
    
    printf("\n");
    return 0;
}
