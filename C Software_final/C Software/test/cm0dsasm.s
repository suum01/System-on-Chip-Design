Stack_Size      EQU     0x00001000              ; 8KB of STACK

                AREA    STACK, NOINIT, READWRITE, ALIGN=4
Stack_Mem       SPACE   Stack_Size
__initial_sp


Heap_Size       EQU     0x00001000               ; 8KB of HEAP

                AREA    HEAP, NOINIT, READWRITE, ALIGN=4
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB

                AREA  RESET, DATA, READONLY          ; First 32 WORDS is VECTOR TABLE
                EXPORT   __Vectors
          
__Vectors       
                DCD    0x0000FFFC              ; 64K Internal Memory
                DCD    Reset_Handler
                DCD    0        
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                
                ; External Interrupts
                            
                DCD    Key_Handler 
                DCD    Timer_Handler
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
                DCD    0
              
                AREA |.text|, CODE, READONLY
;Reset Handler
Reset_Handler   PROC
                GLOBAL Reset_Handler
                ENTRY
        IMPORT  __main
                LDR     R0, =__main               
                BX      R0                        ;Branch to __main
                ENDP

Key_Handler     PROC
                EXPORT Key_Handler
		    IMPORT  Key_ISR
                PUSH    {R0, R1, R2, R3, LR}
				        BL Key_ISR
                POP     {R0, R1, R2, R3, PC}                    ;return
                ENDP
Timer_Handler   PROC
                EXPORT Timer_Handler
		    IMPORT  Timer_ISR
                PUSH    {R0, R1, R2, R3, LR}
				        BL Timer_ISR
                POP     {R0, R1, R2, R3, PC}                    ;return
                ENDP
					
        ALIGN 4  
; User Initial Stack & Heap
                IF      :DEF:__MICROLIB
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                ELSE
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN
        ENDIF  
   END
