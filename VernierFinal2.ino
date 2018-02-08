/*
  Random Number Generator via Nuclear Decay
  
  Turns on an LED to signify operation on pin 13.
  Digital read pin 2
  Serial output to computer
  
  Created: December 1, 2016
  by Anthony Kunkel
  
  Last modified: Feb 6, 2017
  by Anthony Kunkel 
*/
                          // name the digital pins
  const int led = 13;
  const int GM = 2;
                          // create global variables
  const char on = HIGH;
  const char off = LOW;
  const int bytelength = 8;
  
  char input = HIGH;
  unsigned long int t1 = 0;
  unsigned long int t2 = 0;
  unsigned long int t3 = 0;
  unsigned long int t4 = 0;
  unsigned long int dt1 = 0;
  unsigned long int dt2 = 0;
 
                          // the setup function runs once when you press reset or power the board
void setup() {
     // initialize digital pins as output.

  
  
  pinMode(led, OUTPUT);
  pinMode(GM, INPUT);
                          // initialize the serial port and transmit as fast as possible
  Serial.begin(115200);
  while(!Serial){
  }
}

void loop() {
  //blink_led();            //show operation is working
  int i = 1;
  while(i <= 30){         
    generate();
    
    Serial.flush();
    i++;
  }
}

/*void blink_led(){
  digitalWrite(led, on);
  delay(10);
  digitalWrite(led, off);
}*/

void generate(){
  int n = 1;
  while(n <= 30){    //generate bit
    readinput();
    t1 = micros();
    readinput();
    t2 = micros();
    readinput();
    t3 = micros();
    readinput();
    t4 = micros();
    compare(t1, t2, t3, t4);    //print bit
    n++;
  }
}

void readinput() {         //read the GM tube and exit when a new count is read
  input = digitalRead(GM);  //read the GM tube
  while(input == HIGH){    //if GM tube is high, read the pin until low
    input = digitalRead(GM);
  }
  while(input == LOW){     //while GM tube is low, read the pin until high
    input = digitalRead(GM);
  }
}

void compare(unsigned long int t1, unsigned long int t2, unsigned long int t3, unsigned long int t4){
  dt1 = (t2 - t1);
  dt2 = (t4 - t3);

    Serial.println(dt1);
 
    Serial.println(dt2);




}
