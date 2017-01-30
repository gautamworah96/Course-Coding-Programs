; TRAFFIC LIGHT CONTROLLER INTERFACE
; The interface is connected over J8 of of trainer 
; Traffic system moves from one state to other after a fixed delay
; This program starts at 2000H location

        OUTPUT  2500AD

        ORG     2000H
START:  MOV     AL,80H                 ; Initialisation of 8255 Mode 0
        MOV     DX,0FFE6H
        OUT     DX,AL                  ; All ports as o/p ports
AGAIN:  MOV     SI,2038H               ; Table of port values
NEXTST: MOV     AL,[SI]
        MOV     DX,0FFE0H
        OUT     DX,AL                  ; PortA value
        INC     SI
        ADD     DX,2
        MOV     AL,[SI]
        OUT     DX,AL                  ; PortB value
        INC     SI
        ADD     DX,2
        MOV     AL,[SI]
        OUT     DX,AL                  ; PortC value
        INC     SI
        CALL    DELAY                  ; Calling Delay routine
        CMP     SI,2056H               ; Checking for the end of the data values
        JNZ     NEXTST
        JMP     AGAIN
DELAY:  MOV     CX,0FFH                ; Delay routine 
DLY5:   PUSH    CX
        MOV     CX,03FFH
DLY10:  NOP
        LOOP    DLY10
        POP     CX
        LOOP    DLY5
        RET

        ORG     2038H
        PORTVALUES:   DB      10H,81H,7AH                ; State 1
                      DB      44H,44H,0F0H               ; All ambers ON
                      DB      08H,11H,0E5H               ; State 2
                      DB      44H,44H,0F0H               ; All ambers ON     
                      DB      81H,10H,0DAH               ; State 3
                      DB      44H,44H,0F0H               ; All ambers ON
                      DB      11H,08H,0B5H               ; State 4
                      DB      44H,44H,0F0H               ; All ambers ON
                      DB      88H,88H,00H                ; State 5
                      DB      44H,44H,0F0H               ; All ambers ON
                      DB      00H                        ; Dummy

