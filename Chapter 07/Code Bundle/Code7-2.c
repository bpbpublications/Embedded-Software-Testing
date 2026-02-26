/* Supplementing material for the book Testing Embedded Software by Stephan Gruenfelder
 * and Adam Mackay. The authors welcome your feedback on the book and this sample code.
 * Feel free to contact us via stephan.gruenfelder@gmx.at.
 * This is the file containing the the tests.
 * We do not use a test framework with test selectors, library functions and a 'main' function. 
 * Thus, our test file contains the 'main' function. Program execution begins and ends here.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "Code7-2a.h"  /* Framework header*/
#include "Code7-1a.h"  /* Flash routines header*/

/* our function under test */
extern void file_sqrt();

/* functions that support our tests but are not regular flash routines */
extern void simulate_defective_flash();

/* Testcase 1:
 * Output file does not yet exist. Input from flash w. space characters, 
 * non-digits, decimal numbers and numbers exceeding the 32 bit representation. 
 * This test case covers the largest and smallest valid and invalid 
 * input integer numbers. */
void Testcase1(void)
{
    char szResult[80];
    char* pcExtraLine;
    FILE* f;

    printf("Testcase 1\n");
    MY_ASSERT(INT_MAX == 2147483647); /* make sure we test on the expected CPU */

    /* preparing the flash memory with the needed content */
    remove("out.txt"); /* the function under test (re)creates the file */
    flash_erase();
    flash_open();
    flash_write("2147483647\n"); /* largest valid integer input */
    flash_write("2147483648\n"); /* smallest invalid integer input */
    flash_write("25\n");
    flash_write("15\n");
    flash_write("256\n");
    flash_write("49 \n"); /* trailing space -> error */
    flash_write("4 9\n"); /* inbetween space -> error */
    flash_write(" 49\n"); /* space -> error */
    flash_write("8.9\n"); /* error: no integer */
    flash_write("-1\n"); /* largest invalid integer intput */
    flash_write("0\n"); /* smallest valid integer input */
    flash_close();

    file_sqrt(); /* call of the function under test */

    f = fopen("out.txt", "r");
    MY_ASSERT(f != NULL); /* make sure file exists */

    (void)fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("46340\n", szResult) == 0);

    (void)fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("5\n", szResult) == 0);

    (void)fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("3\n", szResult) == 0);

    (void)fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("16\n", szResult) == 0);

    (void)fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("0\n", szResult) == 0);

    pcExtraLine = fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(pcExtraLine == NULL); /* unexpected line? */
}

/* Testcase 2:
 * out.txt already exists, the flash memory is empty */
void Testcase2(void)
{
    char szResult[20];
    char* pcLine;
    FILE* f;

    printf("Testcase 2\n");

    flash_erase();
    f = fopen("out.txt", "w+");
    fprintf(f, "any content to be overwritten");
    fclose(f);

    file_sqrt();

    /* we verify the result file is empty */
    f = fopen("out.txt", "r");
    MY_ASSERT(f != NULL); /* make sure file exists */
    pcLine = fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(pcLine == NULL); /* verify there is no content */
    fclose(f);
}

/* Testcase 3:
 * Flash memory not accessible */
void Testcase3(void)
{
    /* Testing an inaccessible flash memory is a bit tricky because
     * the result is an empty output file. We thus provide a flash
     * content that, under normal condition,s would result into a non-empty
     * output file and simulate that the flash in inaccessible by 
     * commanding our stub implementation of flash_open to yield the
     * needed return value. */

    char* pcLine;
    FILE* f;
    char szResult[20];

    printf("Testcase 3\n");

    flash_open();
    flash_write("25\n");
    flash_close();
    simulate_defective_flash();

    f = fopen("out.txt", "w+");
    fprintf(f, "remains as it is");
    fclose(f);


    file_sqrt(); /* call of the function under test */

    /* we verify the result file is empty */
    f = fopen("out.txt", "r");
    MY_ASSERT(f != NULL); /* make sure file exists */
    pcLine = fgets(szResult, sizeof(szResult), f);
    MY_ASSERT(strcmp("remains as it is", szResult) == 0);
    fclose(f);
}

/* Testcase 4:
 * File system is not accessible for writing the result */
void Testcase4(void)
{
    printf("Testcase 4 - not implemented\n");
    /* To test the handling of a full file system, we need to stub
     * fopen(), which is difficult. We can do that by writing our
     * implemenation of fopen(), e.g. by copying an open source
     * implemenation and enhancing it with what we need. This 
     * stub implementation has to be linked BEFORE the stdio 
     * gets linked. Otherwise our code under test will call 
     * the stdio implemenation. 
     * The idea of creating such a test case is a good one: it
     * identifies an issue of our function under test, that
     * never checks the return value of fopen(). 
     * This example highlights the importance of crafting unit
     * test cases without looking at the source code.
     */
}

main()
{
    Testcase1();
    Testcase2();
    Testcase3();
    Testcase4();
}

