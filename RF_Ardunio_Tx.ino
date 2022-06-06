#include <VirtualWire.h>
char m;

char *data;

void setup() 
{
  pinMode(5,OUTPUT);  //left motors forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(10,OUTPUT);   //right motors forward
pinMode(11,OUTPUT);   //right motors reverse 
Serial.begin(9600);

  vw_set_tx_pin(3);
  vw_setup(2000);
  pinMode (5, LOW);
  pinMode (6, LOW);
  pinMode (10, LOW);
  pinMode (11, LOW); 
}

void loop()
{
   if(Serial.available()){ 
  m = Serial.read();
  Serial.println(m);
}
  if(m == 'F')
  {
    data="f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();   
    digitalWrite(10,HIGH);
      digitalWrite(5,HIGH);
  }
  else if(m =='B')
  {
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    digitalWrite(6,HIGH);
    digitalWrite(11,HIGH);
  }
  
  else if(m == 'L'){
    
    data="l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();      
  digitalWrite(10,HIGH);    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
}
 
else if(m == 'R'){
  
    data="r";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();     //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(5,HIGH);
}

 
else if(m == 'S'){
  
    data="s";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();    //STOP (all motors stop)
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(11,LOW);
}
}
