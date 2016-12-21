# Readline example

Example code for a series of blog post introducing tab completion in GNU
Readline.

For more, see the blog posts:

* <https://robots.thoughtbot.com/tab-completion-in-gnu-readline>
* <https://robots.thoughtbot.com/tab-completion-in-gnu-readline-ruby-edition>

## Running the C code

Compile and run the code with:

    make
    ./rdemo

The defaults in the Makefile are set up for an OS X system
with Readline installed via homebrew to `/usr/local/opt`.
You can override these settings with the appropriate values for your system
by setting the `CC`, `CFLAGS` and `LDFLAGS` environment variables
(see the Makefile for example values).

## Running the Ruby code

The Ruby version demonstrates two Ruby patches that need to be applied before
the code will run:

* <https://bugs.ruby-lang.org/issues/12659>
* <https://bugs.ruby-lang.org/issues/13050>

At the time of writing, #12659 is already in trunk and the 2.4 preview builds.
 #13050 hasn't been accepted yet, but may make it before 2.4 final.

Once you have a properly patched version of Ruby, you can run:

    ruby main.rb
