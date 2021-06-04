/*******************************************************************************/
/*  © Université de Lille, The Pip Development Team (2015-2021)                */
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

#ifndef __DEF_STDIO_H__
#define __DEF_STDIO_H__

#include "pip/api.h"

#define putchar(c)	Pip_Debug_Putc(c)

/*!
 * \brief	Print a string to the serial link
 *
 * \param s	The string to print to the serial link
 */
extern void puts(const char *s);

/*!
 * \brief		Print a formatted string to the serial link
 *
 * \param format	The formatted string to print to the serial link
 *
 * \return		The number of printed characters
 */
extern int printf(const char *format, ...);

/*!
 * \brief		Print a formatted string into str
 *
 * \param str		Where to print the formatted string
 * \param format	The formatted string to print
 *
 * \return		The number of printed characters
 */
extern int sprintf(char *out, const char *format, ...);

/*!
 * \brief		Print a formatted string of size size into str
 *
 * \param str		Where to print the formatted string
 * \param size		The number of characters to copy
 * \param format	The formatted string to print
 *
 * \return		The number of printed characters
 */
extern int snprintf(char *buf, unsigned int count, const char *format, ...);

#endif /* __DEF_STDIO_H__ */
