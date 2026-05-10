#include <stdio.h>
#include <string.h>

%%{
    machine hello;
    main := "hello" any* ;
    write data;
}%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *p = argv[1];
    char *pe = p + strlen(p);
    int cs;

    %% write init;
    %% write exec;

    if (cs >= hello_first_final)
        printf("match!\n");
    else
        printf("no match\n");

    return 0;
}