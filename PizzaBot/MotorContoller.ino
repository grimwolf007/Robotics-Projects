#define PINCS       6 //enable
#define PINLr       4 //both left to rear
#define PINLf       5 //both left to front
#define PINRf       7 //both right to front
#define PINRr       8 //both right to rear
#define PINPWMl     9
#define PINPWMr     10
char buff[2];

void setup() {
  Serial.begin(9600);
  pinMode(PINCS,OUTPUT);
  pinMode(PINLr,OUTPUT);
  pinMode(PINLf,OUTPUT);
  pinMode(PINRf,OUTPUT);
  pinMode(PINRr,OUTPUT);

  Serial.println("Commands: ");
  Serial.println("rf[1-100]: Move right wheels forward with throttle 1-100. ");
  Serial.println("rr[1-100]: Move right wheels rearward with throttle 1-100. ");
  Serial.println("lf[1-100]: Move left wheels forward with throttle 1-100. ");
  Serial.println("lr[1-100]: Move left wheels rearward with throttle 1-100. ");
  Serial.println("ss: Stop all ");
}

void loop() {
  buff[0] = sRead();
  if (buff[0] == 'l' || buff[0] == 'r' || buff[0] == 's'){
    buff[1] = sRead();
  }
  if (buff[0]=='l' && buff[1]=='f'){
    leftForward();
  }
  if (buff[0] =='l'){
    if (buff[1] =='r'){
      leftRearward();
    }
  }
  if (buff[0] =='r'){
    if (buff[1] =='f'){
      rightForward();
    }
  }
  if (buff[0] =='r'){
    if (buff[1] =='r'){
      rightRearward();
    }
  }
  if (buff[0] =='s'){
    if (buff[1] =='s'){
      stopAll();
    }
  }
}