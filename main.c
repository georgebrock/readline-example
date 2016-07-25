#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

char **character_name_completion(const char *, int, int);
char *character_name_generator(const char *, int);

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
        if (strncmp(name, text, len) == 0) {
            return strdup(name);
        }
    }

    return NULL;
}
