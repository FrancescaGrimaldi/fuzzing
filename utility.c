# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include "utility.h"

size_t new_length(char *input_string) {
    size_t length = strlen(input_string);
    size_t new_length = length;

    for (size_t i = 0; i < length; i++) {
        if (input_string[i] == '<' || input_string[i] == '>') {
            new_length += 3;
        } else if (input_string[i]== '&') {
            new_length += 4;
        }
    }

    return new_length;
}

char* replace_char(char *input_string) {
    size_t newlen =  new_length(input_string);

    char *output_string = malloc(newlen + 1);

    if (output_string == NULL) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i=0; i < strlen(input_string); i++) {
        if (input_string[i] == '<') {
            strcpy(&output_string[j], "&lt;");
            j += 4;
        } else if (input_string[i] == '>') {
            strcpy(&output_string[j], "&gt;");
            j += 4;
        } else if (input_string[i] == '&') {
            strcpy(&output_string[j], "&amp;");
            j += 5;
        } else {
            output_string[j] = input_string[i];
            j++;
        }
    }
    output_string[newlen] = '\0';

    return output_string;
}