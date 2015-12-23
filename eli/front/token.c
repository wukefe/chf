
#include "common.h"
#include "token.h"

C SignTable[256];
L localrow, localcol; //for debugging
TK headk, headt;

#define decideTK(f,a,b) (f?step++,a:b)
#define isN(a) (SignTable[a]==2)
#define skipC(a) (a==' ' || a=='\t')

void initTable(){
    DOI(256, SignTable[i] = 0);
    DOI(26, SignTable['a'+i] = SignTable['A'+i] = 1);
    DOI(10, SignTable['0'+i] = 2);
}

TK newTKNode(L typ){TK t=AL(TK0, 1); t->type=typ; t->nxt=NULL; t->row=localrow; t->col=localcol; R t;}
void addTKNode(TK t){headt->nxt=t; headt=t;}


void addTokenOp(S s, L len, L typ){
    TK tmp = newTKNode(typ);
    DOI(len, tmp->v_op[i]=s[i]); tmp->v_op[len]=0;// end of string
    addTKNode(tmp);
}

void addTokenName(S sta, L len, L typ){
    if(!strncmp(sta,"if",2)) addTokenOp("if",2,T_If);
    else if(!strncmp(sta,"for"  ,3)) addTokenOp("for"  ,3,T_For);
    else if(!strncmp(sta,"else" ,4)) addTokenOp("else" ,4,T_Else);
    else if(!strncmp(sta,"while",5)) addTokenOp("while",5,T_While);
    else {
        TK tmp = newTKNode(typ);
        tmp->v_chr= ALC(len);
        strncpy(tmp->v_chr, sta, len);
        tmp->v_chr[len] = 0;
        addTKNode(tmp);
    }
}

void addTokenNumber(S sta, L typ){
    TK tmp = newTKNode(typ); B neg=sta[0]=='_';
    switch(typ){
        case T_Integer: tmp->v_int=atoi(sta+neg)*(neg?-1:1); break;
        case T_Double:  tmp->v_dbv=atof(sta+neg)*(neg?-1:1); break;
    }
    addTKNode(tmp);
}

L getName(S s){
    S t = s;
    if(SignTable[*t]==1){
        t++;
        while(SignTable[*t]==1 || SignTable[*t]==2 || (*t)=='_') t++;
        while(*(t-1) == '_') t--;
        addTokenName(s,t-s,T_VarName);
    }
    return (t-s);
}

L getInt(S s){S t=s;while(isN(*t))t++;R (t-s);}
L getNumber(S s){
    B neg=s[0]=='_'; S t = s+getInt(s+neg)+neg; L typ = T_Integer;
    if(t[0]=='.' && isN(t[1])){ t += getInt(t+1); typ=T_Double; }
    addTokenNumber(s,typ);
    return (t-s);
}

L getString(S s, C ch){
    S t = s;
    while((*t)!=0){
        while((*t)!=ch && (*t)!=0) t++;
        if(t[0]==ch && t[1]==ch) t+=2;
        else break;
    }
    if((*t)==ch) {
        addTokenName(s,t-s,T_String); //add string
        t++; //end of char
    }
    return (t-s);
}

#define T_Comment   112 ////

void mainworker(S s, L ln){
    // need to remove negative char
    localrow = ln;
    for(L i=0;s[i]!=0;){
        C ch0 = s[i], ch1 = s[i+1];
        localcol = i;
        if(ch0=='_' && isN(ch1)){ //number
            i+=getNumber(s+i);
        }
        else if(ch0=='\''){ // string
            i+=1+getString(s+i+1, ch0);
        }
        else {
            int sign = SignTable[s[i]];
            if(sign!=0){
                switch(sign){
                    case 1: i+=getName(s+i);   break;
                    case 2: i+=getNumber(s+i); break;
                }
            }
            else {
                // pending
                L step = 1, valop = -1;
                B isdot = ch1 == '.';
                switch(ch0){
                    case ' ': break;
                    case '+': valop = decideTK(isdot,T_Format   ,T_Plus);     break;
                    case '-': valop = decideTK(ch1=='>',T_Branch,T_Minus);    break;
                    case '*': valop = decideTK(isdot,T_Power    ,T_Multiply); break;
                    case '%': valop = decideTK(isdot,T_Inverse  ,T_Divide);   break;
                    case '.': valop = decideTK(ch1==':',T_Outer ,T_Dot);      break;
                    case '<': valop = decideTK(isdot,T_Encode,decideTK(ch1=='=',T_Lessthan ,decideTK(ch1=='-',T_Get,T_Less))); break;
                    case '>': valop = decideTK(isdot,T_Decode,decideTK(ch1=='=',T_Greatthan,T_Greater));  break;
                    case '^': valop = decideTK(isdot,T_Take   ,T_And);     break;
                    case '!': valop = decideTK(isdot,T_Drop   ,T_Iota);    break;
                    case '_': valop = decideTK(isdot,T_Lower  ,T_Null);    break;
                    case '$': valop = decideTK(isdot,T_Reverse,T_Rotate);  break;
                    case '|': valop = decideTK(isdot,T_Gammar ,T_Bar);     break;
                    case '&': valop = decideTK(isdot,T_Flip   ,T_Or);      break;
                    case '?': valop = decideTK(isdot,T_Deal   ,T_Epislon); break;
                    case '~': valop = decideTK(ch1=='=',T_Notequal,T_Not); break;
                    case ',': valop = decideTK(ch1=='.',T_Raze,T_Comma);   break;
                    case '=': valop = T_Equal;     break;
                    case ':': valop = T_Colon;     break;
                    case ';': valop = T_Semicolon; break;
                    case '"': valop = T_Each;      break;
                    case '{': valop = T_Lparen;    break;
                    case '}': valop = T_Rparen;    break;
                    case '(': valop = T_Lbrace;    break;
                    case ')': valop = T_Rbrace;    break;
                    case '[': valop = decideTK(ch1==']',T_Quad,decideTK(ch1==')',T_BareQuad,T_Lbracket)); break; //[],[)
                    case ']': valop = T_Rbracket;  break;
                    case '@': valop = T_At;        break;
                    case '/': valop = decideTK(ch1=='/',T_Comment,T_Slash); break;
                    case '\\':valop = T_Backslash; break;
                    default:  valop = T_Null;      break;
                }
                if(valop == T_Null){P("A null token has been detected. %c\n",ch0); break;}
                else if(valop == T_Comment) break;
                else if(valop > 0){
                    addTokenOp(s+i,step,valop);
                }
                i += step;
            }
        }
        while(skipC(s[i])) i++;
    }
}

L tokenizer(S s){
    initTable();
    headk = AL(TK0, 1);
    headt = headk;
    mainworker(s, -1);
    R 0;
}


void printTK(){
    TK headt = headk->nxt;
    // int cnt = 0;
    P("type -> value -> r,c\n");
    P(" -----------\n");
    while(headt){
        // P("--- %d\n",cnt);
        P(" %3d -> ",headt->type);
        switch(headt->type){
            case T_VarName:
            case T_String:  P("%s",headt->v_chr); break;
            case T_Integer: P("%d",headt->v_int); break;
            case T_Double:  P("%lf",headt->v_dbv); break;
            default: P("%s",headt->v_op); break;
        }
        P(" --> (%d,%d)\n",headt->row,headt->col);
        headt = headt->nxt;
        // cnt++;
    }
    // delete all tokens
    headt = headk;
    while(headt){
        headk = headk->nxt;
        free(headt);
        headt = headk;
    }
}

