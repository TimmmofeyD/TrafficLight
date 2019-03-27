#include <IRremote.h> // we connect libraries
int LC_g=2;  //here we assign variables responsible for the colors at each Traffic Light(future, as TL)
int LC_y=3;
int LC_r=4;
int LC_gt=5;
int LC_yt=6;
int LC_rt=7;
int LP_g=8;
int LP_r=9;
int LP_gt=10;
int LP_rt=11;
int But=12; // set the button for TL

//переменные для трафика
int big_traffic = 5000;


#define phr A0  //set the photoresistor 
IRrecv irrecv(13); // pin to which IR is connected

decode_results results;

void check_night(){
  int value=analogRead(phr); // read the value from photoresistor 
  int flag = 1;
      while (value>500){
            //откключаем все сигналы
            if(flag == 1){
              digitalWrite(LC_g, LOW);
              digitalWrite(LC_r, LOW);
              digitalWrite(LC_gt, LOW);
              digitalWrite(LC_rt, LOW);
              digitalWrite(LP_g, LOW);
              digitalWrite(LP_r, LOW);
              digitalWrite(LP_rt, LOW);
              digitalWrite(LP_gt, LOW);
              flag = 0;
              }
          // мигание желтого
           
          digitalWrite(LC_y, HIGH);
          digitalWrite(LC_yt, HIGH);
           delay(1000);
          digitalWrite(LC_y, LOW);
          digitalWrite(LC_yt, LOW);
           delay(1000);
      
        value=analogRead(phr);
      }
       flag = 1;
       for(int i=2; i<12; i++)
            digitalWrite(i, LOW);
       return ;
}

void remote_control(){
 /* C0DE for TL IRremote controler */
        if( irrecv.decode( &results)){ //if the data came
        Serial.println(results.value, HEX); // print the data // we recognize the butttons  necessary for us
        //irrecv.resume(); // accept the fillowing command
       
        if(results.value == 0xFF6897){
         
          for(int i=2; i<12; i++){
            digitalWrite(i, LOW);
             
          }
           while (true){
          digitalWrite(LC_g, HIGH);
          digitalWrite(LC_rt, HIGH);
          digitalWrite(LP_r, HIGH);
          digitalWrite(LP_rt, HIGH);
          if( irrecv.decode( &results)){
          Serial.println(results.value, HEX);
          if (results.value == 0xFF30CF){
            for(int i=2; i<12; i++)
            digitalWrite(i, LOW);
            return ;}
            irrecv.resume();
          }
           }
        }
  irrecv.resume();
}
}

void main_traffic(){

  //проверка на наступление ночи
 check_night();  
 
// контроль с пульта
remote_control();
 
   /* Now write C0DE normal operation of TL */
         //when the movement comes from the first side
            //Light for car
                digitalWrite(LC_y, LOW);
                digitalWrite(LC_yt, LOW);
                digitalWrite(LC_g, HIGH);
                digitalWrite(LC_rt, HIGH);
                 delay(3000);
 //проверка на наступление ночи
 check_night(); 
 // контроль с пульта
remote_control();
                 
            //Light for human
                digitalWrite(LP_g, HIGH);
                digitalWrite(LP_rt, HIGH);
                 delay(3000);
 //проверка на наступление ночи
 check_night(); 
 // контроль с пульта
remote_control();
         //when there is a cheange of Traffic and TL (yellow)
            //Light for car

                digitalWrite(LC_y, HIGH);
                 delay(1000);
 //проверка на наступление ночи
 check_night(); 
 // контроль с пульта
remote_control();
         //when the movement comes from the second side
                digitalWrite(LP_gt, LOW);
                digitalWrite(LP_r, LOW);
             //Light from car
                digitalWrite(LC_g, LOW);
                 delay(3000);
 //проверка на наступление ночи
 check_night();  
 // контроль с пульта
remote_control();        
                digitalWrite(LC_y, LOW);
                digitalWrite(LC_rt, LOW);
                digitalWrite(LC_gt, HIGH);
                digitalWrite(LC_r, HIGH);
                
             //Light from human 
     
                digitalWrite(LP_rt, HIGH);
                digitalWrite(LP_g, HIGH);
                 delay(3000);
         //when there is a cheange of Traffic and TL (yellow Two)
              //Light from car
                digitalWrite(LC_yt, HIGH);
                delay(1000);
                digitalWrite(LC_gt, LOW);
                
                digitalWrite(LC_r, LOW);
  //проверка на наступление ночи
 check_night();  
 // контроль с пульта
remote_control();               
         //when the movement comes from the first side #2
             //Light from car
                digitalWrite(LC_yt, LOW);
                digitalWrite(LC_rt, HIGH);
                digitalWrite(LC_g, HIGH);
             //Light from human   
                
                digitalWrite(LP_rt, LOW);
                digitalWrite(LP_g, LOW);
                digitalWrite(LP_gt, HIGH);
                digitalWrite(LP_r, HIGH);
                 delay(3000);

       /* C0DE for normal operation of TL is complited */
       
}


void setup() {
  pinMode(But, INPUT); //configurate Arduino on receive data from the button
  pinMode(LC_g, OUTPUT); //configurate Arduino to send data to the TL
  pinMode(LC_y, OUTPUT);
  pinMode(LC_g, OUTPUT);
  pinMode(LC_gt, OUTPUT);   
  pinMode(LC_yt, OUTPUT);
  pinMode(LC_rt, OUTPUT);
  pinMode(LP_g, OUTPUT);
  pinMode(LP_gt, OUTPUT);
  pinMode(LP_r, OUTPUT); 
  pinMode(LP_rt, OUTPUT);
  Serial.begin(9600); //set the speed of the COM port  
  irrecv.enableIRIn();  //we start reception
}

void loop() {
    /* C0DE for TL photoresistor */
     
       
        /* C0DE for TL button for human
     int ButVal=digitalRead(But);
        Serial.println(ButVal); */
        
    

 /*for (int i = 0; i < 11; i++) { //Checking to LEDs
  digitalWrite(i, HIGH);  
  delay(100);
  digitalWrite(i, LOW);
  delay(100);
  } */
    
  
main_traffic();
 
 
     
     
}
