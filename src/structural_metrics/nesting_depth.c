#include "nesting_depth.h"

int compute_nesting_depth(const char* content) {
    int max_depth = 0, current = 0;
    for (int i = 0; content[i]; i++) {
        if (content[i] == '{') current++;
        if (current > max_depth) max_depth = current;
        if (content[i] == '}') current--;
    }
    return max_depth;
}
