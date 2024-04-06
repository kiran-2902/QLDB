#include "db.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set some key-value pairs
    db_set("key1", "value1");
    db_set("key2", "value2");

    // Try to retrieve and print a value
    char* value = db_get("key1");
    if (value != NULL) {
        printf("The value of 'key1' is: %s\n", value);
        free(value);
    }
    else {
        printf("Key not found\n");
    }

    return 0;
}
