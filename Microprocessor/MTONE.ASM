; MUSIC TONE INTERFACE
; Connect the interface over J8 of trainer
; The program can be in Standalone or Serial Mode
; Execute the program from 2000H


                        OUTPUT 2500AD
                        ORG 2000H
                        MOV AX,0000H
                        MOV ES,AX
                        MOV DX,0FFE6H           ;Initialise all 8255
                        MOV AL,80H              ;ports as O/P in mode 0
                        OUT DX,AL

                GETKEY: CALL FAR 0FE00:00A9H    ;read key from ASCII KBD
                        MOV BX,0000H
                        MOV SI,2500H            ;pointer to freq table
                        CMP AL,41H              ;check if key value
                        JB GETKEY               ;falls between A & P
                        CMP AL,50H
                        JG GETKEY               ;accept valid key only
                        MOV DX,0FFE4H           ;compute count from 
                        SUB AL,41H              ;ASCII keycode
                        MOV BL,AL
                        MOV CL,4FH
                FREQ:   MOV AL,00H
                        MOV DX,0FFE4H
                        OUT DX,AL
                        MOV CH,[BX][SI]
               NXTPL:   NOP
                        NOP
                        NOP
                        NOP
                        DEC CH
                        JNZ NXTPL
                        MOV AL,0FFH
                        OUT DX,AL
                        MOV CH,[BX][SI]
               NXTPH:   NOP
                        NOP
                        NOP
                        NOP
                        DEC CH
                        JNZ NXTPH
                        DEC CL
                        JNZ FREQ
                        JMP SHORT GETKEY

                        ORG 2500H
                        DB B4H,ABH,96H,85H,7EH,70H,64H,59H
                        DB 54H,4AH,42H,3EH,37H,31H,2CH,29H

                        END



                        
                        

