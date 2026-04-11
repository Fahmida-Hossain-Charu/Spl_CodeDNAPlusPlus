#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>

#define SAFE_INIT(x) memset(&(x), 0, sizeof(x))

#define MAX_FILES 10
#define MAX_FILE_PATH 256
#define MAX_LINES 2000
#define MAX_LINE_LENGTH 512
#define MAX_TOKENS 5000
#define MAX_TOKEN_LENGTH 64

#define TRUE 1
#define FALSE 0

#endif