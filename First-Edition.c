#include <Keypad.h>
#include <RSCG12864B.h>


const byte ROW=1;
const byte COL=4;

char modes[ROW][COL]={
  {'-','+','(',')'}
};
byte rowPin[ROW]={38};
byte colPin[COL]={42,44,46,48};
Keypad modeselect=Keypad(makeKeymap(modes),rowPin,colPin,ROW,COL);

const byte UP = 8;
const byte DOWN =11;

char keys[UP][DOWN]={
  {'1','2','3','4','5','6','7','8','9','0','"'},
  {'a','b','c','d','e','f','g','h','i','j',','},
  {'k','l','m','n','o','p','q','r','s','t','<'},
  {'u','v','w','x','y','z','!','@','#','$','>'},
  {'A','B','C','D','E','F','G','H','I','J','.'},
  {'K','L','M','N','O','P','Q','R','S','T','?'},
  {'U','V','W','X','Y','Z','%','^','&','*','/'},
  {'`','~','_','=','{','}','[',']','|',';',':'}
};

byte upPin[UP]={23,25,27,29,31,33,35,22};//ordered by rows,so 23-37 connect to upper film
byte downPin[DOWN]={36,39,41,43,45,47,49,51,53,52,24};//ordered by cols so 39-53-52 connect to lower film
Keypad filmsensor= Keypad(makeKeymap(keys),upPin,downPin,UP,DOWN);
int scores= 0 ;
int times=0;
int tostart301=0;
int rounds=0;
int finish=0;
int fail=0;
int setgame=0;
int tipsgiven=0;

bool competition;
int p1;
int p2;
int tostart301a=0;
int tostart301b=0;
int pscore;

char* itostr(char *str, int i)
{
  sprintf(str, "%d", i);
  return str;
}


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   RSCG12864B.begin();
   RSCG12864B.brightness(255);

}

