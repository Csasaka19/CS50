# Section

## The file list.c

* Creates a singly linked list where nodes are added(prepended) and unloaded to free memory.

        sasaka-jr@Sasaka-JR:~/CS50/Week_5/section$ valgrind ./list
        ==37184== Memcheck, a memory error detector
        ==37184== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
        ==37184== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
        ==37184== Command: ./list
        ==37184== Enter a new phrase: First

        +-- List Visualizer --+

        Location 0x4a9b6b0
        Phrase: "First"
        Next: (nil)

        +---------------------+

        Enter a new phrase: Second

        +-- List Visualizer --+

        Location 0x4a9b980
        Phrase: "Second"
        Next: 0x4a9b6b0

        Location 0x4a9b6b0
        Phrase: "First"
        Next: (nil)

        +---------------------+

        Freed the list.
        ==37184== 
        ==37184== HEAP SUMMARY:
        ==37184==     in use at exit: 0 bytes in 0 blocks
        ==37184==   total heap usage: 18 allocs, 18 frees, 1,129 bytes allocated
        ==37184== 
        ==37184== All heap blocks were freed -- no leaks are possible
        ==37184== 
        ==37184== For lists of detected and suppressed errors, rerun with: -s
        ==37184== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

## The file table

* Implements a simple hash table that uses ASCII table to map the first letter of a word to its index.

        sasaka-jr@Sasaka-JR:~/CS50/Week_5/section$ gcc table.c -Wall -Werror -pedantic -o table cs50.c
        sasaka-jr@Sasaka-JR:~/CS50/Week_5/section$ ./table 
        Enter a new phrase: Kale
        Kale hashes to 10
        Enter a new phrase: plate
        plate hashes to 15
        Enter a new phrase: jolly
        jolly hashes to 9
