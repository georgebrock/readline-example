# Readline example

Example code for a blog post introducing tab completion in GNU Readline.
For more, see the blog post at
<https://robots.thoughtbot.com/tab-completion-in-gnu-readline>

## Running the code

Compile and run the code with:

    make
    ./rdemo

The defaults in the Makefile are set up for an OS X system
with Readline installed via homebrew to `/usr/local/opt`.
You can override these settings with the appropriate values for your system
by setting the `CC`, `CFLAGS` and `LDFLAGS` environment variables
(see the Makefile for example values).
