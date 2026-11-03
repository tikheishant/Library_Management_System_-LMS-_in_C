#ifndef HEADERS_H
#define HEADERS_H

// Standard input/output functions
// Provides printf(), scanf(), fopen(), fclose(), fprintf(), fscanf(), etc.
#include <stdio.h>

// Provides __fpurge() to clear input buffers
// This is a GNU-specific header, not part of standard C
#include <stdio_ext.h>

// Provides dynamic memory allocation and deallocation functions
// malloc(), calloc(), realloc(), free(), exit()
#include <stdlib.h>

// Provides string handling functions
// strcmp(), strcpy(), strlen(), strcat(), etc.
#include <string.h>

// Provides offsetof() macro to calculate the byte offset of a structure member
#include <stddef.h>

// Provides date and time functions
// time(), localtime(), mktime(), etc.
#include <time.h>

// Includes the user-defined structure declarations
// Contains BookRecord, IssueRecord and date structure definitions
#include "structure.h"

#endif