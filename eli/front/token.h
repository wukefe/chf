
#define T_VarName    0
#define T_Integer    1
#define T_Float      2
#define T_Double     3
#define T_String     4
#define T_Not        9 //~
#define T_Comma     10 //,
#define T_Colon     11 //:
#define T_Semicolon 12 //;
#define T_Dot       13 //.
#define T_Get       14 //<-
#define T_Branch    15 //->
#define T_Each      16 //"
#define T_At        17 //@
#define T_Quad      18 //[]
#define T_BareQuad  19 //[)

// primitives
#define T_Less      20 //<
#define T_Lessthan  21 //<=
#define T_Greater   22 //>
#define T_Greatthan 23 //>=
#define T_Equal     24 //=
#define T_Notequal  25 //~=
#define T_And       26 //^
#define T_Take      27 //^.
#define T_Or        28 //&
#define T_Flip      29 //&.
#define T_Epislon   30 //?
#define T_Deal      31 //?.
#define T_Iota      32 //!
#define T_Drop      33 //!.
#define T_Plus      34 //+
#define T_Format    35 //+.
#define T_Minus     36 //-
#define T_Multiply  37 //*
#define T_Power     38 //*.
#define T_Divide    39 //%
#define T_Inverse   40 //%.
#define T_Reshape   41 //#
#define T_Domino    42 //#.
#define T_Rotate    43 //$
#define T_Reverse   44 //$.
#define T_Bar       45 //|
#define T_Gammar    46 //|.
#define T_Encode    47 //<.
#define T_Decode    48 //>.
#define T_Lower     49 //_.
#define T_Nand      50 //~^
#define T_Nor       51 //~&
#define T_Raze      52 //,.

// #define T_Inner     80 //f:g
#define T_Outer     81 //.:f

// control structures
#define T_If        100 //if
#define T_Else      101 //else
#define T_For       102 //for
#define T_While     103 //while
#define T_Lparen    104 //{
#define T_Rparen    105 //}
#define T_Lbrace    106 //(
#define T_Rbrace    107 //)
#define T_Lbracket  108 //[
#define T_Rbracket  109 //]
#define T_Slash     110 ///
#define T_Backslash 111 //\\
#define T_Comment   112 ////
#define T_Null      150 //unknown


// #define isA(a) (((a)>='a' && (a)<='z')||((a)>='A' && (a)<='Z'))
// #define isN(a) ((a)>='0' && (a)<='9')

L tokenizer(S s);
void printTK();

extern TK headk;