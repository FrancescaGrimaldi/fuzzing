#include <assert.h>
#include <string.h>

extern size_t new_length(char *input_string);
extern char *replace_char(char *input_string);

int main() {
    char *result;

    // testing new_length
    assert(new_length("Hello") == 5);
    assert(new_length("Hello & hi") == 14);
    assert(new_length("Hello < hi >") == 18);

    // testing replace_char
    result = replace_char("Hello");
    assert(strcmp(result, "Hello") == 0);
    free(result);    // to prevent memory leak

    result = replace_char("Hello & hi");
    assert(strcmp(result, "Hello &amp; hi") == 0);
    free(result);    // to prevent memory leak
    
    result = replace_char("Hello < hi >");
    assert(strcmp(result, "Hello &lt; hi &gt;") == 0);
    free(result);    // to prevent memory leak
}