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
////////////////////
double borderVal=1022;
int splitNum=6;
///////////////////

void setup() {
  Serial.begin(9600);

  for(int i=0;i<THICK*2;i++){
    p[i]=Adafruit_NeoPixel(NUMPIXELS, PININIT+i, NEO_GRB + NEO_KHZ800);
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
  /*
  phVal = analogRead(A0);
  if(phVal<borderVal){
    rotInit=1;
    diffMillis=millis()-beforeRotateInitMillis;//millis per rot
    beforeRotateInitMillis=millis();
  }else{
    rotInit=0;
  }
  */
  
  /////-----------------------------------------------------------
 

  /*
  for(int i=0;i<THICK*2;i++){
    CO(&p[i],255,0,0);
  }
  */
  /*
  p[0].setPixelColor(0, p[0].Color(255,0,0));
  p[1].setPixelColor(0, p[1].Color(255,0,0));
  p[2].setPixelColor(0, p[2].Color(255,0,0));
  p[3].setPixelColor(0, p[3].Color(255,0,0));
  */

  if(rotInit==1){//rotation angle 0
    Serial.println(phVal);
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
      //p[i].show();
    }
  }

  for(int i=0; i<THICK*2; i++){
    //p[i].show();
  }
  //delay(50);
}
