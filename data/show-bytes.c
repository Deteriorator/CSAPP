/*
 *
 *-----------------------------------------------------------------------------
 * @Name：    show_bytes.c
 * @Desc:     
 * @Author:   liangz.org@gmail.com
 * @Create:   2020.07.14   9:19
 *-----------------------------------------------------------------------------
 * @Change:   2020.07.14
 *-----------------------------------------------------------------------------
*/

/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}
/* $end show-bytes */

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* $end test-show-bytes */

int main(int argc, char *argv[])
{
    int val = 12345;

    if (argc > 1) {
        if (argc > 1) {
            val = strtol(argv[1], NULL, 0);
        }
        printf("calling test_show_bytes\n");
        test_show_bytes(val);
        // test_show_bytes(val);
    } else {
        test_show_bytes(val);
//        printf("calling show_twocomp\n");
//        show_twocomp();
//        printf("Calling simple_show_a\n");
//        simple_show_a();
//        printf("Calling simple_show_b\n");
//        simple_show_b();
//        printf("Calling float_eg\n");
//        float_eg();
//        printf("Calling string_ueg\n");
//        string_ueg();
//        printf("Calling string_leg\n");
//        string_leg();
    }
    return 0;
}

