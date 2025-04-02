#include <stdio.h>

// Function to find the length of a string
int findLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void concatenate(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}


void reverseString(char str[], char rev[]) {
    int length = findLength(str);
    int i;
    for (i = 0; i < length; i++) {
        rev[i] = str[length - i - 1];
    }
    rev[length] = '\0';
}

void copyString(char start[], char end[]) {
    int i = 0;
    while (start[i] != '\0') {
        end[i] = start[i];
        i++;
    }
    end[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200], reversed[100], copied[100];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    printf("Length of first string: %d\n", findLength(str1));
    
    concatenate(str1, str2, result);
    printf("Concatenated string: %s\n", result);
    
    reverseString(str1, reversed);
    printf("Reversed first string: %s\n", reversed);
    
    copyString(str1, copied);
    printf("Copied string: %s\n", copied);
    
    return 0;
}
