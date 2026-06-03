
; Vector Table Mapped to Address 0 at Reset

                PRESERVE8
                THUMB

                AREA  RESET, DATA, READONLY          ; First 32 WORDS is VECTOR TABLE
                EXPORT   __Vectors
          
__Vectors       DCD    0x000003FC              ; 1K Internal Memory
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
                            
                DCD    KEY_Handler
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
                DCD    0
              
                AREA |.text|, CODE, READONLY
;Reset Handler
Reset_Handler   PROC
                GLOBAL Reset_Handler
                ENTRY

                LDR     R1, =0xE000E400     ;Interrupt Priority Register
                LDR     R0, =0x00000000     ;Priority: IRQ0(KEY_IRQ): 0x00
                STR     R0, [R1]
                LDR     R1, =0xE000E100     ;Interrupt Set Enable Register
                LDR     R0, =0x00000001     ;Enable interrupts for KEY 
                STR     R0, [R1]
                LDR     R0, =0x000000FF     ;Clear SEG
                LDR     R1, =0x53000000     ;SEG address
                STR     R0, [R1]            ;ones digit
                STR     R0, [R1, #4]        ;tens digit
                STR     R0, [R1, #8]        ;hundreds digit
                STR     R0, [R1, #0xC]        ;thousands digit

AGAIN           LDR    R1, =0x50000000      ;LED address 
                LDR    R2, =0x52000000      ;ALS address
                LDR    R3, [R2]
                STR    R3, [R1]

                LDR    R0, =0x2FFFFF        ;Delay
Loop            SUBS   R0, R0, #1
                BNE Loop

                B AGAIN
                ENDP

KEY_Handler     PROC
                EXPORT  KEY_Handler
                PUSH    {R0,R1,R2,R3,LR}

                LDR   R0, =0x51000000       ;KEY address
                LDR   R1, [R0]              ;clear KEY push

                LDR   R0, =0x52000000       ;ALS address
                LDR   R1, =0x53000000       ;SEG address
                LDR   R2, [R0]
                LDR   R3, =0x0000000F
                ANDS  R3, R2, R3 
                STR   R3, [R1]              ;ones digit
                LDR   R3, =0x000000F0
                ANDS  R3, R2, R3 
                LSRS  R3, R3, #4            ;tens digit
                STR   R3, [R1, #4]          ;tens digit
    
                POP     {R0,R1,R2,R3,PC}       ;return
                ENDP

                ALIGN     4                  ; Align to a word boundary
  END
