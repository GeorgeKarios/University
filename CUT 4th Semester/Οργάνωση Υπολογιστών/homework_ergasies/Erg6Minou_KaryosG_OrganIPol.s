.data
pinakasIndex: .space 40
pinakasMarks: .space 40
arithmosFoithton: .word 0

menu_str: .asciiz "\n1 Add Student \n2 Display All Students\n3 Search by Index Number\n4 Display Average Marks\n5 Exit\nEnter your choice: "
prompt_index: .asciiz "Enter index number: "
prompt_marks: .asciiz "Enter marks: "
prompt_search: .asciiz "Enter index number to search: "

msg_added: .asciiz "Student added successfully\n"
msg_not_found: .asciiz "Student not found.\n"
msg_exit: .asciiz "Exiting program.\n"
msg_index_no: .asciiz "Index No: "
msg_marks: .asciiz ", Marks: "
msg_newline: .asciiz "\n"
msg_avg: .asciiz "Average Marks: "
msg_no_students: .asciiz "No students added yet.\n"

.text
.globl main

main:
menu_loop:
    li $v0, 4
    la $a0, menu_str
    syscall

    li $v0, 5
    syscall
    add $t0, $v0, $zero

    li $t1, 1
    beq $t0, $t1, prosthiki

    li $t1, 2
    beq $t0, $t1, emfanisi

    li $t1, 3
    beq $t0, $t1, anazitisi

    li $t1, 4
    beq $t0, $t1, mesos_oros

    li $t1, 5
    beq $t0, $t1, eksodos

    j menu_loop

prosthiki:
    li $v0, 4
    la $a0, prompt_index
    syscall

    li $v0, 5
    syscall
    add $t2, $v0, $zero

    li $v0, 4
    la $a0, prompt_marks
    syscall

    li $v0, 5
    syscall
    add $t3, $v0, $zero

    lw $t1, arithmosFoithton
    sll $t4, $t1, 2

    la $t5, pinakasIndex
    add $t5, $t5, $t4
    sw $t2, 0($t5)

    la $t5, pinakasMarks
    add $t5, $t5, $t4
    sw $t3, 0($t5)

    addi $t1, $t1, 1
    sw $t1, arithmosFoithton

    li $v0, 4
    la $a0, msg_added
    syscall

    j menu_loop

emfanisi:
    lw $t1, arithmosFoithton
    beq $t1, $zero, emfanisi_keno

    li $t6, 0

loop_emfanisi:
    beq $t6, $t1, menu_loop

    sll $t4, $t6, 2

    la $t5, pinakasIndex
    add $t5, $t5, $t4
    lw $t2, 0($t5)

    la $t5, pinakasMarks
    add $t5, $t5, $t4
    lw $t3, 0($t5)

    li $v0, 4
    la $a0, msg_index_no
    syscall

    li $v0, 1
    add $a0, $t2, $zero
    syscall

    li $v0, 4
    la $a0, msg_marks
    syscall

    li $v0, 1
    add $a0, $t3, $zero
    syscall

    li $v0, 4
    la $a0, msg_newline
    syscall

    addi $t6, $t6, 1
    j loop_emfanisi

emfanisi_keno:
    li $v0, 4
    la $a0, msg_no_students
    syscall
    j menu_loop

anazitisi:
    li $v0, 4
    la $a0, prompt_search
    syscall

    li $v0, 5
    syscall
    add $t2, $v0, $zero

    lw $t1, arithmosFoithton
    li $t6, 0

loop_anazitisi:
    beq $t6, $t1, den_vrethike

    sll $t4, $t6, 2

    la $t5, pinakasIndex
    add $t5, $t5, $t4
    lw $t7, 0($t5)

    beq $t7, $t2, vrethike

    addi $t6, $t6, 1
    j loop_anazitisi

vrethike:
    la $t5, pinakasMarks
    add $t5, $t5, $t4
    lw $t3, 0($t5)

    li $v0, 4
    la $a0, msg_index_no
    syscall

    li $v0, 1
    add $a0, $t2, $zero
    syscall

    li $v0, 4
    la $a0, msg_marks
    syscall

    li $v0, 1
    add $a0, $t3, $zero
    syscall

    li $v0, 4
    la $a0, msg_newline
    syscall
    j menu_loop

den_vrethike:
    li $v0, 4
    la $a0, msg_not_found
    syscall
    j menu_loop

mesos_oros:
    lw $t1, arithmosFoithton
    beq $t1, $zero, keno_avg
    li $t6, 0
    li $t8, 0

loop_avg:
    beq $t6, $t1, telos_avg
    sll $t4, $t6, 2
    la $t5, pinakasMarks
    add $t5, $t5, $t4
    lw $t3, 0($t5)

    add $t8, $t8, $t3

    addi $t6, $t6, 1
    j loop_avg

telos_avg:
    div $t8, $t1
    mflo $t9

    li $v0, 4
    la $a0, msg_avg
    syscall

    li $v0, 1
    add $a0, $t9, $zero
    syscall

    li $v0, 4
    la $a0, msg_newline
    syscall

    j menu_loop

keno_avg:
    li $v0, 4
    la $a0, msg_no_students
    syscall

    j menu_loop

eksodos:
    li $v0, 4
    la $a0, msg_exit
    syscall

    li $v0, 10
    syscall