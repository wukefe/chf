#ifndef __PARSER__
#define __PARSER__


L Monadic();
L PFDyadic();
L PFMonadic();
B PFCommon(Token k);
L Expr();
L SubExpr();
L AllType();
L Number();
L Expr();
L Function();
L Primitive();
L expectStmt(L a);
L Operand();
void mainParser();

#endif