#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

char **character_name_completion(const char *, int, int);
char *character_name_generator(const char *, int);
char *escape(const char *);

char *character_names[] = {
    "Arthur Dent",
    "Ford Prefect",
    "Tricia McMillan",
    "Zaphod Beeblebrox",
    NULL
};

int
main(int argc, char *argv[])
{
    rl_attempted_completion_function = character_name_completion;
    rl_completer_quote_characters = "'\"";

    printf("Who's your favourite Hitchiker's Guide character?\n");
    char *buffer = readline("> ");
    if (buffer) {
        printf("You entered: %s\n", buffer);
        free(buffer);
    }

    return 0;
}

char **
character_name_completion(const char *text, int start, int end)
{
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, character_name_generator);
}

char *
character_name_generator(const char *text, int state)
{
    static int list_index, len;
    char *name;

    if (!state) {
        list_index = 0;
        len = strlen(text);
    }

    while ((name = character_names[list_index++])) {
        if (rl_completion_quote_character) {
            name = strdup(name);
        } else {
            name = escape(name);
        }

        if (strncmp(name, text, len) == 0) {
            return name;
        } else {
            free(name);
        }
    }

    return NULL;
}

char *
escape(const char *original)
{
    size_t original_len;
    int i, j;
    char *escaped, *resized_escaped;

    original_len = strlen(original);

    if (original_len > SIZE_MAX / 2) {
        errx(1, "string too long to escape");
    }

    if ((escaped = malloc(2 * original_len + 1)) == NULL) {
        err(1, NULL);
    }

    for (i = 0, j = 0; i < original_len; ++i, ++j) {
      if (original[i] == ' ') {
          escaped[j++] = '\\';
      }
      escaped[j] = original[i];
    }
    escaped[j] = '\0';

    if ((resized_escaped = realloc(escaped, j)) == NULL) {
        free(escaped);
        resized_escaped = NULL;
        err(1, NULL);
    }

    return resized_escaped;
}
