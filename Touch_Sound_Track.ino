#define _C2  6541
#define _Db2 6930
#define _D2  7342
#define _Eb2 7778
#define _E2  8241
#define _F2  8731
#define _Gb2 9250
#define _G2  9800
#define _Ab2 10383
#define _LA2 11000
#define _Bb2 11654
#define _B2  12347
#define _C3  13081
#define _Db3 13859
#define _D3  14683
#define _Eb3 15556
#define _E3  16481
#define _F3  17461
#define _Gb3 18500
#define _G3  19600
#define _Ab3 20765
#define _LA3 22000
#define _Bb3 23308
#define _B3  24694
#define _C4  26163
#define _Db4 27718
#define _D4  29366
#define _Eb4 31113
#define _E4  32963
#define _F4  34923
#define _Gb4 36999
#define _G4  39200
#define _Ab4 41530
#define _LA4 44000
#define _Bb4 46616
#define _B4  49388
#define _C5  52325
#define _Db5 55437
#define _D5  58733
#define _Eb5 62225
#define _E5  65926
#define _F5  69846
#define _Gb5 73999
#define _G5  78399
#define _Ab5 83061
#define _LA5 88000
#define _Bb5 93233
#define _B5  98777

//Column     THIS WAS   A    TRI  UMPH  IM    MA    KING A    NOTE HERE  HUGE SUC  CESS  ITS   HARD TO    OV   ER   STATEMY   SA    TIS    FAC   TION   A    PER   TURE SCI  ENCE  WE    DO   WHAT  WE   MUST BE    CAUSEWE   CAN   FOR  THE   GOOD OF   ALL   OF   US   EX    CEPT THE  ONES WHO  ARE  DEAD       BUT   THERE NO   SENSECRY  ING  OV   ER   EV   VRY  MIS  TAKE YOU   JUST  KEEP On   TRY   ING   TILL YOU RUN   OUT   OF   CAKE  AND  THE   SCI   ENCE  GETS   DONE  AND  YOU  MAKE  A     NEAT  GUN  FOR  THE  PEO   PLE  WHO  ARE  STILL A     LIVE
int SA_Column[] = {3,   2,    1,   1,   2,    0,    3,    2,   1,   1,   2,    1,   2,   0,    0,    1,   2,    3,   2,   0,   1,    2,   0,     0,   3,      3,   2,    1,   1,   2,    0,    3,   2,    1,   1,   2,    1,   2,   0,    1,   2,    3,   2,   0,    1,   2,   0,    1,   2,   3,   2,   1,   0,         0,    1,    2,   3,   2,   1,   1,   0,   1,   0,   0,   0,   0,    1,    2,   3,    3,    2,   1,   0,   0,   1,    2,   2,    1,   2,    3,    3,    2,     1,    0,   2,   3,    3,    2,    1,   0,   0,   2,    2,   2,   1,   1,    2,    2    };
int SA_Notes[]  = {_G4, _Gb4, _E4, _E4, _Gb4, _LA3, _G4, _Gb4, _E4, _E4, _Gb4, _D4, _E4, _LA3, _LA3, _E4, _Gb4, _G4, _E4, _Db4, _D4, _E4, _LA3, _LA3,  _Gb4,  _G4, _Gb4, _E4, _E4, _Gb4, _LA3, _G4, _Gb4, _E4, _E4, _Gb4, _D4, _E4, _LA3, _E4, _Gb4, _G4, _E4, _Db4, _D4, _E4, _LA3, _D4, _E4, _F4, _E4, _D4, _C4,       _LA3, _Bb3, _C4, _F4, _E4, _D4, _D4, _C4, _D4, _C4, _C4, _C4, _LA3, _Bb3, _C4, _F4,  _G4,  _F4, _E4, _D4, _D4, _E4,  _F4, _F4,  _G4, _LA4, _Bb4, _Bb4, _LA4,  _G4,  _F4, _G4, _LA4, _LA4, _G4,  _F4, _D4, _C4, _D4,  _F4, _F4, _E4, _E4,  _Gb4, _Gb4 };
int SA_Wait[]   = {0,   0,    0,   0,   10,   0,    0,    0,   0,   1,   2,    1,   0,   7,    0,    1,   0,    2,   0,   1,    2,   1,   0,    1,     10,    0,   0,    0 ,  0,   10,   0,    0,   0,    0,   1,   2,    1,   0,   7,    1,   0,    2,   1,   2,    0,   1,   0,    0,   0,   0,   0,   0,   2,         0,    0,    1,   1,   0,   0,   0,   0,   0,   0,   1,   1,   0,    0,    1,   1,    0,    0,   0,   0,   0,   0,    1,   1,    0,   0,    0,    0,    1,     1,    0,   0,   0,    0,    1,    1,   0,   0,   0,    0,    0,   1,   1,    0,    0    };





