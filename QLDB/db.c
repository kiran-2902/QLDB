#include "db.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create_db(const char* db_name) {
    if (dbExists(db_name)) {
        printf("Database already exists.\n");
        return;
    }
    mkdir(db_name, 0700); // Using POSIX mkdir, adjust permissions as needed
    printf("Database %s created successfully.\n", db_name);
}

void select_db(const char* db_name) {
    if (!dbExists(db_name)) {
        printf("Database does not exist.\n");
        return;
    }
    // Set context to use dbName; for this example, we'll just print a message
    printf("Using database: %s\n", db_name);
}

void drop_db(const char* db_name) {
    if (!dbExists(db_name)) {
        printf("Database does not exist.\n");
        return;
    }
    // Use rmdir for directories or remove for files; this example doesn't handle non-empty directories
    rmdir(db_name);
    printf("Database %s dropped successfully.\n", db_name);
}

//#define DB_FILE "database.txt"
//
//void db_set(const char* key, const char* value) {
//    FILE* file = fopen(DB_FILE, "a");
//    if (file == NULL) {
//        perror("Failed to open database file");
//        return;
//    }
//    fprintf(file, "%s:%s\n", key, value);
//    fclose(file);
//}
//char* db_get(const char* key) {
//    static char line[1024]; // Static buffer for the line
//    FILE* file = fopen(DB_FILE, "r");
//    if (file == NULL) {
//        perror("Failed to open database file");
//        return NULL;
//    }
//
//    while (fgets(line, sizeof(line), file) != NULL) { // Use fgets instead of getline
//        char* foundKey = strtok(line, ":");
//        if (strcmp(foundKey, key) == 0) {
//            char* foundValue = strtok(NULL, "\n");
//            fclose(file);
//            // Ensure that foundValue is not NULL before calling _strdup
//            if (foundValue) {
//                return _strdup(foundValue);
//            }
//            else {
//                // Handle the case where strtok returns NULL
//                return _strdup("");
//            }
//        }
//    }
//
//    fclose(file);
//    return NULL;
//}
