
#include "common.h"
#include "token.h"

C SignTable[256];

TK headk, headt;

void initTable(){
    DOI(256, SignTable[i] = 0);
    DOI(26, SignTable['a'+i] = SignTable['A'+i] = 1);
    DOI(10, SignTable['0'+i] = 2);
}

TK newTKNode(L typ){TK t=AL(TK0, 1); t->type=typ; t->nxt=NULL; R t;}
void addTKNode(TK t){headt->nxt=t; headt=t;}

void addTokenName(S sta, L len, L type){
    TK tmp = newTKNode(type);
    tmp->v_chr= ALC(len);
    strncpy(tmp->v_chr, sta, len);
    tmp->v_chr[len] = 0;
    addTKNode(tmp);
}

void addTokenOp(C ch0, C ch1, L len, L type){
    TK tmp = newTKNode(type);
    tmp->v_op[0] = ch0;
    if(len==2) tmp->v_op[1] = ch1;
    tmp->v_op[len] = 0; // end of string
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

L mainworker(S s){
    // need to remove negative char
    for(L i=0;s[i]!=0;){
        int sign = SignTable[s[i]];
        if(sign!=0){
            P("%s\n",s);
            switch(sign){
                case 1: i+=getName(s+i); break;
            }
        }
        else {
            // pending
            C ch0 = s[i], ch1 = s[i+1];
            L step = 1, valop = -1;
            B isdot = ch1 == '.';
            switch(ch0){
                case ' ': break;
                case '+': valop = T_Plus;     break;
                case '-': valop = T_Minus;    break;
                case '*': valop = T_Multiply; break;
                case '%': valop = T_Divide;   break;
            }
            if(valop > 0){
                addTokenOp(ch0,ch1,step,valop);
            }
            i += step;
        }
        while(s[i]==' ') i++;
    }
}

L tokenizer(S s){
    initTable();
    headk = AL(TK0, 1);
    headt = headk;
    mainworker(s);
    R 0;
}






