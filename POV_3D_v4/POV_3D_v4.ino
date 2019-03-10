#include <Adafruit_NeoPixel.h>

#define PININIT        2
#define NUMPIXELS      8
#define THICK          6
#define BRIGHTNESS     255
#define PIN 13

//Adafruit_NeoPixel p1=Adafruit_NeoPixel(NUMPIXELS, 13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p[THICK*2];

unsigned long beforeRotateInitMillis=0;
unsigned long diffMillis=1;
double phVal=1;
int rotInit=0;//if 1->rot init position
int loopCount=0;
////////////////////
double borderVal=1000;
int splitNum=6;
///////////////////
int Pin;

void setup() {
  Serial.begin(9600);

  for(int i=0;i<THICK*2;i++){
    Pin = PININIT + i;
    p[i]=Adafruit_NeoPixel(NUMPIXELS, Pin, NEO_GRB + NEO_KHZ800);
  }
  
  for(int i=0;i<THICK*2;i++){
    p[i].begin();
  }

  for(int i=0;i<THICK*2;i++){
    p[i].show();
  }
  
  for(int i=0;i<THICK*2;i++){
    p[i].setBrightness(BRIGHTNESS);
  }

  
  for(int i=0;i<THICK*2;i++){
    for(int j=0;j<NUMPIXELS;j++){
      p[i].setPixelColor(j, p[i].Color(0,0,0));
    }
    p[i].show();
  }
  rotInit = 1;
}

void loop() {
  /////ph--------------------------------------------------------
  phVal = analogRead(A0);
  if(phVal<borderVal){
    rotInit=1;
    diffMillis=millis()-beforeRotateInitMillis;//millis per rot
    beforeRotateInitMillis=millis();
  }else{
    rotInit=0;
  }
  
  /////-----------------------------------------------------------



  /*
  Serial.println(phVal);
  if(rotInit==1){//rotation angle 0
    for(int i=0;i<THICK*2;i++){
      for(int j=0;j<NUMPIXELS;j++){
        p[i].setPixelColor(j, p[i].Color(255,0,0));
      }
      p[i].show();
    }
    //rotInit = 2;
  }else if(rotInit==0){
    for(int i=0;i<THICK*2;i++){
      for(int j=0;j<NUMPIXELS;j++){
        p[i].setPixelColor(j, p[i].Color(0,0,0));
      }
      p[i].show();
    }
  }
  */

  
  /*
  switch(loopCount%3){
    case 0:
      for(int i=0;i<THICK*2;i++){
        for(int j=0;j<NUMPIXELS;j++){
          p[i].setPixelColor(j, p[i].Color(255,0,0));
        }
      }
      break;
    case 1:
      for(int i=0;i<THICK*2;i++){
        for(int j=0;j<NUMPIXELS;j++){
          p[i].setPixelColor(j, p[i].Color(0,255,0));
        }
      }
      break;
    case 2:
      for(int i=0;i<THICK*2;i++){
        for(int j=0;j<NUMPIXELS;j++){
          p[i].setPixelColor(j, p[i].Color(0,0,255));
        }
      }
      break;
  }
  */

  
    
  //p[0].setPixelColor(0, p[0].Color(255,0,0));
  int r = 255;
  for(int i=0; i<THICK; i++){
    for(int j=0; j<NUMPIXELS; j++){
      if(i>=j){
        p[i].setPixelColor(j, p[i].Color(0,0,r));
      }else{
        p[i].setPixelColor(j, p[i].Color(0,0,0));
      }
    }
    p[i].show();
  }
  
  for(int i=THICK*2; i>=THICK; i--){
    for(int j=0; j<NUMPIXELS; j++){
      p[i].setPixelColor(j, p[i].Color(0,0,0));
    }
    p[i].setPixelColor(7, p[i].Color(r,0,r));
    p[i].show();
  }
  
  
  //////////////////
  for(int i=THICK; i<THICK*2; i++){
    p[i].show();
  }
  
  loopCount++;
  delay(2);
  /////////////////
}
