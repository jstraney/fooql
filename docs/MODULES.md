# Modules

right now these are the main parts of fooql

### main
main entry point for application, gets command line arguments to set configuration at run time

### analyzer
takes incoming data packets, reads them character by character and splits text into lexemes, or individual tokens. basically (for example, if no word in the language contains backtick characters, an error would be thrown.) determines if the words are valid

### parser
goes through the order of the lexemes to determine if they are gramatically valid. basically, this determines if the order makes sense or not. While the lexemes are parsed, the code generator (gen) is invoked to create machine codes (unsigned integers) with special meanings. 

### debug
special wrapper of vfprintf which will only print if the -v flag is set to "t" at runtime 

### err
raises exceptions and halts the program when a serious problem occurs (stack overflow, buffer overflow, disk error)

### map
type safe implementation of hash maps borrowed from [this repository](https://github.com/rxi/map).

### gen
called by the parser to generate machine codes (enumerated, unsigned integers) for the virtual machine

### dyad
an asynchronous networking library. used by the server module to allow connections, use event handlers etc. [dyad on github](https://github.com/rxi/dyad)

### server
opens a port to receive incoming TCP packets. reads incoming requests and passes them along in this order: analyzer => parser => code gen => vm => sends back output from vm as response.

### storage
handles storage of records to file (still have no idea). some things that have to be thought out

* how will data be represented?
* how will files be split up?
* what locking mechanism will exist?

### vm
virtual machine will take a list of machine codes and run code conditionally


