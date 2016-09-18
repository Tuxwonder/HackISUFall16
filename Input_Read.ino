const int T1Pin=5;
const int T2Pin=6;
const int T3Pin=7;
const int T4Pin=8;
const int BEAT = 500;  //in milliseconds 500 = 120bpm
unsigned long time;
int points = 0;
int inputs_per_beat = 0;
int current_beat = 0;
int input = 0;



void setup() {
pinMode(T1Pin, INPUT);
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
  current_beat++;
  Serial.println(current_beat);
  Serial.println(input);
  Serial.println();
  inputs_per_beat = 0;
  input = 0;
}
current_beat = (time/BEAT);

}

int computePoints(unsigned long time, int pts){
  int t = time;
  t = t % BEAT;   //finds spot within the beat
  Serial.println(t);
  t = (t/5) - 50;  //Changes range from 0-500 to (-25)-(+25)
  Serial.println(t);
  if(t < 0)
    t = (-1)*t;
  Serial.println(t);
  if(t <= 10)
    t = 0;
  Serial.println(t);
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