const int T1Pin=5;
const int T2Pin=6;
const int T3Pin=7;
const int T4Pin=8;
const int BEAT = 250;  //in milliseconds 500 = 120bpm
unsigned long time;
int points = 0;
int inputs_per_beat = 0;
int current_beat = 0;
int input = 0;



void setup() {
pinMode(T1Pin, INPUT);
pinMode(T2Pin, INPUT);
pinMode(T3Pin, INPUT);
pinMode(T4Pin, INPUT);
pinMode(3, OUTPUT);   
pinMode(9, OUTPUT);       
digitalWrite(9,LOW);
pinMode(10, OUTPUT);   
pinMode(11, OUTPUT); 
pinMode(12, OUTPUT);   
pinMode(13, OUTPUT); 
Serial.begin(9600);
}

void loop() { 

  time = millis();

int sensorValue = digitalRead(T1Pin);
if(sensorValue==1)
{
  if(inputs_per_beat == 0) {
    inputs_per_beat++;
    points = computePoints(time, points);
    Serial.println("Input 1");
    input = 1;
  }
} else {
int sensorValue = digitalRead(T2Pin);
if(sensorValue==1)
{
  if(inputs_per_beat == 0) {
    inputs_per_beat++;
    points = computePoints(time, points);
    Serial.println("Input 2");
    input = 2;
  }
} else {
int sensorValue = digitalRead(T3Pin);
if(sensorValue==1)
{
  if(inputs_per_beat == 0) {
    inputs_per_beat++;
    points = computePoints(time, points);
    Serial.println("Input 3");
    input = 3;
  } 
} else {
int sensorValue = digitalRead(T4Pin);
if(sensorValue==1)
{
  if(inputs_per_beat == 0) {
    inputs_per_beat++;
    points = computePoints(time, points);
    Serial.println("Input 4");
    input = 4;
  } 
}
}
}
}





if(update(time, current_beat)==true) {
  digitalWrite((SA_Column[current_beat-9])+10,LOW);
  if(wait>0)
    wait--;
  else{
  tone(8, SA_Notes[current_beat-8]/100, 200);
  digitalWrite((SA_Column[current_beat-8])+10,HIGH);
  wait = SA_Wait[current_beat-8];
  }
  
  
  current_beat++;
  //Serial.println(current_beat);
  //Serial.println(input);
  Serial.println();
  inputs_per_beat = 0;
  input = 0;
}
current_beat = (time/BEAT);

}

int computePoints(unsigned long time, int pts){
  int t = time;
  t = t % BEAT;   //finds spot within the beat
  //Serial.println(t);
  t = (t*10/25) - 50;  //Changes range from 0-250 to (-25)-(+25)
  //Serial.println(t);
  if(t < 0)
    t = (-1)*t;
  //Serial.println(t);
  if(t <= 10)
    t = 0;
  //Serial.println(t);
  pts += (t);  // assigns up to 50 points for pressing in the center
  Serial.print("Points: ");
  Serial.println(pts);
  return pts;
}


bool update(unsigned long t, int current_beat){
  int new_beat = (t / BEAT);
  if(new_beat == current_beat+1)
    return true;
  return false;
}
