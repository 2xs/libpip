.macro CG_HELPER name, o, nargs
.global \name
\name:
.rep \nargs
	push	(4*(\nargs))(%esp)
.endr
	lcall	\o, $0
	ret
.endm

.macro CG_HELPER_INTMASKED name, o, nargs
.global \name
\name:
/* save flags */
	push	0xfffffffc
	orl	$1, 0xfffffffc
.rep \nargs
	push	(4*(\nargs+1))(%esp)
.endr
	lcall	\o, $0
/* restore flags */
	pop	0xfffffffc
	ret
.endm
	
CG_HELPER_INTMASKED	outb, 			$0x30,	2
CG_HELPER_INTMASKED	inb, 			$0x38,	1
CG_HELPER_INTMASKED	outw, 			$0x40,	2
CG_HELPER_INTMASKED	inw, 			$0x48,	1
CG_HELPER_INTMASKED	outl, 			$0x50,	2
CG_HELPER_INTMASKED	inl, 			$0x58,	1
CG_HELPER_INTMASKED	outaddrl,		$0x88,	2

CG_HELPER 		createPartitionInt ,	$0x60, 	5
CG_HELPER 		pageMapCount ,		$0x68, 	2
CG_HELPER 		prepare,		$0x70, 	4
CG_HELPER 		mapPage,		$0x78, 	6
CG_HELPER 		dispatchInt,		$0x80, 	5

CG_HELPER 		pip_time,		$0x90, 	0
CG_HELPER 		resume,			$0x98, 	2
