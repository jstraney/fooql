int debug_set_verbose (const char * debug);

// proxys printf, but will only print if verbose is set
void debug_print(char * format_str, ...);
