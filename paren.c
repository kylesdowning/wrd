#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;
    char line[10];
    while (fgets(line, sizeof(line), file)) {
        // Remove the trailing newline character, if present
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            printf("'%s' %d\n", token, count++);
            token = strtok(NULL, " ");
        }
    }
}
