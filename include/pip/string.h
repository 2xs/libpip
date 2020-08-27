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

#ifndef __DEF_STRING_H__
#define __DEF_STRING_H__

/*!
 * \brief	Calculate the length of the string s, excluding the terminating
 * 		null byte
 *
 * \param s	The string from which to get the length
 *
 * \return	The number of bytes in the string s
 */
extern unsigned long strlen(const char* s);

/*!
 * \brief	Compare the two null-terminated string s1 and s2
 *
 * \param s1	The first string to compare
 * \param s2	The second string to compare
 *
 * \return	A negative integer if s1 < s2, 0 if s1 == s2 or a positive
 * 		integer if s1 > s2
 */
extern int strcmp(const char *s1, const char *s2);

/*!
 * \brief	Fill the first n bytes of the memory area pointed to by s
 *		with the constant byte c
 *
 * \param s	The buffer to fill
 * \param c	The value used to fill
 * \param n	The number of bytes to fill
 *
 * \return	A pointer to the memory area s
 */
extern void *memset(void *s, int c, unsigned long n);

/*!
 * \brief	Copy n bytes from memory area src to memory area dest
 *
 * \param dest	The destination area
 * \param src	The source area
 * \param n	The number of bytes to copy
 *
 * \return	A pointer to dest
 */
extern void *memcpy(void *dest, const void *src, unsigned long n);

/*!
 * \brief	Compare the first n bytes of the memory areas s1 and s2
 *
 * \param s1	The first area to compare
 * \param s2	The second area to compare
 * \param n	The number of bytes to compare
 *
 * \return	A negative integer if s1 < s2, 0 if s1 == s2 or a positive
 * 		integer if s1 > s2
 */
extern int memcmp(const void *s1, const void *s2, unsigned long n);

#endif /* __DEF_STRING_H__ */
