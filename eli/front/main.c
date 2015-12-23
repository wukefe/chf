
#include "common.h"
#include "token.h"

int main(int argc, char** argv)
{
    char input[] = "for(1;2;3) x = i+0.5; while(x>1); create table";
    tokenizer(input);
    printTK();
    return 0;
}