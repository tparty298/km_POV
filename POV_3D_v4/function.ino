void CO(Adafruit_NeoPixel *p, int r,int g, int b){
  for(int i=0;i<NUMPIXELS;i++){
    p->setPixelColor(i, p->Color(r,g,b));
  }
  p->show();
}

void CO_1(Adafruit_NeoPixel *p,int which, int r,int g, int b){
  p->setPixelColor(which, p->Color(r,g,b));
  p->show();
}

void CO_multiple(Adafruit_NeoPixel *p,int startL, int endL, int r,int g, int b){
  for(int i=startL;i<=endL;i++){
    p->setPixelColor(i, p->Color(r,g,b));
  }
  p->show();
}

