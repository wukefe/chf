
#include "common.h"
#include "token.h"

extern TK headk;

void printTK();

int main(int argc, char** argv)
{
    if(argc==2){
        tokenizer(argv[1]);
        printTK();
    }
    return 0;
}

void printTK(){
    TK headt = headk->nxt;
    int cnt = 0;
    while(headt){
        P("--- %d\n",cnt);
        P("type = %d\n",headt->type);
        if(headt->type == T_VarName){
            P("string = %s\n",headt->v_chr);
            free(headt->v_chr);
        }
        else {
            P("op = %s\n",headt->v_op);
        }
        headt = headt->nxt;
        cnt++;
    }
    headt = headk;
    while(headt){
        headk = headk->nxt;
        free(headt);
        headt = headk;
    }
}