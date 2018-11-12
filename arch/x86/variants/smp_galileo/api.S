%macro APICALL  1
[GLOBAL __Arch_APICall_%1]
__Arch_APICall_%1:
    push ebp
    mov ebp, esp
    
    ; Prepare for SYSENTER
    mov ecx, ebp
    mov edx, sysret_ep
    sysenter
%endmacro

sysret_ep:
    leave
    ret
   
APICALL 0
APICALL 1
APICALL 2
APICALL 3
APICALL 4
APICALL 5
APICALL 6
