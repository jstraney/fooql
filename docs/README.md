# Welcome

This is fooql, (name pending). To get started, make sure all dependencies are installed

## Dependencies
to build, you'll need gcc installed along with make. with both of those installed, you should be able to run the following in the project directory

```sh
make
```

you should see some verbose output which is all the c files getting compiled, linked, and placed in the bin directory as fooql. you can then cd into the bin directory and run it with

```sh
# run from the bin directory
./fooql

# alternatively from project root
./bin/fooql

# you shouldn't see any output, but that's because you have to enable 'verbose debugging'. "t" is for "true"
./bin/fooql -v t

# if you send a request to localhost:5446 in your browser, you should see some output (in the terminal)

# alternatively on a mac (in a separate terminal window), try running this (require nc, or netcat)
echo -n "lol | netcat localhost 5446

# could also be nc
echo -n "lol | nc localhost 5446

```

to clean up the object files, just run this in the project root. removes all the object files (ending in .o)

```sh
make clean
```

## Project Structure
all of the source code is located under the src directory. Each part of the program is put into separate modules. This project is pretty simple for now.

for more information on modules, read more on available [modules](docs/MODULES.md)

## Language
I have started mapping out the formal grammar tree of FOOQL. It's starting to look (more or less) like standard SQL
the grammar is documented [here](docs/GRAMMAR.txt)

## Practices
I wanted to document some project specifications (in case other maintainers or contributors come along), to find more info on style guide and best practices, read [this](docs/PRACTICES.md)

