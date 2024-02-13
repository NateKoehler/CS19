
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 8192
#define NUM_OF_CHARS 256

void countCharacters(const char *str, int *charCounts) {
    while (*str != '\0' && *str != '\n') { // Exclude newline character
        charCounts[*str]++; // Increment letter count
        str++;
    }
    charCounts[0]++; // Count null character
}

int main(void) {
    char line[BUFFER_SIZE];
    int charCounts[NUM_OF_CHARS] = {0};

    if (fgets(line, BUFFER_SIZE, stdin) != NULL) {

        countCharacters(line, charCounts);

        int total = 0;
        for (int i = 0; i < NUM_OF_CHARS; i++) {
            total += charCounts[i];
        }

        for (int i = 0; i < NUM_OF_CHARS; i++) {
            if (charCounts[i] > 0) {
                printf("%03d\t", i); // Print ASCII
                if (i >= 32 && i <= 126) {
                    printf("%c\t", i); // Print character
                } else {
                    printf("_\t"); // print underscore
                }
                printf("%d\t", charCounts[i]); // Print count
                printf("%.2f%%\t", (float)charCounts[i] / total * 100); // Print percentage
                // Print histogram
                for (int j = 0; j < charCounts[i] * 50 / total; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }

    return 0;
}
