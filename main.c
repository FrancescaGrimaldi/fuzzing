// In C: write a function that takes a string as input and returns a new string that is equal to the 
// input but where &, < and > are replaced by &amp;, &lt; and &gt;

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "utility.h"

# define MAX 500

int main () {
    char input_string[MAX];

    printf("Enter your string: \n");
    fgets(input_string, sizeof(input_string), stdin);

    if (input_string == NULL) {
        printf("Input string is NULL\n");
        return 0;
    }

    char *output_string = replace_char(input_string);

    if (output_string != NULL) {
        printf("Output string: \n%s", output_string);
        free(output_string);
    } else {
        printf("Error\n");
    }

    return 0;
}