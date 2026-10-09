.data

arrayIndex: .space 40
arrayMarks: .space 40
studentCount: .word 0

menu_str:       .asciiz "\n1. Add Student\n2. Display All Students\n3. Search by Index Number\n4. Display Average Marks\n5. Exit\nEnter your choice: "
prompt_index:   .asciiz "Enter index number: "
prompt_marks:   .asciiz "Enter marks: "
prompt_search:  .asciiz "Enter index number to search: "

msg_added:      .asciiz "Student added successfully!\n"
msg_not_found:  .asciiz "Student not found.\n"
msg_exit:       .asciiz "Exiting program.\n"
msg_index_no:   .asciiz "Index No: "
msg_marks:      .asciiz ", Marks: "
msg_newline:    .asciiz "\n"
msg_avg:        .asciiz "Average Marks: "
msg_no_students:.asciiz "No students added yet.\n"

.text
.globl main

main:
menu_loop:
        li      $v0, 4
        la      $a0, menu_str
        syscall

        li      $v0, 5
        syscall
        move    $t0, $v0

        beq     $t0, 1, do_add
        beq     $t0, 2, do_display
        beq     $t0, 3, do_search
        beq     $t0, 4, do_average
        beq     $t0, 5, do_exit

        j       menu_loop

do_add:

        lw      $t1, studentCount
        li      $t2, 10
        bge     $t1, $t2, menu_loop

        li      $v0, 4
        la      $a0, prompt_index
        syscall

        li      $v0, 5
        syscall
        move    $t2, $v0

        li      $v0, 4
        la      $a0, prompt_marks
        syscall

        li      $v0, 5
        syscall
        move    $t3, $v0

        lw      $t1, studentCount
        la      $t4, arrayIndex
        sll     $t5, $t1, 2
        add     $t4, $t4, $t5
        sw      $t2, 0($t4)

        la      $t4, arrayMarks
        add     $t4, $t4, $t5
        sw      $t3, 0($t4)

        addi    $t1, $t1, 1
        sw      $t1, studentCount

        li      $v0, 4
        la      $a0, msg_added
        syscall

        j       menu_loop

do_display:
        lw      $t1, studentCount
        beqz    $t1, display_empty

        li      $t6, 0
display_loop:
        beq     $t6, $t1, display_done

        la      $t4, arrayIndex
        sll     $t5, $t6, 2
        add     $t4, $t4, $t5
        lw      $t2, 0($t4)

        la      $t4, arrayMarks
        add     $t4, $t4, $t5
        lw      $t3, 0($t4)

        li      $v0, 4
        la      $a0, msg_index_no
        syscall

        li      $v0, 1
        move    $a0, $t2
        syscall

        li      $v0, 4
        la      $a0, msg_marks
        syscall

        li      $v0, 1
        move    $a0, $t3
        syscall

        li      $v0, 4
        la      $a0, msg_newline
        syscall

        addi    $t6, $t6, 1
        j       display_loop

display_empty:
        li      $v0, 4
        la      $a0, msg_no_students
        syscall

display_done:
        j       menu_loop

do_search:
        li      $v0, 4
        la      $a0, prompt_search
        syscall

        li      $v0, 5
        syscall
        move    $t2, $v0

        lw      $t1, studentCount
        li      $t6, 0

search_loop:
        beq     $t6, $t1, search_not_found

        la      $t4, arrayIndex
        sll     $t5, $t6, 2
        add     $t4, $t4, $t5
        lw      $t7, 0($t4)

        beq     $t7, $t2, search_found

        addi    $t6, $t6, 1
        j       search_loop

search_found:
        la      $t4, arrayMarks
        add     $t4, $t4, $t5
        lw      $t3, 0($t4)

        li      $v0, 4
        la      $a0, msg_index_no
        syscall

        li      $v0, 1
        move    $a0, $t2
        syscall

        li      $v0, 4
        la      $a0, msg_marks
        syscall

        li      $v0, 1
        move    $a0, $t3
        syscall

        li      $v0, 4
        la      $a0, msg_newline
        syscall

        j       menu_loop

search_not_found:
        li      $v0, 4
        la      $a0, msg_not_found
        syscall

        j       menu_loop

do_average:
        lw      $t1, studentCount
        beqz    $t1, avg_empty

        # Sum all marks
        li      $t6, 0
        li      $t8, 0
avg_loop:
        beq     $t6, $t1, avg_compute

        la      $t4, arrayMarks
        sll     $t5, $t6, 2
        add     $t4, $t4, $t5
        lw      $t3, 0($t4)
        add     $t8, $t8, $t3

        addi    $t6, $t6, 1
        j       avg_loop

avg_compute:
        div     $t8, $t1
        mflo    $t9

        li      $v0, 4
        la      $a0, msg_avg
        syscall

        li      $v0, 1
        move    $a0, $t9
        syscall

        li      $v0, 4
        la      $a0, msg_newline
        syscall

        j       menu_loop

avg_empty:
        li      $v0, 4
        la      $a0, msg_no_students
        syscall

        j       menu_loop

do_exit:
        li      $v0, 4
        la      $a0, msg_exit
        syscall

        li      $v0, 10
        syscall