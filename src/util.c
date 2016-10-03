#include <stdint.h>
#include <pip/debug.h>
#include <pip/vidt.h>
#include <pip/api.h>

/* Resume handler for the root partition
 * This is a special case for the root partition.
 * as multiplexer can mask interrupt it will save itself
 */
void rootResumeHandler(void)
{
	/* i'll just resume myself fornow */
	resume(0,0);
}

void resumeHandler(void)
{
	puts("TODO: resumeHandler\n");
	for(;;);
}
