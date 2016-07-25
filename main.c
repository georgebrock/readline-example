#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int
main(int argc, char *argv[])
{
    char *buffer = readline("> ");
    if (buffer) {
        printf("You entered: %s\n", buffer);
        free(buffer);
    }

    return 0;
}
