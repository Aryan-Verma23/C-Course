#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *sourceFile, *FinalFile;
    char ch;


    if (argc != 3) {
        printf("Usage: %s <source file> <Final file>\n", argv[0]);
        return 1;
    }

    sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file %s\n", argv[1]);
        return 1;
    }

    FinalFile = fopen(argv[2], "w");
    if (FinalFile == NULL) {
        printf("Error: Cannot open destination file %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, FinalFile);
    }

    printf("File copied successfully.\n");

   
    fclose(sourceFile);
    fclose(FinalFile);

    return 0;
}
