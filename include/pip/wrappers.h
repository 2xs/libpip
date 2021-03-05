#ifndef __WRAPPERS_H__
#define __WRAPPERS_H__

/**
 * Pip_MapPageWrapper return codes
 */

enum map_page_wrapper_ret_e {
	SUCCESS=0,
	FAIL_ALLOC_PAGE=1,
	FAIL_PREPARE=2,
	FAIL_ADD_VADDR=3
};

#endif
