#include "pip/string.h"

extern int strcmp(const char *s1, const char *s2)
{
	unsigned int i;
	for (i = 0; s1[i] != '\0' && (s1[i] == s2[i]); i++);
	return (s1[i] - s2[i]);
}
