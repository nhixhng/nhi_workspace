#include <stdio.h>
#include <stdlib.h>

// Funktion zum Befüllen des Arrays mit Strings
void fillStringArray(char*** array, int size) {
    *array = (char**)malloc(size * sizeof(char*));

    if (*array == NULL) {
        perror("Fehler bei der Speicherreservierung");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; ++i) {
        (*array)[i] = (char*)malloc(20 * sizeof(char)); // Annahme: Maximal 19 Zeichen pro String
        if ((*array)[i] == NULL) {
            perror("Fehler bei der Speicherreservierung");
            exit(EXIT_FAILURE);
        }

        printf("Gib einen String ein: ");
        scanf("%19s", (*array)[i]);
    }
}

// Funktion zum Ausgeben des Arrays mit Strings
void printStringArray(char** array, int size) {
    printf("Die Strings im Array sind:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d: %s\n", i + 1, array[i]);
    }
}

// Funktion zum Freigeben des allokierten Speichers
void freeStringArray(char** array, int size) {
    for (int i = 0; i < size; ++i) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int size;

    printf("Gib die Anzahl der Strings im Array ein: ");
    scanf("%d", &size);

    // Deklaration und Initialisierung des Arrays
    char** stringArray;

    // Befüllen des Arrays mit Strings
    fillStringArray(&stringArray, size);

    // Ausgeben des Arrays mit Strings
    printStringArray(stringArray, size);

    // Freigeben des allokierten Speichers
    freeStringArray(stringArray, size);

    return 0;
}

