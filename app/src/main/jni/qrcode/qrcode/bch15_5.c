
#include "bch15_5.h"


static const unsigned char gf16_exp[31]={
  1,2,4,8,3,6,12,11,5,10,7,14,15,13,9,1,2,4,8,3,6,12,11,5,10,7,14,15,13,9,1
};


static const signed char gf16_log[16]={
  -1,0,1,4,2,8,5,10,3,14,9,7,6,13,11,12
};


static unsigned gf16_mul(unsigned _a,unsigned _b){
  return _a==0||_b==0?0:gf16_exp[gf16_log[_a]+gf16_log[_b]];
}


static unsigned gf16_div(unsigned _a,unsigned _b){
  return _a==0?0:gf16_exp[gf16_log[_a]+15-gf16_log[_b]];
}


static unsigned gf16_hmul(unsigned _a,unsigned _logb){
  return _a==0?0:gf16_exp[gf16_log[_a]+_logb];
}


static int bch15_5_calc_syndrome(unsigned _s[3],unsigned _y){
  unsigned p;
  int      i;
  int      j;
  p=0;
  for(i=0;i<15;i++)if(_y&1<<i)p^=gf16_exp[i];
  _s[0]=p;
  p=0;
  for(i=0;i<3;i++)for(j=0;j<5;j++)if(_y&1<<5*i+j)p^=gf16_exp[j*3];
  _s[1]=p;
  p=0;
  for(i=0;i<5;i++)for(j=0;j<3;j++)if(_y&1<<3*i+j)p^=gf16_exp[j*5];
  _s[2]=p;
  return _s[0]!=0||_s[1]!=0||_s[2]!=0;
}


static int bch15_5_calc_omega(unsigned _o[3],unsigned _s[3]){
  unsigned s02;
  unsigned tt;
  unsigned dd;
  int      d;
  _o[0]=_s[0];
  s02=gf16_mul(_s[0],_s[0]);
  dd=_s[1]^gf16_mul(_s[0],s02);
  tt=_s[2]^gf16_mul(s02,_s[1]);
  _o[1]=dd?gf16_div(tt,dd):0;
  _o[2]=dd^gf16_mul(_s[0],_o[1]);
  for(d=3;d>0&&!_o[d-1];d--);
  return d;
}


static int bch15_5_calc_epos(unsigned _epos[3],unsigned _s[3]){
  unsigned o[3];
  int      nerrors;
  int      d;
  int      i;
  d=bch15_5_calc_omega(o,_s);
  nerrors=0;
  if(d==1)_epos[nerrors++]=gf16_log[o[0]];
  else if(d>0){
    for(i=0;i<15;i++){
      int i2;
      i2=gf16_log[gf16_exp[i<<1]];
      if(!(gf16_exp[i+i2]^gf16_hmul(o[0],i2)^gf16_hmul(o[1],i)^o[2])){
        _epos[nerrors++]=i;
      }
    }
    if(nerrors<d)return -1;
  }
  return nerrors;
}

int bch15_5_correct(unsigned *_y){
  unsigned s[3];
  unsigned epos[3];
  unsigned y;
  int      nerrors;
  int      i;
  y=*_y;
  if(!bch15_5_calc_syndrome(s,y))return 0;
  nerrors=bch15_5_calc_epos(epos,s);
  if(nerrors>0){
    
    for(i=0;i<nerrors;i++)y^=1<<epos[i];
    
    if(bch15_5_encode(y>>10)==y){
      
      *_y=y;
      return nerrors;
    }
  }
  
  return -1;
}

unsigned bch15_5_encode(unsigned _x){
  return (-(_x&1)&0x0537)^(-(_x>>1&1)&0x0A6E)^(-(_x>>2&1)&0x11EB)^
   (-(_x>>3&1)&0x23D6)^(-(_x>>4&1)&0x429B);
}

#if 0
#include <stdio.h>

static unsigned codes[32];

static int hamming(int _a,int _b){
  int d;
  int n;
  d=_a^_b;
  for(n=0;d;n++)d&=d-1;
  return n;
}

static int closest(int _y){
  int min_i;
  int min_d;
  int i;
  int d;
  min_i=0;
  min_d=hamming(_y,codes[0]);
  for(i=1;i<32;i++){
    d=hamming(_y,codes[i]);
    if(d<min_d){
      min_d=d;
      min_i=i;
    }
  }
  return codes[min_i];
}

int main(void){
  int i;
  
  for(i=0;i<32;i++)codes[i]=bch15_5_encode(i);
  for(i=0;i<32;i++)printf("0x%04X%s",codes[i],i+1<32?"  ":"\n");
  
  for(i=0;i<0x8000;i++){
    unsigned y;
    unsigned z;
    int      nerrors;
    int      j;
    y=i;
    nerrors=bch15_5_correct(&y);
    z=closest(i);
    if(nerrors<0){
      printf("0x%04X->Failed\n",i);
      if(hamming(i,z)<=3)printf("Error: 0x%04X should map to 0x%04X\n",i,z);
    }
    else{
      printf("0x%04X->0x%04X\n",i,y);
      if(z!=y)printf("Error: 0x%04X should map to 0x%04X\n",i,z);
    }
  }
  return 0;
}
#endif
