
#define T_VarName    0
#define T_Integer    1
#define T_Float      2
#define T_Double     3
#define T_String     4
#define T_Symbol     5 //`
#define T_Dtime      6
#define T_Month      7
#define T_Date       8
#define T_Minute     9
#define T_Second    10
#define T_Mill      11
#define T_Not       15 //~
#define T_Comma     16 //,
#define T_Colon     17 //:
#define T_Semicolon 18 //;
#define T_Dot       19 //.
#define T_Get       20 //<-
#define T_Branch    21 //->
#define T_Each      22 //"
#define T_At        23 //@
#define T_Quad      24 //[]
#define T_BareQuad  25 //[)

// primitives
#define T_Less      30 //<
#define T_Lessthan  31 //<=
#define T_Greater   32 //>
#define T_Greatthan 33 //>=
#define T_Equal     34 //=
#define T_Notequal  35 //~=
#define T_And       36 //^
#define T_Take      37 //^.
#define T_Or        38 //&
#define T_Flip      39 //&.
#define T_Epislon   40 //?
#define T_Deal      41 //?.
#define T_Iota      42 //!
#define T_Drop      43 //!.
#define T_Plus      44 //+
#define T_Format    45 //+.
#define T_Minus     46 //-
#define T_Multiply  47 //*
#define T_Power     48 //*.
#define T_Divide    49 //%
#define T_Inverse   50 //%.
#define T_Reshape   51 //#
#define T_Domino    52 //#.
#define T_Rotate    53 //$
#define T_Reverse   54 //$.
#define T_Bar       55 //|
#define T_Gammar    56 //|.
#define T_Encode    57 //<.
#define T_Decode    58 //>.
#define T_Lower     59 //_.
#define T_Nand      60 //~^
#define T_Nor       61 //~&
#define T_Raze      62 //,.

// #define T_Inner     80 //f:g
#define T_Outer     81 //.:f

// control structures
#define T_If        100 //if
#define T_Elseif    101 //elseif
#define T_Else      102 //else
#define T_For       103 //for
#define T_While     104 //while
#define T_Lparen    105 //{
#define T_Rparen    106 //}
#define T_Lbrace    107 //(
#define T_Rbrace    108 //)
#define T_Lbracket  109 //[
#define T_Rbracket  110 //]
#define T_Slash     111 ///
#define T_Backslash 112 //\\
#define T_Comment   113 ////
#define T_Null      150 //unknown


// #define isA(a) (((a)>='a' && (a)<='z')||((a)>='A' && (a)<='Z'))
// #define isN(a) ((a)>='0' && (a)<='9')

L tokenizer(S s);
void printTK();

extern TK headk;