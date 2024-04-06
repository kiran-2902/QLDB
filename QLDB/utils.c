#include "utils.h"
#include <sys/stat.h>

int db_exist(const char* db_name) {
	struct stat buffer;
	return (stat(db_name, &buffer) == 0);
}