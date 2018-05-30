# Welcome

This is fooql, (name pending). To get started, make sure all dependencies are installed

## Dependencies
to build, you'll need gcc installed along with make. with both of those installed, you should be able to run the following in the project directory

```sh
make
```

you should see some verbose output which is all the c files getting compiled, linked, and placed in the bin directory (as fooql. you can then run it with)

```sh
./fooql
```

to clean up the object files, just run

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
