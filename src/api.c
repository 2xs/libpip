#include <pip/api.h>
#include <stdint.h>

extern uint32_t createPartitionInt(uint32_t root, uint32_t pd, uint32_t sh1, uint32_t sh2, uint32_t sh3);
uint32_t createPartition(uint32_t root, uint32_t pd, uint32_t sh1, uint32_t sh2, uint32_t sh3)
{
    uint32_t ret;

    *(uint32_t*)root = pd;
    *(uint32_t*)pd = sh1;
    *(uint32_t*)sh1 = sh2;
    *(uint32_t*)sh2 = sh3;

    return createPartitionInt(root, pd, sh1, sh2, sh3);
}

extern uint32_t dispatchInt(uint32_t part, uint32_t int_no, uint32_t notify, uint32_t data1, uint32_t data2);
uint32_t notify2(uint32_t part, uint32_t int_no, uint32_t data1, uint32_t data2)
{
	return dispatchInt(part, int_no, 1, data1, data2);
}
uint32_t dispatch(uint32_t part, uint32_t int_no, uint32_t data1, uint32_t data2)
{
	return dispatchInt(part, int_no, 0, data1, data2);
}
uint32_t viret(void)
{
	/* ie. resume parent's notif child context,
	 * or yield multiplexer if not available */
	return resume(0,2);
}