void loop() {
  // put your main code here, to run repeatedly:
//301 points single person mode
char sc[4];

char mode=modeselect.getKey();
if(mode){  
    RSCG12864B.clear();

  switch(mode)
{  case '(':
scores= 301 ;
times=0;
tostart301=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
Serial.println("301 game starts");
RSCG12864B.print_string_12_xy(10,20,"New game for 301");

delay(1200);
  break;
  case ')':
scores=501;
times=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
tostart301=1;
Serial.println("501 game starts");
RSCG12864B.print_string_12_xy(10,20,"New game for 501");

delay(1200);
  break;
  case '-':
  scores=301;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=0;
  tostart301b=0;
  p1=301;
  p2=301;
  Serial.println("301 match starts");
RSCG12864B.print_string_12_xy(10,20,"New match for 301");

  delay(1200);

  break;
  case '+':
   scores=501;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=1;
  tostart301b=1;
  p1=501;
  p2=501;
    Serial.println("501 match starts");
RSCG12864B.print_string_12_xy(10,20,"New match for 501");

    delay(1200);

  break;

}
}




while(competition){
if(times % 3 == 0&& tipsgiven == 0)
{ tipsgiven=1;  
  Serial.println(scores);
  RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score      Tips");

itostr(sc,scores);
  RSCG12864B.print_string_12_xy(8,20,sc);
if (scores==170){
Serial.println("T20,T20,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,DB");}
if (scores==169||scores==168||scores==166||scores==165||scores==163||scores==162||scores==159||scores>170){
Serial.println("Have Fun!");
RSCG12864B.print_string_12_xy(30,30,"Have Fun!");
}
if (scores==167){
Serial.println("T20,T19,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,DB");}
if (scores==164){
Serial.println("T19,T19,DB");
RSCG12864B.print_string_12_xy(30,20,"T19,T19,DB");}
if (scores==161){
Serial.println("T20,T17,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,DB");}
if (scores==160){
Serial.println("T20,T20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D20");}
if (scores==158){
Serial.println("T20,T20,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D19");}
if (scores==157){
Serial.println("T20,T19,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D20");}
if (scores==156){
Serial.println("T20,T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D18");}
if (scores==155){
Serial.println("T20,T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D18");}
if (scores==154){
Serial.println("T20,T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D20");}
if (scores==153){
Serial.println("T20,T19,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D18");}
if (scores==152){
Serial.println("T20,T20,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D16");}
if (scores==151){
Serial.println("T20,T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D20");}
if (scores==150){
Serial.println("T20,T18,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D19");}
if (scores==149){
Serial.println("T20,T19,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D16");}
if (scores==148){
Serial.println("T20,T20,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D14");}
if (scores==147){
Serial.println("T20,T17,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D18");}
if (scores==146){
Serial.println("T20,T18,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D16");}
if (scores==145){
Serial.println("T20,T19,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D14");}
if (scores==144){
Serial.println("T20,T20,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D12");}
if (scores==143){
Serial.println("T20,T17,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D16");}
if (scores==142){
Serial.println("T20,T14,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D12");}
if (scores==141){
Serial.println("T20,T19,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D12");}
if (scores==140){
Serial.println("T20,T20,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D10");}
if (scores==139){
Serial.println("T20,T13,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T13,D20");}
if (scores==138){
Serial.println("T20,T18,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D12");}
if (scores==137){
Serial.println("T20,T19,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D10");}
if (scores==136){
Serial.println("T20,T20,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D8");}
if (scores==135){
Serial.println("T20,T17,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D12");}
if (scores==134){
Serial.println("T20,T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D16");}
if (scores==133){
Serial.println("T20,T19,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D8");}
if (scores==132){
Serial.println("T20,T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T16,D12");}
if (scores==131){
Serial.println("T20,T13,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T13,D16");}
if (scores==130){
Serial.println("T20,T20,D5");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D5");}
if (scores==129){
Serial.println("T19,T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T19,T16,D12");}
if (scores==128){
Serial.println("T18,T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T18,T14,D16");}
if (scores==127){
Serial.println("T20,T17,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D8");}
if (scores==126){
Serial.println("T19,T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T19,T19,D6");}
if (scores==125){
Serial.println("T18,T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T18,T19,D6");}
if (scores==124){
Serial.println("T20,T14,D11");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D11");}
if (scores==123){
Serial.println("T19,T16,D9");
RSCG12864B.print_string_12_xy(30,20,"T19,T16,D9");}
if (scores==122){
Serial.println("T18,T18,D7");
RSCG12864B.print_string_12_xy(30,20,"T18,T18,D7");}
if (scores==121){
Serial.println("T20,T11,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T11,D14");}
if (scores==120){
Serial.println("T20,S20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S20,D20");}
if (scores==119){
Serial.println("T19,T12,D13");
RSCG12864B.print_string_12_xy(30,20,"T19,T12,D13");}
if (scores==118){
Serial.println("T20,S18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S18,D20");}
if (scores==117){
Serial.println("T20,S17,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S17,D20");}
if (scores==116){
Serial.println("T19,S19,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S19,D20");}
if (scores==115){
Serial.println("T19,S18,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S18,D20");}
if (scores==114){
Serial.println("T20,S14,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S14,D20");}
if (scores==113){
Serial.println("T19,S16,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S16,D20");}
if (scores==112){
Serial.println("T20,S12,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,S12,D8");}
if (scores==111){
Serial.println("T20,S11,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S11,D20");}
if (scores==110){
Serial.println("T20,T10,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T10,D10");}
if (scores==109){
Serial.println("T20,S9,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S9,D20");}
if (scores==108){
Serial.println("T20,S16,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S16,D16");}
if (scores==107){
Serial.println("T19,T10,D10");
RSCG12864B.print_string_12_xy(30,20,"T19,T10,D10");}
if (scores==106){
Serial.println("T20,S14,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S14,D16");}
if (scores==105){
Serial.println("T20,S13,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S13,D16");}
if (scores==104){
Serial.println("T19,S15,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,S15,D16");}
if (scores==103){
Serial.println("T19,S6,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S6,D20");}
if (scores==102){
Serial.println("T20,S10,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S10,D16");}
if (scores==101){
Serial.println("T20,S9,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S9,D16");}
if (scores==100){
Serial.println("T20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,D20");}
if (scores==99){
Serial.println("T19,S10,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,S10,D16");}
if (scores==98){
Serial.println("T20,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,D19");}
if (scores==97){
Serial.println("T19,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,D20");}
if (scores==96){
Serial.println("T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,D18");}
if (scores==95){
Serial.println("T19,D19");
RSCG12864B.print_string_12_xy(30,20,"T19,D19");}
if (scores==94){
Serial.println("T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T18,D20");}
if (scores==93){
Serial.println("T19,D18");
RSCG12864B.print_string_12_xy(30,20,"T19,D18");}
if (scores==92){
Serial.println("T20,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,D16");}
if (scores==91){
Serial.println("T17,D20");
RSCG12864B.print_string_12_xy(30,20,"T17,D20");}
if (scores==90){
Serial.println("T20,D15");
RSCG12864B.print_string_12_xy(30,20,"T20,D15");}
if (scores==89){
Serial.println("T19,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,D16");}
if (scores==88){
Serial.println("T20,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,D14");}
if (scores==87){
Serial.println("T17,D18");
RSCG12864B.print_string_12_xy(30,20,"T17,D18");}
if (scores==86){
Serial.println("T18,D16");
RSCG12864B.print_string_12_xy(30,20,"T18,D16");}
if (scores==85){
Serial.println("T19,D14");
RSCG12864B.print_string_12_xy(30,20,"T19,D14");}
if (scores==84){
Serial.println("T20,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,D12");}
if (scores==83){
Serial.println("T17,D16");
RSCG12864B.print_string_12_xy(30,20,"T17,D16");}
if (scores==82){
Serial.println("T14,D20");
RSCG12864B.print_string_12_xy(30,20,"T14,D20");}
if (scores==81){
Serial.println("T19,D12");
RSCG12864B.print_string_12_xy(30,20,"T19,D12");}
if (scores==80){
Serial.println("T20,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,D10");}
if (scores==79){
Serial.println("T13,D20");
RSCG12864B.print_string_12_xy(30,20,"T13,D20");}
if (scores==78){
Serial.println("T18,D12");
RSCG12864B.print_string_12_xy(30,20,"T18,D12");}
if (scores==77){
Serial.println("T19,D10");
RSCG12864B.print_string_12_xy(30,20,"T19,D10");}
if (scores==76){
Serial.println("T20,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,D8");}
if (scores==75){
Serial.println("T17,D12");
RSCG12864B.print_string_12_xy(30,20,"T17,D12");}
if (scores==74){
Serial.println("T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T14,D16");}
if (scores==73){
Serial.println("T19,D8");
RSCG12864B.print_string_12_xy(30,20,"T19,D8");}
if (scores==72){
Serial.println("T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T16,D12");}
if (scores==71){
Serial.println("T13,D16");
RSCG12864B.print_string_12_xy(30,20,"T13,D16");}
if (scores==70){
Serial.println("T18,D8");
RSCG12864B.print_string_12_xy(30,20,"T18,D8");}
if (scores==69){
Serial.println("T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T19,D6");}
if (scores==68){
Serial.println("T18,D7");
RSCG12864B.print_string_12_xy(30,20,"T18,D7");}
if (scores==67){
Serial.println("T17,D8");
RSCG12864B.print_string_12_xy(30,20,"T17,D8");}
if (scores==66){
Serial.println("T10,D18");
RSCG12864B.print_string_12_xy(30,20,"T10,D18");}
if (scores==65){
Serial.println("T19,D4");
RSCG12864B.print_string_12_xy(30,20,"T19,D4");}
if (scores==64){
Serial.println("T16,D8");
RSCG12864B.print_string_12_xy(30,20,"T16,D8");}
if (scores==63){
Serial.println("T17,D6");
RSCG12864B.print_string_12_xy(30,20,"T17,D6");}
if (scores==62){
Serial.println("T10,D16");
RSCG12864B.print_string_12_xy(30,20,"T10,D16");}
if (scores==61){
Serial.println("T15,D8");
RSCG12864B.print_string_12_xy(30,20,"T15,D8");}
if (scores==60){
Serial.println("S20,D20");
RSCG12864B.print_string_12_xy(30,20,"S20,D20");}
if (scores==59){
Serial.println("S19,D20");
RSCG12864B.print_string_12_xy(30,20,"S19,D20");}
if (scores==58){
Serial.println("S18,D20");
RSCG12864B.print_string_12_xy(30,20,"S18,D20");}
if (scores==57){
Serial.println("S17,D20");
RSCG12864B.print_string_12_xy(30,20,"S17,D20");}
if (scores==56){
Serial.println("S16,D20");
RSCG12864B.print_string_12_xy(30,20,"S16,D20");}
if (scores==55){
Serial.println("S15,D20");
RSCG12864B.print_string_12_xy(30,20,"S15,D20");}
if (scores==54){
Serial.println("S14,D20");
RSCG12864B.print_string_12_xy(30,20,"S14,D20");}
if (scores==53){
Serial.println("S13,D20");
RSCG12864B.print_string_12_xy(30,20,"S13,D20");}
if (scores==52){
Serial.println("T12,D8");
RSCG12864B.print_string_12_xy(30,20,"T12,D8");}
if (scores==51){
Serial.println("S11,D20");
RSCG12864B.print_string_12_xy(30,20,"S11,D20");}
if (scores==50){
Serial.println("S10,D20");
RSCG12864B.print_string_12_xy(30,20,"S10,D20");}
if (scores==49){
Serial.println("S9,D20");
RSCG12864B.print_string_12_xy(30,20,"S9,D20");}
if (scores==48){
Serial.println("S16,D16");
RSCG12864B.print_string_12_xy(30,20,"S16,D16");}
if (scores==47){
Serial.println("S7,D20");
RSCG12864B.print_string_12_xy(30,20,"S7,D20");}
if (scores==46){
Serial.println("S6,D20");
RSCG12864B.print_string_12_xy(30,20,"S6,D20");}
if (scores==45){
Serial.println("S13,D16");
RSCG12864B.print_string_12_xy(30,20,"S13,D16");}
if (scores==44){
Serial.println("S12,D16");
RSCG12864B.print_string_12_xy(30,20,"S12,D16");}
if (scores==43){
Serial.println("S11,D16");
RSCG12864B.print_string_12_xy(30,20,"S11,D16");}
if (scores==42){
Serial.println("S10,D16");
RSCG12864B.print_string_12_xy(30,20,"S10,D16");}
if (scores==41){
Serial.println("S9,D16");
RSCG12864B.print_string_12_xy(30,20,"S9,D16");}
if (scores==40){
Serial.println("D20");
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==39){
Serial.println("S7,D16");
RSCG12864B.print_string_12_xy(30,20,"S7,D16");}
if (scores==38){
Serial.println("D19");
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==37){
Serial.println("S5,D16");
RSCG12864B.print_string_12_xy(30,20,"S5,D16");}
if (scores==36){
Serial.println("D18");
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==35){
Serial.println("S3,D16");
RSCG12864B.print_string_12_xy(30,20,"S3,D16");}
if (scores==34){
Serial.println("D17");
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==33){
Serial.println("S17,D8");
RSCG12864B.print_string_12_xy(30,20,"S17,D8");}
if (scores==32) {
Serial.println("D16");
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==31){
Serial.println("S15,D8");
RSCG12864B.print_string_12_xy(30,20,"S15,D8");}
if (scores==30){
Serial.println("D15");
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==29){
Serial.println("S13,D8");
RSCG12864B.print_string_12_xy(30,20,"S13,D8");}
if (scores==28){
Serial.println("D14");
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==27){
Serial.println("S19,D4");
RSCG12864B.print_string_12_xy(30,20,"S19,D4");}
if (scores==26){
Serial.println("D13");
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==25){
Serial.println("S17,D4");
RSCG12864B.print_string_12_xy(30,20,"S17,D4");}
if (scores==24){
Serial.println("D12");
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==23){
Serial.println("S7,D8");
RSCG12864B.print_string_12_xy(30,20,"S7,D8");}
if (scores==22){
Serial.println("D11");
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==21){
Serial.println("S5,D8");
RSCG12864B.print_string_12_xy(30,20,"S5,D8");}
if (scores==20){
Serial.println("D10");
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==19){
Serial.println("S11,D4");
RSCG12864B.print_string_12_xy(30,20,"S11,D4");}
if (scores==18){
Serial.println("D9");
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==17){
Serial.println("S9,D4");
RSCG12864B.print_string_12_xy(30,20,"S9,D4");}
if (scores==16){
Serial.println("D8");
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==15){
Serial.println("S7,D4");
RSCG12864B.print_string_12_xy(30,20,"S7,D4");}
if (scores==14){
Serial.println("D7");
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==13){
Serial.println("S5,D4");
RSCG12864B.print_string_12_xy(30,20,"S5,D4");}
if (scores==12){
Serial.println("D6");
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==11){
Serial.println("S3,D4");
RSCG12864B.print_string_12_xy(30,20,"S3,D4");}
if (scores==10){
Serial.println("D5");
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==9){
Serial.println("S1,D4");
RSCG12864B.print_string_12_xy(30,20,"S1,D4");}
if (scores==8){
Serial.println("D4");
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==7){
Serial.println("S3,D2");
RSCG12864B.print_string_12_xy(30,20,"S3,D2");}
if (scores==6){
Serial.println("D3");
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==5){
Serial.println("S1,D2");
RSCG12864B.print_string_12_xy(30,20,"S1,D2");}
if (scores==4){
Serial.println("D2");
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==3){
Serial.println("S1,D1");
RSCG12864B.print_string_12_xy(30,20,"S1,D1");}
if (scores==2){
Serial.println("D1");
RSCG12864B.print_string_12_xy(30,20,"D1");}


  
}

char key= filmsensor.getKey();
  if(key)//读出飞出去或者打到板上时的信号

  {   tipsgiven=0;
  if(tostart301a==0){
     if(times % 6==1||times % 6==2||times % 6==0){
      if(key=='Q'||key=='P'||key=='O'||key=='e'||key=='f'||key=='g'||key=='h'||key=='i'||key=='j'||key=='d'||key=='c'||key=='b'||key=='a'||key=='K'||key=='L'||key=='M'||key=='N'||key=='T'||key=='S'||key=='R'||key=='u')//判断是否打到双倍区
      {tostart301a=1;
        switch(key){
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case 'u':
scores=scores-50;
break;
        }
      }
      else{
        Serial.println("Hit double areas first!");
        RSCG12864B.clear();
        RSCG12864B.print_string_12_xy(10,20,"Hit double areas first!");
        delay(1000);
      }
      
     }
  }
     else if(tostart301a==1)
    { if(times%6==1||times%6==2||times%6==0){
      switch(key)//给p1算分
      {
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case '^':
scores=scores-9;
break;
case '%':
scores=scores-51;
break;
case 'Z':
scores=scores-6;
break;
case 'Y':
scores=scores-45;
break;
case '5':
scores=scores-30;
break;
case '6':
scores=scores-18;
break;
case '7':
scores=scores-39;
break;
case '8':
scores=scores-12;
break;
case '9':
scores=scores-54;
break;
case '0':
scores=scores-3;
break;
case '4':
scores=scores-60;
break;
case '3':
scores=scores-15;
break;
case '2':
scores=scores-36;
break;
case '1':
scores=scores-27;
break;
case 'U':
scores=scores-42;
break;
case 'V':
scores=scores-33;
break;
case 'W':
scores=scores-24;
break;
case 'X':
scores=scores-48;
break;
case '*':
scores=scores-21;
break;
case '&':
scores=scores-57;
break;
case 'v':
scores=scores-25;
break;
case 'u':
scores=scores-50;
break;
case 'n':
scores=scores-20;
break;
case 'D':
scores=scores-16;
break;
case 'I':
scores=scores-19;
break;
case 'm':
scores=scores-5;
break;
case 'l':
scores=scores-12;
break;
case 'k':
scores=scores-9;
break;
case 'A':
scores=scores-14;
break;
case 'B':
scores=scores-11;
break;
case 'C':
scores=scores-8;
break;
case 'J':
scores=scores-7;
break;
case 'F':
scores=scores-2;
break;
case 'E':
scores=scores-15;
break;
case 'o':
scores=scores-10;
break;
case 'p':
scores=scores-6;
break;
case 'q':
scores=scores-13;
break;
case 'r':
scores=scores-4;
break;
case 's':
scores=scores-18;
break;
case 't':
scores=scores-1;
break;
case 'H':
scores=scores-3;
break;
case 'G':
scores=scores-17;
break;
    }
    }
  }
  if(tostart301b==0){
    if(times % 6==3||times % 6 ==4||times % 6==5){
      if(key=='Q'||key=='P'||key=='O'||key=='e'||key=='f'||key=='g'||key=='h'||key=='i'||key=='j'||key=='d'||key=='c'||key=='b'||key=='a'||key=='D'||key=='L'||key=='M'||key=='N'||key=='T'||key=='S'||key=='R'||key=='u')//判断是否打到双倍区
    { tostart301b=1;
      switch(key){
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case 'u':
scores=scores-50;
break;
      }
      
    }
    else{
        Serial.println("Hit double areas first!");
           RSCG12864B.clear();
              RSCG12864B.print_string_12_xy(10,20,"Hit double areas first!");
              delay(1000);
      }
    }
  }
  else if(tostart301b==1)
  {if(times%6==3||times%6==4||times%6==5){
    switch(key)//给p2算分
    {
      
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case '^':
scores=scores-9;
break;
case '%':
scores=scores-51;
break;
case 'Z':
scores=scores-6;
break;
case 'Y':
scores=scores-45;
break;
case '5':
scores=scores-30;
break;
case '6':
scores=scores-18;
break;
case '7':
scores=scores-39;
break;
case '8':
scores=scores-12;
break;
case '9':
scores=scores-54;
break;
case '0':
scores=scores-3;
break;
case '4':
scores=scores-60;
break;
case '3':
scores=scores-15;
break;
case '2':
scores=scores-36;
break;
case '1':
scores=scores-27;
break;
case 'U':
scores=scores-42;
break;
case 'V':
scores=scores-33;
break;
case 'W':
scores=scores-24;
break;
case 'X':
scores=scores-48;
break;
case '*':
scores=scores-21;
break;
case '&':
scores=scores-57;
break;
case 'v':
scores=scores-25;
break;
case 'u':
scores=scores-50;
break;
case 'n':
scores=scores-20;
break;
case 'D':
scores=scores-16;
break;
case 'I':
scores=scores-19;
break;
case 'm':
scores=scores-5;
break;
case 'l':
scores=scores-12;
break;
case 'k':
scores=scores-9;
break;
case 'A':
scores=scores-14;
break;
case 'B':
scores=scores-11;
break;
case 'C':
scores=scores-8;
break;
case 'J':
scores=scores-7;
break;
case 'F':
scores=scores-2;
break;
case 'E':
scores=scores-15;
break;
case 'o':
scores=scores-10;
break;
case 'p':
scores=scores-6;
break;
case 'q':
scores=scores-13;
break;
case 'r':
scores=scores-4;
break;
case 's':
scores=scores-18;
break;
case 't':
scores=scores-1;
break;
case 'H':
scores=scores-3;
break;
case 'G':
scores=scores-17;
break;
    }
  }
  }
if(scores>1){
  Serial.println(scores);
  RSCG12864B.clear();
  RSCG12864B.print_string_16_xy(8,0,"Score       Tips");
  
itostr(sc,scores);
  RSCG12864B.print_string_12_xy(8,20,sc);
}
    times=times+1;
    if(scores==0){
      if(key=='Q'||key=='P'||key=='O'||key=='e'||key=='f'||key=='g'||key=='h'||key=='i'||key=='j'||key=='d'||key=='c'||key=='b'||key=='a'||key=='K'||key=='L'||key=='M'||key=='N'||key=='T'||key=='S'||key=='R'||key=='u')
      {
        if(times%6==1||times%6==2||times%6==3){
          Serial.println("Player 1 wins!");
          RSCG12864B.clear();
          RSCG12864B.print_string_12_xy(10,20,"Player 1 wins!");
          
        }
        if(times%6==4||times%6==5||times%6==0){
          Serial.println("Player 2 wins!");
          RSCG12864B.clear();
          RSCG12864B.print_string_12_xy(10,20,"Player 2 wins!");
        }
        competition=false;
      }
    }
    
    if(rounds<10){
       if(scores<=1){

        if(times % 3 ==1){
        times=times+2;
        }
        else if(times % 3 ==2){
          times=times+1;
        }

        //这里只要p1 p2不变就可以实现这轮没分了
          }
         if(times%6==0)
          {
            rounds=rounds+1;
           if(rounds==10){
           competition=false;
           Serial.println("Aim at the bull to decide who wins.");
              RSCG12864B.clear();
          RSCG12864B.print_string_12_xy(10,20,"Aim at the bull to decide who wins.");
           }
          }
       if (times % 3==0&& times % 2 ==1&&rounds<10){
            if(scores>1){
            p1=scores;
            }
            scores=p2;
            tipsgiven=0;
            Serial.println("Next Player. Take off the darts in 15 seconds.");
             RSCG12864B.clear();
          RSCG12864B.print_string_12_xy(10,10,"Next Player.");
          RSCG12864B.print_string_12_xy(10,30,"Take off the darts in 15 seconds.");
            delay(15000);
            
          }
        else if(times % 6==0&&rounds<10){
          if(scores>1){
            p2=scores;
          }
            scores=p1;
            tipsgiven=0;
            Serial.println("Next player. Next round starts in 15 seconds. Take off the darts.");
                  RSCG12864B.clear();
          RSCG12864B.print_string_12_xy(10,20,"Next Player.");
          RSCG12864B.print_string_12_xy(10,40,"Next round starts in 15 seconds.");
          RSCG12864B.print_string_12_xy(10,60,"Take off the darts.");
            delay(15000);
            delay(15000);
            
          }
         


    
    if(times % 3 ==1&&rounds<10){
      tipsgiven=1;
  Serial.println(scores);
  RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score     Tips");
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
     if (scores==170){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==169||scores==168||scores==166||scores==165||scores==163||scores==162||scores==159||scores>170){
Serial.println("Have Fun!");
RSCG12864B.print_string_12_xy(30,30,"Have Fun!");
}
if (scores==167){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==164){
Serial.println("T19,T19");
RSCG12864B.print_string_12_xy(30,20,"T19,T19");}
if (scores==161){
Serial.println("T20,T17");
RSCG12864B.print_string_12_xy(30,20,"T20,T17");}
if (scores==160){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==158){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==157){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==156){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==155){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==154){
Serial.println("T20,T18");
RSCG12864B.print_string_12_xy(30,20,"T20,T18");}
if (scores==153){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==152){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==151){
Serial.println("T20,T18");
RSCG12864B.print_string_12_xy(30,20,"T20,T18");}
if (scores==150){
Serial.println("T20,T18");
RSCG12864B.print_string_12_xy(30,20,"T20,T18");}
if (scores==149){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==148){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==147){
Serial.println("T20,T17");
RSCG12864B.print_string_12_xy(30,20,"T20,T17");}
if (scores==146){
Serial.println("T20,T18");
RSCG12864B.print_string_12_xy(30,20,"T20,T18");}
if (scores==145){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==144){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==143){
Serial.println("T20,T17");
RSCG12864B.print_string_12_xy(30,20,"T20,T17");}
if (scores==142){
Serial.println("T20,T14");
RSCG12864B.print_string_12_xy(30,20,"T20,T14");}
if (scores==141){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==140){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==139){
Serial.println("T20,T13");
RSCG12864B.print_string_12_xy(30,20,"T20,T13");}
if (scores==138){
Serial.println("T20,T18");
RSCG12864B.print_string_12_xy(30,20,"T20,T18");}
if (scores==137){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==136){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==135){
Serial.println("T20,T17");
RSCG12864B.print_string_12_xy(30,20,"T20,T17");}
if (scores==134){
Serial.println("T20,T14");
RSCG12864B.print_string_12_xy(30,20,"T20,T14");}
if (scores==133){
Serial.println("T20,T19");
RSCG12864B.print_string_12_xy(30,20,"T20,T19");}
if (scores==132){
Serial.println("T20,T16");
RSCG12864B.print_string_12_xy(30,20,"T20,T16");}
if (scores==131){
Serial.println("T20,T13");
RSCG12864B.print_string_12_xy(30,20,"T20,T13");}
if (scores==130){
Serial.println("T20,T20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20");}
if (scores==129){
Serial.println("T19,T16");
RSCG12864B.print_string_12_xy(30,20,"T19,T16");}
if (scores==128){
Serial.println("T18,T14");
RSCG12864B.print_string_12_xy(30,20,"T18,T14");}
if (scores==127){
Serial.println("T20,T17");
RSCG12864B.print_string_12_xy(30,20,"T20,T17");}
if (scores==126){
Serial.println("T19,T19");
RSCG12864B.print_string_12_xy(30,20,"T19,T19");}
if (scores==125){
Serial.println("T18,T19");
RSCG12864B.print_string_12_xy(30,20,"T18,T19");}
if (scores==124){
Serial.println("T20,T14");
RSCG12864B.print_string_12_xy(30,20,"T20,T14");}
if (scores==123){
Serial.println("T19,T16");
RSCG12864B.print_string_12_xy(30,20,"T19,T16");}
if (scores==122){
Serial.println("T18,T18");
RSCG12864B.print_string_12_xy(30,20,"T18,T18");}
if (scores==121){
Serial.println("T20,T11");
RSCG12864B.print_string_12_xy(30,20,"T20,T11");}
if (scores==120){
Serial.println("T20,S20");
RSCG12864B.print_string_12_xy(30,20,"T20,S20");}
if (scores==119){
Serial.println("T19,T12");
RSCG12864B.print_string_12_xy(30,20,"T19,T12");}
if (scores==118){
Serial.println("T20,S18");
RSCG12864B.print_string_12_xy(30,20,"T20,S18");}
if (scores==117){
Serial.println("T20,S17");
RSCG12864B.print_string_12_xy(30,20,"T20,S17");}
if (scores==116){
Serial.println("T19,S19");
RSCG12864B.print_string_12_xy(30,20,"T19,S19");}
if (scores==115){
Serial.println("T19,S18");
RSCG12864B.print_string_12_xy(30,20,"T19,S18");}
if (scores==114){
Serial.println("T20,S14");
RSCG12864B.print_string_12_xy(30,20,"T20,S14");}
if (scores==113){
Serial.println("T19,S16");
RSCG12864B.print_string_12_xy(30,20,"T19,S16");}
if (scores==112){
Serial.println("T20,S12");
RSCG12864B.print_string_12_xy(30,20,"T20,S12");}
if (scores==111){
Serial.println("T20,S11");
RSCG12864B.print_string_12_xy(30,20,"T20,S11");}
if (scores==110){
Serial.println("T20,T10");
RSCG12864B.print_string_12_xy(30,20,"T20,T10");}
if (scores==109){
Serial.println("T20,S9");
RSCG12864B.print_string_12_xy(30,20,"T20,S9");}
if (scores==108){
Serial.println("T20,S16");
RSCG12864B.print_string_12_xy(30,20,"T20,S16");}
if (scores==107){
Serial.println("T19,T10");
RSCG12864B.print_string_12_xy(30,20,"T19,T10");}
if (scores==106){
Serial.println("T20,S14");
RSCG12864B.print_string_12_xy(30,20,"T20,S14");}
if (scores==105){
Serial.println("T20,S13");
RSCG12864B.print_string_12_xy(30,20,"T20,S13");}
if (scores==104){
Serial.println("T19,S15");
RSCG12864B.print_string_12_xy(30,20,"T19,S15");}
if (scores==103){
Serial.println("T19,S6");
RSCG12864B.print_string_12_xy(30,20,"T19,S6");}
if (scores==102){
Serial.println("T20,S10");
RSCG12864B.print_string_12_xy(30,20,"T20,S10");}
if (scores==101){
Serial.println("T20,S9");
RSCG12864B.print_string_12_xy(30,20,"T20,S9");}
if (scores==100){
Serial.println("T20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,D20");}
if (scores==99){
Serial.println("T19,S10");
RSCG12864B.print_string_12_xy(30,20,"T19,S10");}
if (scores==98){
Serial.println("T20,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,D19");}
if (scores==97){
Serial.println("T19,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,D20");}
if (scores==96){
Serial.println("T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,D18");}
if (scores==95){
Serial.println("T19,D19");
RSCG12864B.print_string_12_xy(30,20,"T19,D19");}
if (scores==94){
Serial.println("T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T18,D20");}
if (scores==93){
Serial.println("T19,D18");
RSCG12864B.print_string_12_xy(30,20,"T19,D18");}
if (scores==92){
Serial.println("T20,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,D16");}
if (scores==91){
Serial.println("T17,D20");
RSCG12864B.print_string_12_xy(30,20,"T17,D20");}
if (scores==90){
Serial.println("T20,D15");
RSCG12864B.print_string_12_xy(30,20,"T20,D15");}
if (scores==89){
Serial.println("T19,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,D16");}
if (scores==88){
Serial.println("T20,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,D14");}
if (scores==87){
Serial.println("T17,D18");
RSCG12864B.print_string_12_xy(30,20,"T17,D18");}
if (scores==86){
Serial.println("T18,D16");
RSCG12864B.print_string_12_xy(30,20,"T18,D16");}
if (scores==85){
Serial.println("T19,D14");
RSCG12864B.print_string_12_xy(30,20,"T19,D14");}
if (scores==84){
Serial.println("T20,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,D12");}
if (scores==83){
Serial.println("T17,D16");
RSCG12864B.print_string_12_xy(30,20,"T17,D16");}
if (scores==82){
Serial.println("T14,D20");
RSCG12864B.print_string_12_xy(30,20,"T14,D20");}
if (scores==81){
Serial.println("T19,D12");
RSCG12864B.print_string_12_xy(30,20,"T19,D12");}
if (scores==80){
Serial.println("T20,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,D10");}
if (scores==79){
Serial.println("T13,D20");
RSCG12864B.print_string_12_xy(30,20,"T13,D20");}
if (scores==78){
Serial.println("T18,D12");
RSCG12864B.print_string_12_xy(30,20,"T18,D12");}
if (scores==77){
Serial.println("T19,D10");
RSCG12864B.print_string_12_xy(30,20,"T19,D10");}
if (scores==76){
Serial.println("T20,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,D8");}
if (scores==75){
Serial.println("T17,D12");
RSCG12864B.print_string_12_xy(30,20,"T17,D12");}
if (scores==74){
Serial.println("T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T14,D16");}
if (scores==73){
Serial.println("T19,D8");
RSCG12864B.print_string_12_xy(30,20,"T19,D8");}
if (scores==72){
Serial.println("T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T16,D12");}
if (scores==71){
Serial.println("T13,D16");
RSCG12864B.print_string_12_xy(30,20,"T13,D16");}
if (scores==70){
Serial.println("T18,D8");
RSCG12864B.print_string_12_xy(30,20,"T18,D8");}
if (scores==69){
Serial.println("T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T19,D6");}
if (scores==68){
Serial.println("T18,D7");
RSCG12864B.print_string_12_xy(30,20,"T18,D7");}
if (scores==67){
Serial.println("T17,D8");
RSCG12864B.print_string_12_xy(30,20,"T17,D8");}
if (scores==66){
Serial.println("T10,D18");
RSCG12864B.print_string_12_xy(30,20,"T10,D18");}
if (scores==65){
Serial.println("T19,D4");
RSCG12864B.print_string_12_xy(30,20,"T19,D4");}
if (scores==64){
Serial.println("T16,D8");
RSCG12864B.print_string_12_xy(30,20,"T16,D8");}
if (scores==63){
Serial.println("T17,D6");
RSCG12864B.print_string_12_xy(30,20,"T17,D6");}
if (scores==62){
Serial.println("T10,D16");
RSCG12864B.print_string_12_xy(30,20,"T10,D16");}
if (scores==61){
Serial.println("T15,D8");
RSCG12864B.print_string_12_xy(30,20,"T15,D8");}
if (scores==60){
Serial.println("S20,D20");
RSCG12864B.print_string_12_xy(30,20,"S20,D20");}
if (scores==59){
Serial.println("S19,D20");
RSCG12864B.print_string_12_xy(30,20,"S19,D20");}
if (scores==58){
Serial.println("S18,D20");
RSCG12864B.print_string_12_xy(30,20,"S18,D20");}
if (scores==57){
Serial.println("S17,D20");
RSCG12864B.print_string_12_xy(30,20,"S17,D20");}
if (scores==56){
Serial.println("S16,D20");
RSCG12864B.print_string_12_xy(30,20,"S16,D20");}
if (scores==55){
Serial.println("S15,D20");
RSCG12864B.print_string_12_xy(30,20,"S15,D20");}
if (scores==54){
Serial.println("S14,D20");
RSCG12864B.print_string_12_xy(30,20,"S14,D20");}
if (scores==53){
Serial.println("S13,D20");
RSCG12864B.print_string_12_xy(30,20,"S13,D20");}
if (scores==52){
Serial.println("T12,D8");
RSCG12864B.print_string_12_xy(30,20,"T12,D8");}
if (scores==51){
Serial.println("S11,D20");
RSCG12864B.print_string_12_xy(30,20,"S11,D20");}
if (scores==50){
Serial.println("S10,D20");
RSCG12864B.print_string_12_xy(30,20,"S10,D20");}
if (scores==49){
Serial.println("S9,D20");
RSCG12864B.print_string_12_xy(30,20,"S9,D20");}
if (scores==48){
Serial.println("S16,D16");
RSCG12864B.print_string_12_xy(30,20,"S16,D16");}
if (scores==47){
Serial.println("S7,D20");
RSCG12864B.print_string_12_xy(30,20,"S7,D20");}
if (scores==46){
Serial.println("S6,D20");
RSCG12864B.print_string_12_xy(30,20,"S6,D20");}
if (scores==45){
Serial.println("S13,D16");
RSCG12864B.print_string_12_xy(30,20,"S13,D16");}
if (scores==44){
Serial.println("S12,D16");
RSCG12864B.print_string_12_xy(30,20,"S12,D16");}
if (scores==43){
Serial.println("S11,D16");
RSCG12864B.print_string_12_xy(30,20,"S11,D16");}
if (scores==42){
Serial.println("S10,D16");
RSCG12864B.print_string_12_xy(30,20,"S10,D16");}
if (scores==41){
Serial.println("S9,D16");
RSCG12864B.print_string_12_xy(30,20,"S9,D16");}
if (scores==40){
Serial.println("D20");
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==39){
Serial.println("S7,D16");
RSCG12864B.print_string_12_xy(30,20,"S7,D16");}
if (scores==38){
Serial.println("D19");
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==37){
Serial.println("S5,D16");
RSCG12864B.print_string_12_xy(30,20,"S5,D16");}
if (scores==36){
Serial.println("D18");
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==35){
Serial.println("S3,D16");
RSCG12864B.print_string_12_xy(30,20,"S3,D16");}
if (scores==34){
Serial.println("D17");
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==33){
Serial.println("S17,D8");
RSCG12864B.print_string_12_xy(30,20,"S17,D8");}
if (scores==32) {
Serial.println("D16");
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==31){
Serial.println("S15,D8");
RSCG12864B.print_string_12_xy(30,20,"S15,D8");}
if (scores==30){
Serial.println("D15");
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==29){
Serial.println("S13,D8");
RSCG12864B.print_string_12_xy(30,20,"S13,D8");}
if (scores==28){
Serial.println("D14");
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==27){
Serial.println("S19,D4");
RSCG12864B.print_string_12_xy(30,20,"S19,D4");}
if (scores==26){
Serial.println("D13");
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==25){
Serial.println("S17,D4");
RSCG12864B.print_string_12_xy(30,20,"S17,D4");}
if (scores==24){
Serial.println("D12");
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==23){
Serial.println("S7,D8");
RSCG12864B.print_string_12_xy(30,20,"S7,D8");}
if (scores==22){
Serial.println("D11");
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==21){
Serial.println("S5,D8");
RSCG12864B.print_string_12_xy(30,20,"S5,D8");}
if (scores==20){
Serial.println("D10");
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==19){
Serial.println("S11,D4");
RSCG12864B.print_string_12_xy(30,20,"S11,D4");}
if (scores==18){
Serial.println("D9");
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==17){
Serial.println("S9,D4");
RSCG12864B.print_string_12_xy(30,20,"S9,D4");}
if (scores==16){
Serial.println("D8");
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==15){
Serial.println("S7,D4");
RSCG12864B.print_string_12_xy(30,20,"S7,D4");}
if (scores==14){
Serial.println("D7");
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==13){
Serial.println("S5,D4");
RSCG12864B.print_string_12_xy(30,20,"S5,D4");}
if (scores==12){
Serial.println("D6");
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==11){
Serial.println("S3,D4");
RSCG12864B.print_string_12_xy(30,20,"S3,D4");}
if (scores==10){
Serial.println("D5");
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==9){
Serial.println("S1,D4");
RSCG12864B.print_string_12_xy(30,20,"S1,D4");}
if (scores==8){
Serial.println("D4");
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==7){
Serial.println("S3,D2");
RSCG12864B.print_string_12_xy(30,20,"S3,D2");}
if (scores==6){
Serial.println("D3");
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==5){
Serial.println("S1,D2");
RSCG12864B.print_string_12_xy(30,20,"S1,D2");}
if (scores==4){
Serial.println("D2");
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==3){
Serial.println("S1,D1");
RSCG12864B.print_string_12_xy(30,20,"S1,D1");}
if (scores==2){
Serial.println("D1");
RSCG12864B.print_string_12_xy(30,20,"D1");}

    }
    if(times % 3 ==2&&rounds<10){
tipsgiven=1;
  Serial.println(scores);
  RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score      Tips");
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
       if (scores==170){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==169||scores==168||scores==166||scores==165||scores==163||scores==162||scores==159||scores>170){
Serial.println("Have Fun!");
RSCG12864B.print_string_12_xy(30,30,"Have Fun!");
}
if (scores==167){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==164){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==161){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==160){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==158){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==157){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T2,T19");}
if (scores==156){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==155){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==154){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==153){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==152){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==151){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==150){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==149){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==148){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==147){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==146){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==145){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==144){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==143){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==142){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==141){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==140){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==139){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==138){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==137){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==136){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==135){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==134){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==133){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==132){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==131){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==130){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==129){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==128){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==127){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==126){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==125){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==124){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==123){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==122){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==121){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==120){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==119){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==118){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==117){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==116){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==115){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==114){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==113){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==112){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==111){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==110){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==109){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==108){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==107){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==106){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==105){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==104){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==103){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==102){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==101){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==100){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==99){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==98){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==97){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==96){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==95){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==94){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==93){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==92){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==91){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==90){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==89){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==88){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==87){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==86){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==85){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==84){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==83){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==82){
Serial.println("T14");
RSCG12864B.print_string_12_xy(30,20,"T14");}
if (scores==81){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==80){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==79){
Serial.println("T13");
RSCG12864B.print_string_12_xy(30,20,"T13");}
if (scores==78){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==77){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==76){
Serial.println("T20");
RSCG12864B.print_string_12_xy(30,20,"T20");}
if (scores==75){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==74){
Serial.println("T14");
RSCG12864B.print_string_12_xy(30,20,"T14");}
if (scores==73){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==72){
Serial.println("T16");
RSCG12864B.print_string_12_xy(30,20,"T16");}
if (scores==71){
Serial.println("T13");
RSCG12864B.print_string_12_xy(30,20,"T13");}
if (scores==70){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==69){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==68){
Serial.println("T18");
RSCG12864B.print_string_12_xy(30,20,"T18");}
if (scores==67){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==66){
Serial.println("T10");
RSCG12864B.print_string_12_xy(30,20,"T10");}
if (scores==65){
Serial.println("T19");
RSCG12864B.print_string_12_xy(30,20,"T19");}
if (scores==64){
Serial.println("T16");
RSCG12864B.print_string_12_xy(30,20,"T16");}
if (scores==63){
Serial.println("T17");
RSCG12864B.print_string_12_xy(30,20,"T17");}
if (scores==62){
Serial.println("T10");
RSCG12864B.print_string_12_xy(30,20,"T10");}
if (scores==61){
Serial.println("T15");
RSCG12864B.print_string_12_xy(30,20,"T15");}
if (scores==60){
Serial.println("S20");
RSCG12864B.print_string_12_xy(30,20,"S20");}
if (scores==59){
Serial.println("S19");
RSCG12864B.print_string_12_xy(30,20,"S19");}
if (scores==58){
Serial.println("S18");
RSCG12864B.print_string_12_xy(30,20,"S18");}
if (scores==57){
Serial.println("S17");
RSCG12864B.print_string_12_xy(30,20,"S17");}
if (scores==56){
Serial.println("S16");
RSCG12864B.print_string_12_xy(30,20,"S16");}
if (scores==55){
Serial.println("S15");
RSCG12864B.print_string_12_xy(30,20,"S15");}
if (scores==54){
Serial.println("S14");
RSCG12864B.print_string_12_xy(30,20,"S14");}
if (scores==53){
Serial.println("S13");
RSCG12864B.print_string_12_xy(30,20,"S13");}
if (scores==52){
Serial.println("T12");
RSCG12864B.print_string_12_xy(30,20,"T12");}
if (scores==51){
Serial.println("S11");
RSCG12864B.print_string_12_xy(30,20,"S11");}
if (scores==50){
Serial.println("S10");
RSCG12864B.print_string_12_xy(30,20,"S10");}
if (scores==49){
Serial.println("S9");
RSCG12864B.print_string_12_xy(30,20,"S9");}
if (scores==48){
Serial.println("S16");
RSCG12864B.print_string_12_xy(30,20,"S16");}
if (scores==47){
Serial.println("S7");
RSCG12864B.print_string_12_xy(30,20,"S7");}
if (scores==46){
Serial.println("S6");
RSCG12864B.print_string_12_xy(30,20,"S6");}
if (scores==45){
Serial.println("S13");
RSCG12864B.print_string_12_xy(30,20,"S13");}
if (scores==44){
Serial.println("S12");
RSCG12864B.print_string_12_xy(30,20,"S12");}
if (scores==43){
Serial.println("S11");
RSCG12864B.print_string_12_xy(30,20,"S11");}
if (scores==42){
Serial.println("S10");
RSCG12864B.print_string_12_xy(30,20,"S10");}
if (scores==41){
Serial.println("S9");
RSCG12864B.print_string_12_xy(30,20,"S9");}
if (scores==40){
Serial.println("D20");
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==39){
Serial.println("S7");
RSCG12864B.print_string_12_xy(30,20,"S7");}
if (scores==38){
Serial.println("D19");
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==37){
Serial.println("S5");
RSCG12864B.print_string_12_xy(30,20,"S5");}
if (scores==36){
Serial.println("D18");
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==35){
Serial.println("S3");
RSCG12864B.print_string_12_xy(30,20,"S3");}
if (scores==34){
Serial.println("D17");
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==33){
Serial.println("S17");
RSCG12864B.print_string_12_xy(30,20,"S17");}
if (scores==32) {
Serial.println("D16");
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==31){
Serial.println("S15");
RSCG12864B.print_string_12_xy(30,20,"S15");}
if (scores==30){
Serial.println("D15");
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==29){
Serial.println("S13");
RSCG12864B.print_string_12_xy(30,20,"S13");}
if (scores==28){
Serial.println("D14");
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==27){
Serial.println("S19");
RSCG12864B.print_string_12_xy(30,20,"S19");}
if (scores==26){
Serial.println("D13");
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==25){
Serial.println("S17");
RSCG12864B.print_string_12_xy(30,20,"S17");}
if (scores==24){
Serial.println("D12");
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==23){
Serial.println("S7");
RSCG12864B.print_string_12_xy(30,20,"S7");}
if (scores==22){
Serial.println("D11");
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==21){
Serial.println("S5");
RSCG12864B.print_string_12_xy(30,20,"S5");}
if (scores==20){
Serial.println("D10");
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==19){
Serial.println("S11");
RSCG12864B.print_string_12_xy(30,20,"S11");}
if (scores==18){
Serial.println("D9");
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==17){
Serial.println("S9");
RSCG12864B.print_string_12_xy(30,20,"S9");}
if (scores==16){
Serial.println("D8");
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==15){
Serial.println("S7");
RSCG12864B.print_string_12_xy(30,20,"S7");}
if (scores==14){
Serial.println("D7");
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==13){
Serial.println("S5");
RSCG12864B.print_string_12_xy(30,20,"S5");}
if (scores==12){
Serial.println("D6");
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==11){
Serial.println("S3");
RSCG12864B.print_string_12_xy(30,20,"S3");}
if (scores==10){
Serial.println("D5");
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==9){
Serial.println("S1");
RSCG12864B.print_string_12_xy(30,20,"S1");}
if (scores==8){
Serial.println("D4");
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==7){
Serial.println("S3");
RSCG12864B.print_string_12_xy(30,20,"S3");}
if (scores==6){
Serial.println("D3");
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==5){
Serial.println("S1");
RSCG12864B.print_string_12_xy(30,20,"S1");}
if (scores==4){
Serial.println("D2");
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==3){
Serial.println("S1");
RSCG12864B.print_string_12_xy(30,20,"S1");}
if (scores==2){
Serial.println("D1");
RSCG12864B.print_string_12_xy(30,20,"D1");}
    }

  }


  
}
  mode=modeselect.getKey();

if(mode){
        RSCG12864B.clear();
  switch(mode)
{ case '(':
scores= 301 ;
times=0;
tostart301=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
competition=false;
Serial.println("301 game starts");
RSCG12864B.print_string_12_xy(10,20,"New game for 301");

delay(1200);
  break;
  case ')':
scores=501;
times=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
tostart301=1;
competition=false;
Serial.println("501 game starts");
RSCG12864B.print_string_12_xy(10,20,"New game for 501");

  delay(1200);
  break;
  case '-':
  scores=301;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=0;
  tostart301b=0;
  p1=301;
  p2=301;
  Serial.println("301 match starts");
  RSCG12864B.print_string_12_xy(10,20,"New match for 301");

  delay(1200);
  break;
  case '+':
   scores=501;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=1;
  tostart301b=1;
  p1=501;
  p2=501;
    Serial.println("501 match starts");
    RSCG12864B.print_string_12_xy(10,20,"New match for 501");

  delay(1200);
  break;
  case '=':
  break;
}
}

}



while (setgame==1&&rounds<=9&&times<=2 && finish==0&&fail==0){
if(times ==0 &&tipsgiven==0)
{tipsgiven=1;
  Serial.println(scores);
  RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score     Tips");
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
if (scores==170){
Serial.println("T20,T20,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,DB");}
if (scores==169||scores==168||scores==166||scores==165||scores==163||scores==162||scores==159||scores>170){
Serial.println("Have Fun!");
RSCG12864B.print_string_12_xy(30,30,"Have Fun!");
}
if (scores==167){
Serial.println("T20,T19,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,DB");}
if (scores==164){
Serial.println("T19,T19,DB");
RSCG12864B.print_string_12_xy(30,20,"T19,T19,DB");}
if (scores==161){
Serial.println("T20,T17,DB");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,DB");}
if (scores==160){
Serial.println("T20,T20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D20");}
if (scores==158){
Serial.println("T20,T20,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D19");}
if (scores==157){
Serial.println("T20,T19,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D20");}
if (scores==156){
Serial.println("T20,T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D18");}
if (scores==155){
Serial.println("T20,T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D18");}
if (scores==154){
Serial.println("T20,T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D20");}
if (scores==153){
Serial.println("T20,T19,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D18");}
if (scores==152){
Serial.println("T20,T20,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D16");}
if (scores==151){
Serial.println("T20,T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D20");}
if (scores==150){
Serial.println("T20,T18,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D19");}
if (scores==149){
Serial.println("T20,T19,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D16");}
if (scores==148){
Serial.println("T20,T20,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D14");}
if (scores==147){
Serial.println("T20,T17,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D18");}
if (scores==146){
Serial.println("T20,T18,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D16");}
if (scores==145){
Serial.println("T20,T19,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D14");}
if (scores==144){
Serial.println("T20,T20,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D12");}
if (scores==143){
Serial.println("T20,T17,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D16");}
if (scores==142){
Serial.println("T20,T14,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D12");}
if (scores==141){
Serial.println("T20,T19,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D12");}
if (scores==140){
Serial.println("T20,T20,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D10");}
if (scores==139){
Serial.println("T20,T13,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,T13,D20");}
if (scores==138){
Serial.println("T20,T18,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T18,D12");}
if (scores==137){
Serial.println("T20,T19,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D10");}
if (scores==136){
Serial.println("T20,T20,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D8");}
if (scores==135){
Serial.println("T20,T17,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D12");}
if (scores==134){
Serial.println("T20,T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D16");}
if (scores==133){
Serial.println("T20,T19,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T19,D8");}
if (scores==132){
Serial.println("T20,T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,T16,D12");}
if (scores==131){
Serial.println("T20,T13,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,T13,D16");}
if (scores==130){
Serial.println("T20,T20,D5");
RSCG12864B.print_string_12_xy(30,20,"T20,T20,D5");}
if (scores==129){
Serial.println("T19,T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T19,T16,D12");}
if (scores==128){
Serial.println("T18,T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T18,T14,D16");}
if (scores==127){
Serial.println("T20,T17,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,T17,D8");}
if (scores==126){
Serial.println("T19,T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T19,T19,D6");}
if (scores==125){
Serial.println("T18,T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T18,T19,D6");}
if (scores==124){
Serial.println("T20,T14,D11");
RSCG12864B.print_string_12_xy(30,20,"T20,T14,D11");}
if (scores==123){
Serial.println("T19,T16,D9");
RSCG12864B.print_string_12_xy(30,20,"T19,T16,D9");}
if (scores==122){
Serial.println("T18,T18,D7");
RSCG12864B.print_string_12_xy(30,20,"T18,T18,D7");}
if (scores==121){
Serial.println("T20,T11,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,T11,D14");}
if (scores==120){
Serial.println("T20,S20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S20,D20");}
if (scores==119){
Serial.println("T19,T12,D13");
RSCG12864B.print_string_12_xy(30,20,"T19,T12,D13");}
if (scores==118){
Serial.println("T20,S18,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S18,D20");}
if (scores==117){
Serial.println("T20,S17,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S17,D20");}
if (scores==116){
Serial.println("T19,S19,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S19,D20");}
if (scores==115){
Serial.println("T19,S18,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S18,D20");}
if (scores==114){
Serial.println("T20,S14,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S14,D20");}
if (scores==113){
Serial.println("T19,S16,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S16,D20");}
if (scores==112){
Serial.println("T20,S12,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,S12,D8");}
if (scores==111){
Serial.println("T20,S11,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S11,D20");}
if (scores==110){
Serial.println("T20,T10,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,T10,D10");}
if (scores==109){
Serial.println("T20,S9,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,S9,D20");}
if (scores==108){
Serial.println("T20,S16,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S16,D16");}
if (scores==107){
Serial.println("T19,T10,D10");
RSCG12864B.print_string_12_xy(30,20,"T19,T10,D10");}
if (scores==106){
Serial.println("T20,S14,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S14,D16");}
if (scores==105){
Serial.println("T20,S13,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S13,D16");}
if (scores==104){
Serial.println("T19,S15,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,S15,D16");}
if (scores==103){
Serial.println("T19,S6,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,S6,D20");}
if (scores==102){
Serial.println("T20,S10,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S10,D16");}
if (scores==101){
Serial.println("T20,S9,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,S9,D16");}
if (scores==100){
Serial.println("T20,D20");
RSCG12864B.print_string_12_xy(30,20,"T20,D20");}
if (scores==99){
Serial.println("T19,S10,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,S10,D16");}
if (scores==98){
Serial.println("T20,D19");
RSCG12864B.print_string_12_xy(30,20,"T20,D19");}
if (scores==97){
Serial.println("T19,D20");
RSCG12864B.print_string_12_xy(30,20,"T19,D20");}
if (scores==96){
Serial.println("T20,D18");
RSCG12864B.print_string_12_xy(30,20,"T20,D18");}
if (scores==95){
Serial.println("T19,D19");
RSCG12864B.print_string_12_xy(30,20,"T19,D19");}
if (scores==94){
Serial.println("T18,D20");
RSCG12864B.print_string_12_xy(30,20,"T18,D20");}
if (scores==93){
Serial.println("T19,D18");
RSCG12864B.print_string_12_xy(30,20,"T19,D18");}
if (scores==92){
Serial.println("T20,D16");
RSCG12864B.print_string_12_xy(30,20,"T20,D16");}
if (scores==91){
Serial.println("T17,D20");
RSCG12864B.print_string_12_xy(30,20,"T17,D20");}
if (scores==90){
Serial.println("T20,D15");
RSCG12864B.print_string_12_xy(30,20,"T20,D15");}
if (scores==89){
Serial.println("T19,D16");
RSCG12864B.print_string_12_xy(30,20,"T19,D16");}
if (scores==88){
Serial.println("T20,D14");
RSCG12864B.print_string_12_xy(30,20,"T20,D14");}
if (scores==87){
Serial.println("T17,D18");
RSCG12864B.print_string_12_xy(30,20,"T17,D18");}
if (scores==86){
Serial.println("T18,D16");
RSCG12864B.print_string_12_xy(30,20,"T18,D16");}
if (scores==85){
Serial.println("T19,D14");
RSCG12864B.print_string_12_xy(30,20,"T19,D14");}
if (scores==84){
Serial.println("T20,D12");
RSCG12864B.print_string_12_xy(30,20,"T20,D12");}
if (scores==83){
Serial.println("T17,D16");
RSCG12864B.print_string_12_xy(30,20,"T17,D16");}
if (scores==82){
Serial.println("T14,D20");
RSCG12864B.print_string_12_xy(30,20,"T14,D20");}
if (scores==81){
Serial.println("T19,D12");
RSCG12864B.print_string_12_xy(30,20,"T19,D12");}
if (scores==80){
Serial.println("T20,D10");
RSCG12864B.print_string_12_xy(30,20,"T20,D10");}
if (scores==79){
Serial.println("T13,D20");
RSCG12864B.print_string_12_xy(30,20,"T13,D20");}
if (scores==78){
Serial.println("T18,D12");
RSCG12864B.print_string_12_xy(30,20,"T18,D12");}
if (scores==77){
Serial.println("T19,D10");
RSCG12864B.print_string_12_xy(30,20,"T19,D10");}
if (scores==76){
Serial.println("T20,D8");
RSCG12864B.print_string_12_xy(30,20,"T20,D8");}
if (scores==75){
Serial.println("T17,D12");
RSCG12864B.print_string_12_xy(30,20,"T17,D12");}
if (scores==74){
Serial.println("T14,D16");
RSCG12864B.print_string_12_xy(30,20,"T14,D16");}
if (scores==73){
Serial.println("T19,D8");
RSCG12864B.print_string_12_xy(30,20,"T19,D8");}
if (scores==72){
Serial.println("T16,D12");
RSCG12864B.print_string_12_xy(30,20,"T16,D12");}
if (scores==71){
Serial.println("T13,D16");
RSCG12864B.print_string_12_xy(30,20,"T13,D16");}
if (scores==70){
Serial.println("T18,D8");
RSCG12864B.print_string_12_xy(30,20,"T18,D8");}
if (scores==69){
Serial.println("T19,D6");
RSCG12864B.print_string_12_xy(30,20,"T19,D6");}
if (scores==68){
Serial.println("T18,D7");
RSCG12864B.print_string_12_xy(30,20,"T18,D7");}
if (scores==67){
Serial.println("T17,D8");
RSCG12864B.print_string_12_xy(30,20,"T17,D8");}
if (scores==66){
Serial.println("T10,D18");
RSCG12864B.print_string_12_xy(30,20,"T10,D18");}
if (scores==65){
Serial.println("T19,D4");
RSCG12864B.print_string_12_xy(30,20,"T19,D4");}
if (scores==64){
Serial.println("T16,D8");
RSCG12864B.print_string_12_xy(30,20,"T16,D8");}
if (scores==63){
Serial.println("T17,D6");
RSCG12864B.print_string_12_xy(30,20,"T17,D6");}
if (scores==62){
Serial.println("T10,D16");
RSCG12864B.print_string_12_xy(30,20,"T10,D16");}
if (scores==61){
Serial.println("T15,D8");
RSCG12864B.print_string_12_xy(30,20,"T15,D8");}
if (scores==60){
Serial.println("S20,D20");
RSCG12864B.print_string_12_xy(30,20,"S20,D20");}
if (scores==59){
Serial.println("S19,D20");
RSCG12864B.print_string_12_xy(30,20,"S19,D20");}
if (scores==58){
Serial.println("S18,D20");
RSCG12864B.print_string_12_xy(30,20,"S18,D20");}
if (scores==57){
Serial.println("S17,D20");
RSCG12864B.print_string_12_xy(30,20,"S17,D20");}
if (scores==56){
Serial.println("S16,D20");
RSCG12864B.print_string_12_xy(30,20,"S16,D20");}
if (scores==55){
Serial.println("S15,D20");
RSCG12864B.print_string_12_xy(30,20,"S15,D20");}
if (scores==54){
Serial.println("S14,D20");
RSCG12864B.print_string_12_xy(30,20,"S14,D20");}
if (scores==53){
Serial.println("S13,D20");
RSCG12864B.print_string_12_xy(30,20,"S13,D20");}
if (scores==52){
Serial.println("T12,D8");
RSCG12864B.print_string_12_xy(30,20,"T12,D8");}
if (scores==51){
Serial.println("S11,D20");
RSCG12864B.print_string_12_xy(30,20,"S11,D20");}
if (scores==50){
Serial.println("S10,D20");
RSCG12864B.print_string_12_xy(30,20,"S10,D20");}
if (scores==49){
Serial.println("S9,D20");
RSCG12864B.print_string_12_xy(30,20,"S9,D20");}
if (scores==48){
Serial.println("S16,D16");
RSCG12864B.print_string_12_xy(30,20,"S16,D16");}
if (scores==47){
Serial.println("S7,D20");
RSCG12864B.print_string_12_xy(30,20,"S7,D20");}
if (scores==46){
Serial.println("S6,D20");
RSCG12864B.print_string_12_xy(30,20,"S6,D20");}
if (scores==45){
Serial.println("S13,D16");
RSCG12864B.print_string_12_xy(30,20,"S13,D16");}
if (scores==44){
Serial.println("S12,D16");
RSCG12864B.print_string_12_xy(30,20,"S12,D16");}
if (scores==43){
Serial.println("S11,D16");
RSCG12864B.print_string_12_xy(30,20,"S11,D16");}
if (scores==42){
Serial.println("S10,D16");
RSCG12864B.print_string_12_xy(30,20,"S10,D16");}
if (scores==41){
Serial.println("S9,D16");
RSCG12864B.print_string_12_xy(30,20,"S9,D16");}
if (scores==40){
Serial.println("D20");
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==39){
Serial.println("S7,D16");
RSCG12864B.print_string_12_xy(30,20,"S7,D16");}
if (scores==38){
Serial.println("D19");
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==37){
Serial.println("S5,D16");
RSCG12864B.print_string_12_xy(30,20,"S5,D16");}
if (scores==36){
Serial.println("D18");
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==35){
Serial.println("S3,D16");
RSCG12864B.print_string_12_xy(30,20,"S3,D16");}
if (scores==34){
Serial.println("D17");
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==33){
Serial.println("S17,D8");
RSCG12864B.print_string_12_xy(30,20,"S17,D8");}
if (scores==32) {
Serial.println("D16");
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==31){
Serial.println("S15,D8");
RSCG12864B.print_string_12_xy(30,20,"S15,D8");}
if (scores==30){
Serial.println("D15");
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==29){
Serial.println("S13,D8");
RSCG12864B.print_string_12_xy(30,20,"S13,D8");}
if (scores==28){
Serial.println("D14");
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==27){
Serial.println("S19,D4");
RSCG12864B.print_string_12_xy(30,20,"S19,D4");}
if (scores==26){
Serial.println("D13");
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==25){
Serial.println("S17,D4");
RSCG12864B.print_string_12_xy(30,20,"S17,D4");}
if (scores==24){
Serial.println("D12");
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==23){
Serial.println("S7,D8");
RSCG12864B.print_string_12_xy(30,20,"S7,D8");}
if (scores==22){
Serial.println("D11");
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==21){
Serial.println("S5,D8");
RSCG12864B.print_string_12_xy(30,20,"S5,D8");}
if (scores==20){
Serial.println("D10");
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==19){
Serial.println("S11,D4");
RSCG12864B.print_string_12_xy(30,20,"S11,D4");}
if (scores==18){
Serial.println("D9");
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==17){
Serial.println("S9,D4");
RSCG12864B.print_string_12_xy(30,20,"S9,D4");}
if (scores==16){
Serial.println("D8");
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==15){
Serial.println("S7,D4");
RSCG12864B.print_string_12_xy(30,20,"S7,D4");}
if (scores==14){
Serial.println("D7");
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==13){
Serial.println("S5,D4");
RSCG12864B.print_string_12_xy(30,20,"S5,D4");}
if (scores==12){
Serial.println("D6");
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==11){
Serial.println("S3,D4");
RSCG12864B.print_string_12_xy(30,20,"S3,D4");}
if (scores==10){
Serial.println("D5");
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==9){
Serial.println("S1,D4");
RSCG12864B.print_string_12_xy(30,20,"S1,D4");}
if (scores==8){
Serial.println("D4");
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==7){
Serial.println("S3,D2");
RSCG12864B.print_string_12_xy(30,20,"S3,D2");}
if (scores==6){
Serial.println("D3");
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==5){
Serial.println("S1,D2");
RSCG12864B.print_string_12_xy(30,20,"S1,D2");}
if (scores==4){
Serial.println("D2");
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==3){
Serial.println("S1,D1");
RSCG12864B.print_string_12_xy(30,20,"S1,D1");}
if (scores==2){
Serial.println("D1");
RSCG12864B.print_string_12_xy(30,20,"D1");}

  
}



char key= filmsensor.getKey();

if (key)//after the test the button should be added
{
  tipsgiven=0;
//start to count when double is hit (only for 301 mode)
if(tostart301==0)
    {
      if(key=='Q'||key=='P'||key=='O'||key=='e'||key=='f'||key=='g'||key=='h'||key=='i'||key=='j'||key=='d'||key=='c'||key=='b'||key=='a'||key=='K'||key=='L'||key=='M'||key=='N'||key=='T'||key=='S'||key=='R'||key=='u')
      {
 
        tostart301=1;
      switch(key){
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case 'u':
scores=scores-50;
break;
      }
      }
    else{
    Serial.println("Hit double areas first!");
  RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Hit double areas first!");
  delay(1000);
    }
    }
else if(tostart301==1){
switch(key){
case 'Q':
scores=scores-34;
break;
case 'P':
scores=scores-4;
break;
case 'O':
scores=scores-30;
break;
case 'e':
scores=scores-20;
break;
case 'f':
scores=scores-12;
break;
case 'g':
scores=scores-26;
break;
case 'h':
scores=scores-8;
break;
case 'i':
scores=scores-36;
break;
case 'j':
scores=scores-2;
break;
case 'd':
scores=scores-40;
break;
case 'c':
scores=scores-10;
break;
case 'b':
scores=scores-24;
break;
case 'a':
scores=scores-18;
break;
case 'K':
scores=scores-28;
break;
case 'L':
scores=scores-22;
break;
case 'M':
scores=scores-16;
break;
case 'N':
scores=scores-32;
break;
case 'T':
scores=scores-14;
break;
case 'S':
scores=scores-38;
break;
case 'R':
scores=scores-6;
break;
case '^':
scores=scores-9;
break;
case '%':
scores=scores-51;
break;
case 'Z':
scores=scores-6;
break;
case 'Y':
scores=scores-45;
break;
case '5':
scores=scores-30;
break;
case '6':
scores=scores-18;
break;
case '7':
scores=scores-39;
break;
case '8':
scores=scores-12;
break;
case '9':
scores=scores-54;
break;
case '0':
scores=scores-3;
break;
case '4':
scores=scores-60;
break;
case '3':
scores=scores-15;
break;
case '2':
scores=scores-36;
break;
case '1':
scores=scores-27;
break;
case 'U':
scores=scores-42;
break;
case 'V':
scores=scores-33;
break;
case 'W':
scores=scores-24;
break;
case 'X':
scores=scores-48;
break;
case '*':
scores=scores-21;
break;
case '&':
scores=scores-57;
break;
case 'v':
scores=scores-25;
break;
case 'u':
scores=scores-50;
break;
case 'n':
scores=scores-20;
break;
case 'D':
scores=scores-16;
break;
case 'I':
scores=scores-19;
break;
case 'm':
scores=scores-5;
break;
case 'l':
scores=scores-12;
break;
case 'k':
scores=scores-9;
break;
case 'A':
scores=scores-14;
break;
case 'B':
scores=scores-11;
break;
case 'C':
scores=scores-8;
break;
case 'J':
scores=scores-7;
break;
case 'F':
scores=scores-2;
break;
case 'E':
scores=scores-15;
break;
case 'o':
scores=scores-10;
break;
case 'p':
scores=scores-6;
break;
case 'q':
scores=scores-13;
break;
case 'r':
scores=scores-4;
break;
case 's':
scores=scores-18;
break;
case 't':
scores=scores-1;
break;
case 'H':
scores=scores-3;
x67kcase 'G':
scores=scores-17;
break;
  
}

}
times=times+1;
if(scores>1){
Serial.println(scores);
  RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score      Tips");
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
}
//if score is 0 and not the double
if(scores==1)
{
  Serial.println("BUST!");
    RSCG12864B.clear();
  RSCG12864B.print_string_16_xy(30,20,"BUST!");
  delay(1000);
  rounds=rounds+1;
  times=0;
  scores=pscore;
  Serial.println(scores);
    RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score       Tips");
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
  delay(1000);
        Serial.println("Next round,move off your darts in 15 seconds");
        delay(1000);
            RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Next round,move off your darts in 15 seconds");
      delay(14000);
      Serial.println("New round starts after 3 seconds");
                  RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(0,20,"New round starts after 3 seconds");
  delay(1500);
}
else if(scores==0)//unfinished
{ 
  if(key!='P'&&key!='Q'&&key!='R'&&key!='S'&&key!='T'&&key!='N'&&key!='M'&&key!='L'&&key!='K'&&key!='a'&&key!='b'&&key!='c'&&key!='d'&&key!='j'&&key!='i'&&key!='h'&&key!='g'&&key!='f'&&key!='e'&&key!='O'&&key!='u')//randomly picked,needed to be rearranged

{
  Serial.println("BUST!");
      RSCG12864B.clear();
  RSCG12864B.print_string_16_xy(30,20,"BUST!");
  delay(1000);
  rounds=rounds+1;
  times=0;
  scores=pscore;  
   Serial.println(scores);
    RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score      Tips");
delay(1000);
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
  delay(1000);
        Serial.println("Next round,move off your darts in 15 seconds");
            RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Next round,move off your darts in 15 seconds");
      delay(1500);
      Serial.println("New round starts after 3 seconds");
                  RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"New round starts after 3 seconds");
  delay(1000);
}
else
{
  Serial.println("finished");
     RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"finished");
  
  finish=1;
  setgame=0;
  delay(3000);
  Serial.println("Push button to start a new game!");
       RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Push button to start a new game!");
delay(1000);
}
}
else if(scores<0){
Serial.println("BUST!");
      RSCG12864B.clear();
  RSCG12864B.print_string_16_xy(30,20,"BUST!");
delay(1000);
scores=pscore;
rounds=rounds+1;
times=0;
   Serial.println(scores);
    RSCG12864B.clear();
RSCG12864B.print_string_16_xy(8,0,"Score      Tips");
delay(1000);
itostr(sc,scores);

  RSCG12864B.print_string_12_xy(8,20,sc);
  delay(1000);
        Serial.println("Next round,move off your darts in 15 seconds");
            RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Next round,move off your darts in 15 seconds");
      delay(1500);
      Serial.println("New round starts after 3 seconds");
                  RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"New round starts after 3 seconds");
delay(1000);
}
 else if(times==3&&scores>0)
  {
    Serial.println("Round Over");
     RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,20,"Round Over");
    delay(1000);
    rounds=rounds+1;
    times=0;
    tipsgiven=0;
    pscore=scores;
    if(rounds<10){
      Serial.println("Next round,move off your darts in 15 seconds");
           RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,0,"Next round,move off your darts in 15 seconds");
      delay(1500);
      Serial.println("New round starts after 3 seconds");
        RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,0,"New round starts after 3 seconds");
    delay(1000);
    }
    else if(rounds==10)
  {
   Serial.println("You didn't finish all the scores. Game failed.");
       RSCG12864B.clear();
  RSCG12864B.print_string_12_xy(8,0,"You didn't finish all the scores. Game failed.");
delay(1000);
rounds=0;
times=0;
fail=1;
tostart301=0;
scores=301; 
setgame=0;
  }
  }

 


}

