#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 32

int main() {
    FILE *checkSumsLog;
    FILE *knownHashes;
    char checkSumLine[MAX_LINE_LENGTH];
    char hashLine[MAX_LINE_LENGTH];
    int found = 0;
    int lines = 0;

    // Open the first file for reading
    checkSumsLog = fopen("./checkSumsLog.txt", "r");
    if (checkSumsLog == NULL) {
        perror("Error opening checkSumsLog.txt");
        return 1;
    }

    // Open the second file for reading
    knownHashes = fopen("./knownHashes.txt", "r");
    if (knownHashes == NULL) {
        perror("Error opening knownHashes.txt");
        return 1;
    }

    // Read each line from checkSumsLog.txt
    while (fgets(checkSumLine, MAX_LINE_LENGTH, checkSumsLog) != NULL) {
        // Reset the file pointer for knownHashes.txt to the beginning
        rewind(knownHashes);
        
        // Read each line from knownHashes.txt and compare with the current line from checkSumsLog.txt
        while (fgets(hashLine, MAX_LINE_LENGTH, knownHashes) != NULL) {
            // Compare the two lines
            if (strcmp(checkSumLine, hashLine) == 0) {
                printf("Match found: %s", checkSumLine);
		found++;
                break; // Break the inner loop if a match is found
            }
        }
    }

    // Close the files
    fclose(checkSumsLog);
    fclose(knownHashes);

    printf("\n\n\033[1mFINAL RESULTS:\033[0m\nFound \033[31m%d\033[0m error(s)\n\nThank you for using CHKSMS <3", found);

    return 0;
}

