#include <stdio.h>
#include <stdlib.h>

// Function to write a sentence to the file
void writeSentenceToFile() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }
    
    char sentence[101];
    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);
    
    fputs(sentence, file);
    fclose(file);
    printf("Sentence written to file successfully.\n");
}

// Function to read content from the file and display it
void readContentFromFile() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }
    
    char ch;
    printf("Content of data.txt:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

// Function to append a sentence to the file
void appendSentenceToFile() {
    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(1);
    }
    
    char sentence[101];
    printf("Enter another sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);
    
    fputs(sentence, file);
    fclose(file);
    printf("Sentence appended to file successfully.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Write a sentence to file\n");
        printf("2. Read content from file\n");
        printf("3. Append a sentence to file\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf
        
        switch (choice) {
            case 1:
                writeSentenceToFile();
                break;
            case 2:
                readContentFromFile();
                break;
            case 3:
                appendSentenceToFile();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}