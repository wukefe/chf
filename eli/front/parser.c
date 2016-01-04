
#include "common.h"
#include "token.h"
#include "parser.h"

extern TK headk;
TK tok;
#define tokt tok->type

void error(const C msg[]){P("%s\n",msg);exit(1);}
void nextToken(){if(!tok)error("no more tokens"); tok= tok->nxt;}
L accept(Token k){P("k=%d,%d\n",k,tokt);R (k==tokt?nextToken(),1:0);}
L expect(Token k){
    if(accept(k)) R 1;
    error("expect : unexpected symbol");
    R 0;
}

L expectStmt(L a){if(a) R 1; error("unexpected : statement"); R 0;}

L IfStmt(){R 0;}
L WhileStmt(){R 0;}
L Stmt(){R Expr();}

L Statements(){
    if(IfStmt());
    else if(WhileStmt());
    else if(Stmt());
    else R 0;
    R 1;
}

L Monadic(){if(PFMonadic()){expectStmt(Expr()); R 1;} R 0;}
L Dyadic() {if(Operand()){if(PFDyadic())expectStmt(Expr());R 1;}R 0;}

L PFDyadic(){
    if(tok && (PFCommon(tokt)||tokt==T_Less||tokt==T_Lessthan||tokt==T_Greater||tokt==T_Greatthan)){
        nextToken(); R 1;
    }
    R 0;
}

L PFMonadic(){
    if(tok && (PFCommon(tokt)||tokt==T_Deal)){
        nextToken(); R 1;
    }
    R 0;
}

B PFCommon(Token k){
    R (k==T_Plus||k==T_Minus||k==T_Multiply||k==T_Divide||k==T_Minus||k==T_Equal||k==T_Rotate);
}

L Expr(){
    L r=0;
    if(accept(T_Lbrace)){
        r=SubExpr();
        expect(T_Rbrace);
    }
    else r=SubExpr();
    R r;
}

L SubExpr(){
    if(Function());
    else R Expr();
    // Assign
    R 1;
}

L Operand(){
    if(accept(T_VarName));
    else if(AllType());
    else R 0;
    // ArrayIndex
    R 1;
}

L AllType(){
    if(tok){
        L k = tokt;
        if(Number()){ while(Number()); }
        else if(k==T_String) nextToken();
        else R 0;
        R 1;
    }
    R 0;
}

L Number(){
    if(tok && (tokt==T_Integer||tokt==T_Float||tokt==T_Double)){
        P("entering Number\n");
        nextToken();
        R 1;
    }
    R 0;
}

L Function(){
    if(tok){
        if(Primitive());
        else R 0;
        R 1;
    }
    R 0;
}

L Primitive(){
    if(Monadic());
    else if(Dyadic());
    else R 0;
    R 1;
}

void mainParser(){
    tok = headk; nextToken();
    // Monadic();
    while(tok && Expr());
    if(!tok){
        P("parse successfully\n");
    }
    else {
        P("some error!\n");
    }
}
