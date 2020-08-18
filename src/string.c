/*******************************************************************************/
/*  © Université Lille 1, The Pip Development Team (2015-2020)                 */
/*                                                                             */
/*  This software is a computer program whose purpose is to run a minimal,     */
/*  hypervisor relying on proven properties such as memory isolation.          */
/*                                                                             */
/*  This software is governed by the CeCILL license under French law and       */
/*  abiding by the rules of distribution of free software.  You can  use,      */
/*  modify and/ or redistribute the software under the terms of the CeCILL     */
/*  license as circulated by CEA, CNRS and INRIA at the following URL          */
/*  "http://www.cecill.info".                                                  */
/*                                                                             */
/*  As a counterpart to the access to the source code and  rights to copy,     */
/*  modify and redistribute granted by the license, users are provided only    */
/*  with a limited warranty  and the software's author,  the holder of the     */
/*  economic rights,  and the successive licensors  have only  limited         */
/*  liability.                                                                 */
/*                                                                             */
/*  In this respect, the user's attention is drawn to the risks associated     */
/*  with loading,  using,  modifying and/or developing or reproducing the      */
/*  software by the user in light of its specific status of free software,     */
/*  that may mean  that it is complicated to manipulate,  and  that  also      */
/*  therefore means  that it is reserved for developers  and  experienced      */
/*  professionals having in-depth computer knowledge. Users are therefore      */
/*  encouraged to load and test the software's suitability as regards their    */
/*  requirements in conditions enabling the security of their systems and/or   */
/*  data to be ensured and,  more generally, to use and operate it in the      */
/*  same conditions as regards security.                                       */
/*                                                                             */
/*  The fact that you are presently reading this means that you have had       */
/*  knowledge of the CeCILL license and that you accept its terms.             */
/*******************************************************************************/

#include "pip/string.h"

extern unsigned long strlen(const char* s)
{
	unsigned long i = 0;

	while (*(s+i) != '\0')
	{
		i++;
	}

	return i;
}

extern int strcmp(const char *s1, const char *s2)
{
	volatile int ret, i = 0;

	while ((*(s1+i) != 0x00) && (*(s2+i) != 0x00))
	{
		i++;
	}

	if ((*(s1+i) == 0x00) && (*(s2+i) == 0x00))
	{
		ret = 0;
	}
	else
	{
		ret = ~0;
	}

	return ret;
}

extern void *memset(void *s, int c, unsigned long n)
{
	volatile unsigned char * volatile t =
			(volatile unsigned char * volatile) s;
	volatile unsigned long x;

	for(x = 0; x < n; x++)
	{
		*(t+x) = (unsigned char) c;
	}

	return s;
}

extern void *memcpy(void *dest, const void *src, unsigned long n)
{
	volatile unsigned char *tdest = (volatile unsigned char *) dest,
			*tsrc = (volatile unsigned char *) src;
	unsigned long x;

	if (dest != src)
	{
		for (x = 0; x < n; x++)
		{
			*(tdest+x) = *(tsrc+x);
		}
	}

	return dest;
}

extern int memcmp(const void *s1, const void *s2, unsigned long n)
{
	const volatile unsigned char *ts1 = s1, *ts2 = s2;
	register unsigned long x;

	for (x = 0; x < n; x++)
	{
		if (*(ts1+x) != *(ts2+x))
		{
			break;
		}
	}

	return n - x;
}
