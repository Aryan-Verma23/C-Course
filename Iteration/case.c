#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "source.txt"

void countCharacters() {
    FILE *file = fopen(FILE_NAME, "r"); 
    if (file == NULL) {
        printf("Error opening file! Make sure '%s' exists.\n", FILE_NAME);
        return;
    }

    int lowercase = 0, uppercase = 0, digits = 0, specialChars = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) { 
            lowercase++;
        else if (ch >= 'A' && ch <= 'Z') 
            uppercase++;
        else if (ch >= '0' && ch <= '9') 
            digits++;
        else if (ch != ' ' && ch != '\n' && ch != '\t') 
            specialChars++;
    }

    fclose(file);

 
    printf("\nCharacter Count in '%s':\n", FILE_NAME);
    printf("Uppercase Letters : %d\n", uppercase);
    printf("Lowercase Letters : %d\n", lowercase);
    printf("Digits            : %d\n", digits);
    printf("Special Characters: %d\n", specialChars);
}

int main() {
    countCharacters();
    return 0;
}
