#define DELAY 10
int l;
char sRead() {
if(Serial.available()){
   char r = Serial.read();
    delay(DELAY);    
    return r;
  }
  return -2;
}

int lvl(){
  int buff[3];
  buff[0] = sRead();
  buff[1] = sRead();
  buff[2] = sRead();
  if (buff[0] == '1' && buff[1] == '0' && buff[2] == '0'){
    return 100;
  }
  else if ((buff[0] >= '0' && buff[0] <= '9') && (buff[1] >= '0' && buff[1] <= '9')){
    return (buff[0]-48) * 10 + (buff[1]-48);
  }
  else if (buff[0] >= '0' && buff[0] <= '9'){
    return buff[0]-48;
  }
  return -3;
}

void leftForward() {
  l = lvl();
  Serial.println("moving left forward");
  digitalWrite(PINCS,1);
  digitalWrite(PINLr,0);
  digitalWrite(PINLf,1);
  analogWrite(PINPWMl, (int)(((float)l)*255/100));
}

void leftRearward() {
  l = lvl();
  Serial.println("moving left rearward");
  digitalWrite(PINCS,1);
  digitalWrite(PINLf,0);
  digitalWrite(PINLr,1);
  analogWrite(PINPWMl, (int)(((float)l)*255/100));
}

void rightForward() {
  l = lvl();
  Serial.println("moving right forward");
  digitalWrite(PINCS,1);
  digitalWrite(PINRr,0);
  digitalWrite(PINRf,1);
  analogWrite(PINPWMr, (int)(((float)l)*255/100));
}

void rightRearward() {
  l = lvl();
  Serial.println("moving right rearward");
  digitalWrite(PINCS,1);
  digitalWrite(PINRf,0);
  digitalWrite(PINRr,1);
  analogWrite(PINPWMr, (int)(((float)l)*255/100));

}

void stopAll() {
  Serial.println("stopping");
  digitalWrite(PINCS,0);
  digitalWrite(PINLr,0);
  digitalWrite(PINLf,0);
  digitalWrite(PINRf,0);
  digitalWrite(PINRr,0);
}