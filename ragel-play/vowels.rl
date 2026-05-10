#include <stdio.h>
#include <string.h>

%%{
    machine counter;

    action count_vowel { vowels++; }

    main := ( [aeiou] @count_vowel | any )* ;

    write data;
}%%

int main(int argc, char **argv) {
    char *p = argv[1];
    char *pe = p + strlen(p);
    int cs;
    int vowels = 0;

    %% write init;
    %% write exec;

    printf("vowels: %d\n", vowels);
    return 0;
}