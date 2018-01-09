/* Working Pong Ball bouncing off Walls.
   Leaves 1 Space at top and bottom for Ship


-- Cosmetics to do:

    - Ships don't move when Ball is not coming
    - Increasing Speed
    - Kometenschweif auf Ball
*/

#include <Charliplexing.h>
#include <Figure.h>
#include <Font.h>

int8_t ballx = 0;
int8_t bally = 0;
int8_t dx = 1;
int8_t dy = 1;
int8_t sp1y = 0;
int8_t sp2y = 8;

int8_t lastballx; //To save last Ball X position
int8_t lastbally; //To save last Ball Y position

// bally = random(9);

void setup(){
  
   LedSign::Init(); //Initialize LOLShield 
  
   LedSign::SetBrightness(20); 
 
   randomSeed(analogRead(0)); //Initialize Random Number
 
}

void loop(){

  
  //##################### BALL MOVEMENT ######################
  
   //Saves last Ball X Position
   lastballx = ballx;
   lastbally = bally;
   
   // Calculates new X and Y Ball Values
   ballx = ballx + dx;
   bally = bally + dy;
 
   //Bounce off Wall top X
   if( ballx == 12){
     dx = - 1;
   }
   //Bounce off Wall bottom X
   if(ballx == 1 ){
      dx = + 1;
   }
  
   //Bounce off Wall top Y
   if( bally == 8){
      dy = - 1;
   }
   //Bounce off Wall bottom Y
   if(bally == 0 ){
      dy = + 1;
   }  

   //################# BALL MOVEMENT END #####################

   //##################### SHIP MOVEMENT ######################

    //Cosmetic: Makes ship stop if the ball just bounced off of it.
    if(lastballx >= ballx){
  
      // ### Left Ship Movement ###
      if(bally >= sp1y){
       sp1y= sp1y + 1;
      }
      else{
       sp1y = sp1y -1;
      }
      if(sp1y == 8){
        sp1y = sp1y -1;
      }
      
    }

    //Cosmetic: Makes ship stop if the ball just bounced off of it.
    if(lastballx <= ballx){

      // right Ship Movement
      if(bally >= sp2y){
       sp2y= sp2y + 1;
      }
      else{
       sp2y = sp2y -1;
      }
      if(sp2y == 0){
        sp2y = sp2y + 1;
      }
      if(sp2y == 9){
        sp2y = sp2y - 1;
      }
    
   }
      
  //################# SHIP MOVEMENT END #####################
  
 
  //Paint Objects
  paintships();
  paintball();
  delay(160);
  LedSign::Clear();
}  
  
void paintball(){
//  LedSign::Set(lastballx,lastbally,7);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF
  LedSign::Set(ballx,bally,1);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF 

}

void paintships(){
  LedSign::Set(0,sp1y,1);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF  
  LedSign::Set(0,sp1y+1,1);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF
  LedSign::Set(13,sp2y,1);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF 
  LedSign::Set(13,sp2y-1,1);  //Values: First Number: X Axis Position, Second Number: Y Axis Position, third Nubmer: LED ON/OFF 
}
