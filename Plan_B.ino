#include <Adafruit_NeoPixel.h>

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

#define NUM_LEDS 150
#define BRIGHTNESS 50
#define PIXEL_OFFSET 2
#define FREQUENCY 3
#define TRAIL_LENGTH 6
#define SONG_LENGTH sizeof SA_Column / sizeof *SA_Column
#define BEAT_LENGTH 250
#define MAX_POINTS 50

#define S_PIN 10
#define T1_PIN 5
#define T2_PIN 6
#define T3_PIN 7
#define T4_PIN 8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, S_PIN, NEO_GRB + NEO_KHZ800);

uint32_t NONE = strip.Color(0, 0, 0);

uint32_t FRET_COLORS[][6] = {
  {   //RED
  strip.Color(255,  0,    0),
  strip.Color(128,  0,    0),
  strip.Color(64,   0,    0),
  strip.Color(32,   0,    0),
  strip.Color(16,   0,    0),
  strip.Color(0,    0,    0)},
  {   //YELLOW
  strip.Color(255,  255,  0),
  strip.Color(128,  128,  0),
  strip.Color(64,   64,   0),
  strip.Color(32,   32,   0),
  strip.Color(16,   16,   0),
  strip.Color(0,    0,    0)},
  {   //GREEN
  strip.Color(0,    255,  0),
  strip.Color(0,    128,  0),
  strip.Color(0,    64,   0),
  strip.Color(0,    32,   0),
  strip.Color(0,    16 ,  0),
  strip.Color(0,    0,    0)},
  {   //BLUE
  strip.Color(0,    0,    255),
  strip.Color(0,    0,    128),
  strip.Color(0,    0,    64),
  strip.Color(0,    0,    32),
  strip.Color(0,    0,    16),
  strip.Color(0,    0,    0)}};

unsigned long time;
int touchInput = -1;
int beat = 0; //how many beats till we play the next note
int note = 0; //what note we are on
int trail = 0; //To have a trail behind notes
int points = 0; //How many points the player has received
int fretBoard[4][19] = {{0}};
int inputs[4];

int beat = 0;
int nextBeat = 0;


  //                              //
 /////////// HERE WE GO ///////////
//                              //


void setup() {    
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  
  int i;
  for(i = 0; i < 4; i++)
    addPixel(i, 3, strip.Color(120, 120, 120));
  strip.show(); // Initialize all pixels to 'off'

  pinMode(T1_PIN, INPUT);
  pinMode(8, OUTPUT);   
  pinMode(9, OUTPUT);       
  digitalWrite(9,LOW);
  
  delay(2000);
  time = millis();
  beat = floor(time/250);
  nextBeat = beat + 1;
}

void loop() {

  time = millis();

  //grabInputs();

  if(beat < floor(time/250)) //If the time has moved to the next beat
  {
    beat = floor(time/250);
    if(note < SONG_LENGTH && beat >= nextBeat)
    addNotes();
    displayNotes();
    cycleNotes();
  }
  else
    beat = floor(time/250);
}


  //                                  //
 /////////// HELPER METHODS ///////////
//                                  //


void addPixel(int column, int row, uint32_t color){
  strip.setPixelColor(PIXEL_OFFSET + 8*row + column, color);
}

void displayNotes() {

  //DRAW NOTES
  int col, row, i;
  for(col = 0; col < 4; col++){
    for(row = 0; row < 19; row++){
      if(fretBoard[col][row] > 0){
        addPixel(col, row, FRET_COLORS[col][0]);
        if(trail == 1)
          for(i = 1; i < TRAIL_LENGTH; i++)
            if(row + i < 19)
              addPixel(col, row+i, FRET_COLORS[col][i]);

        if(row == 3)
          tone(8, fretBoard[col][row]/100, 200);
      }
      else
        addPixel(col, row, NONE);
    }
  }

  for(i = 0; i < 4; i++)
    addPixel(i, 3, strip.Color(120, 120, 120));
    
  strip.show();
}

void addNotes() {
  fretBoard[SA_Column[note]][18] = SA_Notes[note];
  beat = (SA_Wait[note]+1)*5;
  note++;
}

void cycleNotes() {
  int col, row;
  for(col = 0; col < 4; col++)
    for(row = 0; row < 19; row++){
      if(fretBoard[col][row] > 0){
        if(row > 0)
          fretBoard[col][row - 1] = fretBoard[col][row];
        fretBoard[col][row] = 0;
      }
    }
}

void addPoints(){
/*  int t = time;
  t = t % BEAT;   //finds spot within the beat
  t = (t/5) - 50;  //Changes range from 0-500 to (-25)-(+25)
  if(t < 0)
    t = (-1)*t;
  if(t <= 10)
    t = 0;
  pts += (t);  // assigns up to 50 points for pressing in the center
  return pts;*/
}

void grabInputs(){
  int i;
  inputs[0] = digitalRead(T1_PIN);
  inputs[1] = digitalRead(T2_PIN);
  inputs[2] = digitalRead(T3_PIN);
  inputs[3] = digitalRead(T4_PIN);
    
  if(touchInput >= 0)
    if(inputs[touchInput] == 0)
      touchInput = -1;

  if(touchInput == -1)
    for(i = 0; i < 4; i++)
      if(inputs[i] == 1){
        touchInput = i;
        addPoints();
      }
}



