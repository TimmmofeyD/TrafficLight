int LC_g=0;  //here we assign variables responsible for the colors at each Traffic Light(future, as TL)
int LC_y=1;
int LC_r=2;
int LC_gt=3;
int LC_yt=4;
int LC_rt=5;
int LP_g=6;
int LP_r=7;
int LP_gt=8;
int LP_rt=9;
int But=10; // set the button for TL
#define phr A0  //set the photoresistor 
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
     
}

void loop() {
  /*for(int i; i=0; i<10; i++){
    digitalWrite(LC_g, HIGH);
    digitalWrite(LC_y, HIGH);
    digitalWrite(LC_r, HIGH);
    digitalWrite(LC_gt, HIGH);  //Checking to LEDs
    digitalWrite(LC_yt, HIGH);
    digitalWrite(LC_rt, HIGH);
    digitalWrite(LP_g, HIGH);
    digitalWrite(Lp_gt, HIGH);
    digitalWrite(Lp_r, HIGH);
    digitalWrite(Lp_rt, HIGH);"
    }
    */
  
  int value=analogRead(phr); // read the value from photoresistor
  int ButVal= digitalRead(But); // read the state of the button
  
  /* Now write C0DE normal operation of TL  */
         //when the movement comes from the first side
            //Light for car
                digitalWrite(LC_g, HIGH);
                digitalWrite(LC_rt, HIGH);
                 delay(3000);
            //Light for human
                digitalWrite(LP_gt, HIGH);
                digitalWrite(LP_r, HIGH);
                 delay(3000);
         //when there is a cheange of Traffic and TL (yellow)
            //Light for car
                digitalWrite(LC_g, LOW);
                digitalWrite(LC_y, HIGH);
                 delay(1000);
         //when the movement comes from the second side
             //Light from car
                digitalWrite(LC_g, LOW);
                digitalWrite(LC_rt, LOW);
                digitalWrite(LC_gt, HIGH);
                digitalWrite(LC_r, HIGH);
                 delay(3000);
             //Light from human 
                digitalWrite(LP_g, LOW);
                digitalWrite(LP_rt, LOW);
                digitalWrite(LP_r, HIGH);
                digitalWrite(LP_gt, HIGH);
                 delay(3000);
         //when there is a cheange of Traffic and TL (yellow Two)
              //Light from car
                digitalWrite(LC_yt, HIGH);
                digitalWrite(LC_gt, LOW);
                 delay(1000);
         //when the movement comes from the first side #2
             //Light from car
                digitalWrite(LC_yt, LOW);
                digitalWrite(LC_rt, HIGH);
                digitalWrite(LC_g, HIGH);
             //Light from human   
                digitalWrite(LP_g, HIGH);
                digitalWrite(LP_r, LOW);
                digitalWrite(LP_gt, LOW);
                digitalWrite(LP_rt, HIGH);
                 delay(3000);

        /* C0DE for normal operation of TL is complited */
      /* C0DE for TL button for human */
        if(ButVal == HIGH){
          
        }




}
