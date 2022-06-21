//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int points[3][2] = {{1,1}, {4,2}, {2,0}}; // Start on point 1,1 and first drive to 3,3 and from there, drive to 5,2.

int startX = points[0][0];
int startY = points[0][1];
int x = points[1][0];
int y = points[1][1];
int x1 = points[2][0];
int y1 = points[2][1];


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        
        //left motor
#define enableA 5
#define motorPinA1 7
#define motorPinA2 6

        //right motor
#define enableB 10
#define motorPinB1 9
#define motorPinB2 8

        //line sensors
#define sensorPinLeft 2
#define sensorPinRight 4

        //variables for line detection
#define black HIGH
#define white LOW

#define Up 0
#define Right 1
#define Down 2
#define Left 3


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int direction = Up; //Starting direction is 'Up'
/* Direction codes       0 - Up, 1 - Right, 2 - Down, 3 - Left*/

int sensorValueLeft, sensorValueRight;

int turned = 0;         //keeps track of if we turned or not in the current direction

 
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


void setup(){
  
        // Set motor pints as outputs
 pinMode(enableA, OUTPUT);
 pinMode(enableB, OUTPUT);
 pinMode(motorPinA1, OUTPUT);
 pinMode(motorPinA2, OUTPUT);
 pinMode(motorPinB1, OUTPUT);
 pinMode(motorPinB2, OUTPUT);

        // Set line sensor pins as inputs
 pinMode(sensorPinLeft,INPUT);
 pinMode(sensorPinRight,INPUT);
  Serial.begin(9600);
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void loop(){

  goTo(x,y);
  goTo(x1,y1);
  exit(0);
 
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void goTo(int x, int y){
  do{
  
  while(startX < x){                                                           //moving up
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(direction == Up){                                                       //pointed up
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startX++;
        delay(150);
      }
    }
    if(direction == Right){                                                    //pointed right
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
       direction = Up;
       startX++; 
       turned = 0;
       delay(150);
      }
    }
    if(direction == Down){                                                      //pointed down
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Right;
        startY++; 
        delay(150);
        turned = 0;
      }
    }
    if(direction == Left){                                                      //pointed left
      if(turned == 0){
        turnRight();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Up;
        startX++; 
        delay(150);
        turned = 0;
      }
    }
  }

  while(startX > x){                                                            //moving down
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(direction == Up){                                                        //pointed up
      if(turned == 0){
        turnRight();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Right;
        startY++;
        delay(150);
        turned = 0;
      }
    }
    if(direction == Right){                                                     //pointed right
      if(turned == 0){
        turnRight();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Down;
        startX--; 
        delay(150);
        turned = 0;
      }
    }
    if(direction == Down){                                                      //pointed down
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startX--; 
        delay(150);
      }
    }
    if(direction == Left){                                                      //pointed left
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Down;
        startX--; 
        delay(150);
        turned = 1;
      }
    }
  }

  while(startX == x && startY < y){                                             //moving right
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(direction == Up){                                                        //pointed up
      if(turned == 0){
        turnRight();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startY++; 
        delay(150);
        direction = Right;
        turned = 0;
      }
    }
    if(direction == Right){                                                     //pointed right
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startY++; 
        delay(150);
      }
    }
    if(direction == Down){                                                      //pointed down
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        direction = Right;
        startY++;
    delay(150);
        turned = 0;
    }
    }
    if(direction == Left){                                                      //pointed left
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startX--;
        direction = Down;
        delay(150);
        turned = 0;
      }
    }
  }

  while(startX == x && startY > y){                                             //moving left
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(direction == Up){                                                        //pointed up
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startY--; 
        direction = Left;
        delay(150);
        turned = 0;
      }
    }
    if(direction == Right){                                                      //pointed right
      if(turned == 0){
        turnLeft();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startX++; 
        delay(150);
        direction = Up;
        turned = 0;
      }
    }
    if(direction == Down){                                                       //pointed down
      if(turned == 0){
        turnRight();
        turned = 1;
      }
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startY--; 
        delay(150);
        direction = Left;
        turned = 1;
      }
    }
    if(direction == Left){                                                       //pointed left
      followLine();
      if(sensorValueLeft == white && sensorValueRight == white){
        startY--; 
        delay(150);
      }
    }
  }
  
  }while(startX != x && startY != y);                                       //At desired coordinates
    
  vehicleStop();                                                            //We stop the car for 2 seconds
  delay(2000);
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void followLine(){
     sensorValueLeft = digitalRead(sensorPinLeft);
     sensorValueRight = digitalRead(sensorPinRight);
    
    if(sensorValueLeft == black && sensorValueRight == white){
      Serial.println("adjusting right");
      rightSlow();
    } 
    
    else if(sensorValueLeft == white && sensorValueRight == black){
      Serial.println("adjusting left");
      leftSlow();
    } 
    
    else if(sensorValueLeft == black && sensorValueRight == black){
      Serial.println("going forward");
      forward();
    }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int forward(){
  analogWrite(enableA, 140);
  analogWrite(enableB, 110);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
}

int vehicleStop(){
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}

int leftSlow(){
  analogWrite(enableA, 0);
  analogWrite(enableB, 80);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
}

int rightSlow(){
  analogWrite(enableA, 110);
  analogWrite(enableB, 0);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
}

int turnLeft(){
  vehicleStop();
  delay(500);
  analogWrite(enableA, 180);
  analogWrite(enableB, 120);
  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
  delay(565);
  vehicleStop();
  delay(200);
}

int turnRight(){
  vehicleStop();
  delay(500);
  analogWrite(enableA, 180);
  analogWrite(enableB, 120);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
  delay(565);
  vehicleStop();
  delay(200);
}