if(times ==1&&tipsgiven==0)
{ if(scores==110){
Serial.println("T20 DB");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20 DB");}
if(scores==107){
Serial.println("T19 DB");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19 DB");}
if(scores==104){
Serial.println("T18 DB");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18 DB");}
if(scores==101){
Serial.println("T17 DB");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17 DB");}
if (scores==100){
Serial.println("T20,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D20");}
if (scores==98){
Serial.println("T20,D19");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D19");}
if (scores==97){
Serial.println("T19,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D20");}
if (scores==96){
Serial.println("T20,D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D18");}
if (scores==95){
Serial.println("T19,D19");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D19");}
if (scores==94){
Serial.println("T18,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18,D20");}
if (scores==93){
Serial.println("T19,D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D18");}
if (scores==92){
Serial.println("T20,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D16");}
if (scores==91){
Serial.println("T17,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D20");}
if (scores==90){
Serial.println("T20,D15");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D15");}
if (scores==89){
Serial.println("T19,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D16");}
if (scores==88){
Serial.println("T20,D14");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D14");}
if (scores==87){
Serial.println("T17,D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D18");}
if (scores==86){
Serial.println("T18,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18,D16");}
if (scores==85){
Serial.println("T19,D14");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D14");}
if (scores==84){
Serial.println("T20,D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D12");}
if (scores==83){
Serial.println("T17,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D16");}
if (scores==82){
Serial.println("T14,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T14,D20");}
if (scores==81){
Serial.println("T19,D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D12");}
if (scores==80){
Serial.println("T20,D10");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D10");}
if (scores==79){
Serial.println("T13,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T13,D20");}
if (scores==78){
Serial.println("T18,D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18,D12");}
if (scores==77){
Serial.println("T19,D10");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D10");}
if (scores==76){
Serial.println("T20,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T20,D8");}
if (scores==75){
Serial.println("T17,D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D12");}
if (scores==74){
Serial.println("T14,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T14,D16");}
if (scores==73){
Serial.println("T19,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D8");}
if (scores==72){
Serial.println("T16,D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T16,D12");}
if (scores==71){
Serial.println("T13,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T13,D16");}
if (scores==70){
Serial.println("T18,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18,D8");}
if (scores==69){
Serial.println("T19,D6");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D6");}
if (scores==68){
Serial.println("T18,D7");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T18,D7");}
if (scores==67){
Serial.println("T17,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D8");}
if (scores==66){
Serial.println("T10,D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T10,D18");}
if (scores==65){
Serial.println("T19,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T19,D4");}
if (scores==64){
Serial.println("T16,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T16,D8");}
if (scores==63){
Serial.println("T17,D6");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T17,D6");}
if (scores==62){
Serial.println("T10,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T10,D16");}
if (scores==61){
Serial.println("T15,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T15,D8");}
if (scores==60){
Serial.println("S20,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S20,D20");}
if (scores==59){
Serial.println("S19,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S19,D20");}
if (scores==58){
Serial.println("S18,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S18,D20");}
if (scores==57){
Serial.println("S17,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S17,D20");}
if (scores==56){
Serial.println("S16,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S16,D20");}
if (scores==55){
Serial.println("S15,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S15,D20");}
if (scores==54){
Serial.println("S14,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S14,D20");}
if (scores==53){
Serial.println("S13,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S13,D20");}
if (scores==52){
Serial.println("T12,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"T12,D8");}
if (scores==51){
Serial.println("S11,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S11,D20");}
if (scores==50){
Serial.println("S10,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S10,D20");}
if (scores==49){
Serial.println("S9,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S9,D20");}
if (scores==48){
Serial.println("S16,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S16,D16");}
if (scores==47){
Serial.println("S7,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S7,D20");}
if (scores==46){
Serial.println("S6,D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S6,D20");}
if (scores==45){
Serial.println("S13,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S13,D16");}
if (scores==44){
Serial.println("S12,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S12,D16");}
if (scores==43){
Serial.println("S11,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S11,D16");}
if (scores==42){
Serial.println("S10,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S10,D16");}
if (scores==41){
Serial.println("S9,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S9,D16");}
if (scores==40){
Serial.println("D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==39){
Serial.println("S7,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S7,D16");}
if (scores==38){
Serial.println("D19");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==37){
Serial.println("S5,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S5,D16");}
if (scores==36){
Serial.println("D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==35){
Serial.println("S3,D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S3,D16");}
if (scores==34){
Serial.println("D17");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==33){
Serial.println("S17,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S17,D8");}
if (scores==32){
Serial.println("D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==31){
Serial.println("S15,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S15,D8");}
if (scores==30){
Serial.println("D15");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==29){
Serial.println("S13,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S13,D8");}
if (scores==28){
Serial.println("D14");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==27){
Serial.println("S19,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S19,D4");}
if (scores==26){
Serial.println("D13");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==25){
Serial.println("S17,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S17,D4");}
if (scores==24){
Serial.println("D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==23){
Serial.println("S7,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S7,D8");}
if (scores==22){
Serial.println("D11");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==21){
Serial.println("S5,D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S5,D8");}
if (scores==20){
Serial.println("D10");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==19){
Serial.println("S11,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S11,D4");}
if (scores==18){
Serial.println("D9");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==17){
Serial.println("S9,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S9,D4");}
if (scores==16){
Serial.println("D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==15){
Serial.println("S7,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S7,D4");}
if (scores==14){
Serial.println("D7");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==13){
Serial.println("S5,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S5,D4");}
if (scores==12){
Serial.println("D6");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==11){
Serial.println("S3,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S3,D4");}
if (scores==10){
Serial.println("D5");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==9){
Serial.println("S1,D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S1,D4");}
if (scores==8){
Serial.println("D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==7){
Serial.println("S3,D2");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S3,D2");}
if (scores==6){
Serial.println("D3");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==5){
Serial.println("S1,D2");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S1,D2");}
if (scores==4){
Serial.println("D2");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==3){
Serial.println("S1,D1");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"S1,D1");}
if (scores==2){
Serial.println("D1");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D1");}

}
else if(times==2&&tipsgiven==0)
{
if (scores==50){
Serial.println("DB");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"DB");}
if (scores==40){
Serial.println("D20");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D20");}
if (scores==38){
Serial.println("D19");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D19");}
if (scores==36){
Serial.println("D18");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D18");}
if (scores==34){
Serial.println("D17");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D17");}
if (scores==32){
Serial.println("D16");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D16");}
if (scores==30){
Serial.println("D15");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D15");}
if (scores==28){
Serial.println("D14");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D14");}
if (scores==26){
Serial.println("D13");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D13");}
if (scores==24){
Serial.println("D12");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D12");}
if (scores==22){
Serial.println("D11");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D11");}
if (scores==20){
Serial.println("D10");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D10");}
if (scores==18){
Serial.println("D9");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D9");}
if (scores==16){
Serial.println("D8");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D8");}
if (scores==14){
Serial.println("D7");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D7");}
if (scores==12){
Serial.println("D6");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D6");}
if (scores==10){
Serial.println("D5");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D5");}
if (scores==8){
Serial.println("D4");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D4");}
if (scores==6){
Serial.println("D3");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D3");}
if (scores==4){
Serial.println("D2");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D2");}
if (scores==2){
Serial.println("D1");tipsgiven=1;
RSCG12864B.print_string_12_xy(30,20,"D1");}
}

mode=modeselect.getKey();
if(mode){
switch(mode)
{  case '(':
scores= 301 ;
times=0;
tostart301=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
Serial.println("301 game starts!");
 RSCG12864B.clear();
RSCG12864B.print_string_12_xy(10,20,"301 game starts!");
delay(1200);
  break;
  case ')':
scores=501;
times=0;
rounds=0;
finish=0;
fail=0;
setgame=1;
tipsgiven=0;
tostart301=1;
Serial.println("501 game starts!");
 RSCG12864B.clear();
RSCG12864B.print_string_12_xy(10,20,"501 game starts!");
  delay(1200);
  break;
  case '-':
  scores=301;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=0;
  tostart301b=0; 
  p1=301;
  p2=301;
  setgame=0;
  Serial.println("301 match starts!");
   RSCG12864B.clear();
RSCG12864B.print_string_12_xy(10,20,"301 match starts!");
  delay(1200);
  break;
  case '+':
   scores=501;
  times=0;
  rounds=0;
  finish=0;
  competition=true;
  tipsgiven=0;
  tostart301a=1;
  tostart301b=1;
  p1=501;
  p2=501;
  setgame=0;
    Serial.println("501 match starts!");
     RSCG12864B.clear();
RSCG12864B.print_string_12_xy(10,20,"501 match starts!");
  delay(1200);
  break;
    case '=':
  break;
}
}


}

}