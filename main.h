#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

/* _printf function prototype */
int _printf(const char *format, ...);

/* custom memory deallocation */
void _free(void **ptr);
#define safefree(p) safefree((void **)&(p))

#endif /* MAIN_H */
