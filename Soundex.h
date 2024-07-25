#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include <ctype.h>
#include <string.h>
#include <stdio.h>
 
char getSoundexCode(char c) {
    static const char codeTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0','2', '2', '4', '5', '5', '0', '1', '2', '6',  '2', '3', '0', '1', '0', '2', '0', '2'     
    };
     c = toupper(c);
    if (isalpha(c)) {
        return codeTable[c - 'A'];
    }
    return '0';
}  
 
int updateSoundex(char code, int sIndex, char *soundex) {
    int notZero = code != '0';
    if (notZero) {
        soundex[sIndex] = code;
        return ++sIndex;
    } 
    soundex[sIndex] = soundex[sIndex];
    return sIndex;
}
void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
 
     for (int i = 1; name[i] != '\0' && sIndex <=3; i++) {
        char code = getSoundexCode(name[i]);
        sIndex = updateSoundex(code, sIndex, soundex); 
    }
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}
 
#endif // SOUNDEX_H
