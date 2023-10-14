#include <ESP32Servo.h>
  
int pos;
  
int LDR_pin = 32;
int servo_pin = 13;
int curAng = 90;
int intensity = 0;
int intensity_thes = 0;
int diff;
int score = 0;
int StopScore = 3;

  
int Delay;
 

Servo Target;

void setup()
{
  Serial.begin(115200);
 
  Target.attach(servo_pin);
  Target.write(90);
 
  intensity_thes = analogRead(LDR_pin);
   Serial.print("intensity_thes=");
   Serial.println(intensity_thes);
   startGame();
}

void loop()
{  
   if (Serial.available() > 0)  ReadInput();
   intensity = analogRead(LDR_pin);
   diff =(intensity - intensity_thes) ;
  if(diff > 100 && score == StopScore) startGame();
  
 if (score < StopScore ) {
            
                if(diff > 100){
              
                  Shooted();
                }else{
                 
                }
          
                if (StopScore == score)  { 
                    SetTargetDown(90,10,50,5);
                    Serial.print("Finish Game at : ");
                    Serial.println(StopScore);
                }
           
          }

        delay(300);
 }
/// ----------------------
void startGame() {
  score = 0;
  intensity_thes = analogRead(LDR_pin);
   Serial.println("=============  Start Game -----------------");
   Serial.println("=============             -----------------");
   Target.write(90);
}
void ReadInput() {
  char inChar = Serial.read();
   // Keyboard.write(inChar + 1);
    Serial.print("inChar =");
    Serial.println( inChar );

    if ( inChar == 'S')  startGame();
      if ( inChar == 'T')  startGame();  Shooted();
}
void Shooted() {
   score +=1;
  Serial.print("Shooted Score : ");
   Serial.print(score); 
  Serial.print("  ----  intensity = ");
  Serial.print(intensity);

  Serial.print("   diff = ");
  Serial.println(diff);
 
  Target.write(20);
 //SetTargetDown(90,20,50,5);
  delay(300);
  //Target.write(90);
  SetTargetUp(20,90,50,5);
 
}

void SetTargetDown(int fromAng,int toAng,int delaytime  ,int step  ) {
  //   fromAng 90 toAng 20
   for(pos = fromAng; pos>=toAng; pos-=step) {    // goes from 180 degrees to 0 degrees                                 
       Target.write(pos); 
       delay(delaytime);
  }
}

void SetTargetUp(int fromAng,int toAng,int delaytime ,int step  ) {
   for(pos = fromAng; pos<=toAng; pos+=step) {    // goes from 180 degrees to 0 degrees                                 
       Target.write(pos); 
       delay(delaytime);
    
  }
}
