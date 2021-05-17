/* Author: Vlad Dogariu */

#include <string.h>
#include "cipher.h"

int isLowercase (char letter){
    return (letter>='a' && letter<='z');
}

int isUppercase (char letter){
    return (letter>='A' && letter<='Z');
}

char shiftUp (char letter, int key, char max, char min){
    char newLetter = letter+key;
        if (newLetter>max){
            char tmp = newLetter-max;
            return min+tmp;
        } else return newLetter;
}

char shiftDown (char letter, int key, char max, char min){
    char newLetter = letter-key;
        if (newLetter<min){
            char tmp = min-letter;
            return max-tmp;
        } else return newLetter;
}

char encodeChar (char letter, int key){
    if (isUppercase(letter)){
        return shiftUp(letter,key,'Z','A');
    } else if (isLowercase(letter)){
        return shiftUp(letter,key,'z','a');
    } else return letter;
}


char decodeChar (char letter, int key){
if (isUppercase(letter)){
        return shiftDown(letter,key,'Z','A');
    } else if (isLowercase(letter)){
        return shiftDown(letter,key,'z','a');
    } else return letter;
}

int encode (char *string, int key){
    size_t len= strlen(string);
    for (int i=0; i<len-1; i++){
        string [i] = encodeChar(string[i],key);
    }
}

int decode (char *string, int key){
    size_t len= strlen(string);
    for (int i=0; i<len-1; i++){
        string [i] = decodeChar(string[i],key);
    }
}