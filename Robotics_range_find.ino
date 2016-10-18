int pin=7; // pin the device is connected to.
// todo: no globals
double oldDistance;
int super_flytime;

// not working... just says 0.02
double velocity(double newDistance,int timediff) 
{
  double deltaP=newDistance-oldDistance;
  deltaP=deltaP/timediff;
  double oldDistance=newDistance;

  return deltaP;
}

int takeReading()
{
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  delayMicroseconds(2);
  digitalWrite(pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin,INPUT);
  int flyTime= pulseIn(pin, HIGH);

  super_flytime=flyTime;
 
  return flyTime;
  
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // clear the line and then send a ping.

  double distance=takeReading()/29/2;
 
  Serial.println(distance);

}
