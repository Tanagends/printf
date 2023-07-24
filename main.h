#ifndef MACRO_H
#define MACRO_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 1024
int _printf(const char *format, ...);
void print_buffer(char buffer[],size_t count);
#endif
