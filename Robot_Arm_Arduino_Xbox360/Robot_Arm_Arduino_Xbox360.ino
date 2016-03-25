#include <Servo.h>


Servo servo1;       //wrist
Servo servo2;       //hand
Servo servo3;       //shoulder
Servo servo4;       //elbow
Servo servo5;       //bottom

//define initial positions of servos
const int init1 = 90;
const int init2 = 0;
const int init3 = 90;
const int init4 = 90;
const int init5 = 90;

//define the increment in degrees. This is what we will use to move the servos
int inc = 1;

//define the delay between each iteration of movement. I will call it speed_ for simplicity
int speed_ = 10;

//define the initial postions of the servos
int pos1 = init1;
int pos2 = init2;
int pos3 = init3;
int pos4 = init4;
int pos5 = init5;

//power on/off (optional)
int powerPin = 9;


void setup() {

//power button (optional)
digitalWrite(powerPin,HIGH);


Serial.begin(9600);

//attaching servos to pins of arduino
servo1.attach(12);
servo2.attach(10);
servo3.attach(6);
servo4.attach(5);
servo5.attach(3);

//begin at initial positions
servo1.write(pos1);
servo2.write(pos2);
servo3.write(pos3);
servo4.write(pos4);
servo5.write(pos5);

//(optional) power again
pinMode(powerPin, OUTPUT);

}

void loop() {
  
//possibly not needed?  
Serial.flush();

//val is the variable we store the received data in
int val = Serial.read();

//condtional needed for loops to work properly
int i = 1;


//--------------------------------MOVE servo5 METHOD-----------------------------------------
while(val=='w' && i==1){
  val = Serial.read(); 

   //limitations that I put in so I can't break the servo cords
  if(pos5 <= 180){

    //increment position to move servo
  pos5=pos5+inc;
  servo5.write(pos5);

  //used to break out of the loop and move different servo or do nothing
  if(val!='w'){
    i=0;
  }
  delay(speed_);
  }
  }
while(val=='q' && i==1){
  val = Serial.read();
  if(pos5 >= 30){
  pos5=pos5-inc;
  servo5.write(pos5);
  if(val!='q'){
    i=0;
  }
  delay(speed_);
  }
  } 

//--------------------------------MOVE servo3 METHOD-----------------------------------------   
while(val=='a' && i==1){
  val = Serial.read();
  if(pos3 >= 35){
  pos3=pos3-inc;
  servo3.write(pos3);
  if(val!='a'){
    i=0;
  }
  delay(speed_);
  }
}
while(val=='s' && i==1){
  val = Serial.read();
  if(pos3 <= 180){
  pos3=pos3+inc;
  servo3.write(pos3);
  if(val!='s'){
    i=0;
  }
  delay(speed_);
  }
}

//--------------------------------MOVE servo4 METHOD-----------------------------------------  
  while(val=='x' && i==1){
  val = Serial.read();
  if(pos4 <= 115){
  pos4=pos4+inc;
  servo4.write(pos4);
  if(val!='x'){
    i=0;
  }
  delay(speed_);
  }
  }
  while(val=='t' && i==1){
  val = Serial.read();
  if(pos4 >= 45){
  pos4=pos4-inc;
  servo4.write(pos4);
  if(val!='t'){
    i=0;
  }
  delay(speed_);
  }
  }

//--------------------------------MOVE servo1 METHOD-----------------------------------------  
  while(val=='r' && i==1){
  val = Serial.read();
  if(pos1 <= 180){
  pos1=pos1+inc;
  servo1.write(pos1);
  if(val!='r'){
    i=0;
  }
  delay(speed_);
  }
  }
  while(val=='e' && i==1){
  val = Serial.read();
  if(pos1 >= 10){
  pos1=pos1-inc;
  servo1.write(pos1);
  if(val!='e'){
    i=0;
  }
  delay(speed_);
  }
}

//--------------------------------MOVE servo2 METHOD-----------------------------------------  
  while(val=='y' && i==1){
  val = Serial.read();
  if(pos2 <= 90){
  pos2=pos2+inc;
  servo2.write(pos2);
  }
  if(val!='y'){
    i=0;
  }
  delay(speed_);
  }
  while(val=='d' && i==1){
  val = Serial.read();
  if(pos2 >= 0){
  pos2=pos2-inc;
  servo2.write(pos2);
  }
  if(val!='d'){
    i=0;
  }
  delay(speed_);
  }


  //---------------------------------change speed of arm method------------------------
  if(val=='n' && i==1){
    val = Serial.read();
    if(inc < 5 && inc >= 1){

      //changing the increment size changes the speed essentially
      inc = inc - 1;
      i=0;
    }
    if(inc == 5){
      inc = inc - 1;
      i = 0;
    }
  }
  if(val=='m' && i==1){
    val = Serial.read();
    if(inc < 5 && inc >= 1){
      inc = inc + 1;
      i=0;
    }
    if(inc == 0){
      inc = 1;
      i=0;
    }
  } 

   
//-------------------------------------------RESET METHOD-----------------------------------  
if(val=='z'){
  //variables used to break loops
  int i1=1;
  int i2=1;
  int i3=1;
  int i4=1;
  int i5=1;
  
//*********************reset servo5***************    
  if(pos5 < init5){
    while(i5==1){
     pos5 = pos5 + 1;
     servo5.write(pos5);
     delay(20);
     if(pos5 >= init5){
       i5=0;
     }
    }
  }
  if(pos5 > init5){
    while(i5==1){
     pos5 = pos5 - 1;
     servo5.write(pos5);
     delay(20);
     if(pos5 <= init5){
      i5=0;
     }
    }
  }

//******************reset servo3**************
  if(pos3 < init3){
    while(i3==1){
     pos3 = pos3 + 1;
     servo3.write(pos3);
     delay(20);
     if(pos3 >= init3){
      i3=0;
     }
    }
  }
    if(pos3 > init3){
    while(i3==1){
     pos3 = pos3 - 1;
     servo3.write(pos3);
     delay(20);
     if(pos3 <= init3){
      i3=0;
     }
    }
  }
  
//***************reset servo4***************
    if(pos4 < init4){
    while(i4==1){
     pos4 = pos4 + 1;
     servo4.write(pos4);
     delay(20);
     if(pos4 >= init4){
      i4=0;
     }
    }
  }
    if(pos4 > init4){
    while(i4==1){
     pos4 = pos4 - 1;
     servo4.write(pos4);
     delay(20);
     if(pos4 <= init4){
      i4=0;
     }
    }
  }

//***************reset servo1***************
 if(pos1 != init1){
  pos1 = init1;
  servo1.write(pos1); 
} 
//***************reset servo2***************
if(pos2 != init2){
  pos2 = init2;
  servo2.write(pos2); 
}
 
    
}
//---------------------------------END RESET METHOD---------------------------------

//-----------------------------------POWER ON/OFF---------------------------------
if(val=='g'){
  digitalWrite(powerPin,LOW);
}
if(val=='j'){
  digitalWrite(powerPin,HIGH);
}


}

