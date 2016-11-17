/*
 An Adaptation on Fading Application that lets you input data into serial to control two color changing LEDS and the speed at which they fade

  Roxanne Coburn
  11/16/2016
 */


boolean LED1_blue = 0; //11    
boolean LED1_green = 0; //10
boolean LED1_red = 0; //9

boolean LED2_blue = 0; //6    
boolean LED2_green = 0; //5
boolean LED2_red = 0; //3

int speed_var = 30;


void setup() { 
 // initialize the digital pins as an output.

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);

// Turn the Serial Protocol ON
 Serial.begin(9600);
}

void loop() {
 byte byteRead;
 if (Serial.available()) {
  
  byteRead = Serial.read();
  
  byteRead=byteRead-'0';

  if(byteRead == 0) {
    
      LED1_blue = 0; //11    
      LED1_green = 0; //10
      LED1_red = 0; //9
  
      LED2_blue = 0; //6    
      LED2_green = 0; //5
      LED2_red = 0; //3

      speed_var = 30; //normal speed
  }
  if(byteRead == 1) {
    LED1_blue = !LED1_blue; //11  
  }
  if(byteRead == 2) {
    LED1_green = !LED1_green; //10 
  }
  if(byteRead == 3) {
    LED1_red = !LED1_red; //9  
  }
    if(byteRead == 4) {
    LED2_blue = !LED2_blue; //11  
  }
  if(byteRead == 5) {
    LED2_green = !LED2_green; //10 
  }
  if(byteRead == 6) {
    LED2_red = !LED2_red; //9  
  }

  if(byteRead == 7) {
    speed_var = speed_var + 5;
  }

  if(byteRead == 8) {
    speed_var = speed_var - 5;
  }

    if(byteRead == 9) {
    speed_var = 30;
  }


  
 Serial.print(byteRead);
 }
 else {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    if(LED1_blue) {
      analogWrite(11, fadeValue);
    }
    else {
      analogWrite(11, 0);
    }
    if(LED1_green) {
      analogWrite(10, fadeValue);
    }
    else {
      analogWrite(10, 0);
    }

    if(LED1_red) {
      analogWrite(9, fadeValue);
    }
    else {
      analogWrite(9, 0);
    }

    if(LED2_blue) {
      analogWrite(6, fadeValue);
    }
    else {
      analogWrite(6, 0);
    }
    if(LED2_green) {
      analogWrite(5, fadeValue);
    }
    else {
      analogWrite(5, 0);
    }

    if(LED2_red) {
      analogWrite(3, fadeValue);
    }
    else {
      analogWrite(3, 0);
    }

    delay(speed_var);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
     if(LED1_blue) {
      analogWrite(11, fadeValue);
    }
    else {
      analogWrite(11, 0);
    }
    if(LED1_green) {
      analogWrite(10, fadeValue);
    }
    else {
      analogWrite(10, 0);
    }

    if(LED1_red) {
      analogWrite(9, fadeValue);
    }
    else {
      analogWrite(9, 0);
    }

    if(LED2_blue) {
      analogWrite(6, fadeValue);
    }
    else {
      analogWrite(6, 0);
    }
    if(LED2_green) {
      analogWrite(5, fadeValue);
    }
    else {
      analogWrite(5, 0);
    }

    if(LED2_red) {
      analogWrite(3, fadeValue);
    }
    else {
      analogWrite(3, 0);
    }
    delay(speed_var);
  }
 }
}

