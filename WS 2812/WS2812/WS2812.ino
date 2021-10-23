#include <Adafruit_NeoPixel.h>    // importar libreria

//   NEO_KHZ800  800 KHz velocidad de datos (WS2812 y nuevos)
//   NEO_KHZ400  400 KHz velocidad de datos (WS2811 y mas antiguos)
//   NEO_GRB     flujo de datos en orden GRB (WS2812 y nuevos)
//   NEO_RGB     flujo de datos en orden RGB (versiones mas antiguas)

Adafruit_NeoPixel tira = Adafruit_NeoPixel(256, 2, NEO_GRB + NEO_KHZ800); // creacion de objeto "tira"
// con una cantidad de 256 pixeles, sobre pin 2 del Arduino

void setup(){
  tira.begin();       // inicializacion de la tira
  tira.show();        // muestra datos en pixel
}

void loop(){
  tira.setBrightness(200);               // brillo global para 0 apagado 255 maximo
  for(int i = 0; i < 256; i=i+1){   // bucle para recorrer posiciones 0 a 255
    tira.setPixelColor(i, 0, i, 255);   //  (posicion,R,G,B)
    tira.show();      // muestra datos en pixel 
    delay(100);       // breve demora 
  
  }
  tira.clear();       //  apagado
}
