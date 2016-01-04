
#include "common.h"
#include "token.h"
#include "parser.h"

int main(int argc, char** argv)
{
    // char input[] = "for(1;2;3) x = i+0.5; while(x>1); create table";
    // char input[] = "(2)+1 2 3";
    // char input[] = "2 +1 2 3";
    char input[] = "2+1 2 3";
    tokenizer(input);
    mainParser();
    // printTK();
    return 0;
}