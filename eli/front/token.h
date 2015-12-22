
#define T_VarName    0
#define T_Integer    1
#define T_Float      2
#define T_Double     3
#define T_String     4
#define T_Comma     10
#define T_Colon     11
#define T_Semicolon 12
#define T_Dot       13

// primitives
#define T_Plus      20
#define T_Minus     21
#define T_Multiply  22
#define T_Divide    23


#define isA(a) (((a)>='a' && (a)<='z')||((a)>='A' && (a)<='Z'))
#define isN(a) ((a)>='0' && (a)<='9')

L tokenizer(S s);

extern TK headk;