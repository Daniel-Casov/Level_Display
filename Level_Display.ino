#include <TFT_eSPI.h>
#include "nodo.h"
#include "wifi25.h"
#include "clock70.h"

#define Potenciometro 15


int nivel = 0;
int auxNivel = 0;
int angulo = 0;

TFT_eSPI tft=TFT_eSPI();
TFT_eSprite SignalSprite = TFT_eSprite(&tft);
TFT_eSprite ArcSprite = TFT_eSprite(&tft);
TFT_eSprite TextSprite = TFT_eSprite(&tft);
TFT_eSprite ClockSprite = TFT_eSprite(&tft);


void setup()
 {   
   tft.init();   
   tft.fillScreen(TFT_WHITE);

   tft.setSwapBytes(true);
   tft.pushImage(45, 45, 150, 150, nodo);
   delay(2000);
   tft.fillScreen(TFT_BLACK);

   SignalSprite.createSprite(25, 25);
   SignalSprite.setSwapBytes(true);
   SignalSprite.pushImage(0, 0, 25, 25, wifi25);

   ClockSprite.createSprite(70, 70);
   ClockSprite.setSwapBytes(true);
   ClockSprite.pushImage(0, 0, 70, 70, clock70);

   TextSprite.createSprite(165,80);
   TextSprite.setSwapBytes(true);
   TextSprite.setTextColor(TFT_RED, TFT_GREEN);

   ArcSprite.createSprite(240, 230);
   ArcSprite.setSwapBytes(true);
   ArcSprite.fillRectVGradient(0, 0, 240, 230, TFT_BLUE, TFT_BLACK);

   ArcSprite.pushSprite(0, 0, TFT_BLACK);

   

   DataIn();
   angulo = map(nivel, 0, 100, 30, 330);   

   //------------- Lesser than 10 ------------------------------------------------

   if(nivel < 10)     
   {  
     if(nivel == 0)
      {
      for(int i=31; i<=angulo; i++)
        {     

        ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_RED, TFT_BLACK, true);
        ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
        ArcSprite.pushSprite(0, 0, TFT_BLACK);   
        delay(50);
        }        
      }
     else
      {
      for(int i=31; i<=angulo; i++)
        {     
        ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_RED, TFT_BLACK, true);
        ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
        ArcSprite.pushSprite(0, 0, TFT_BLACK);   
        delay(50);
        }        
      }
   }
   //------------- Lesser than 25 ------------------------------------------------

   if(nivel >= 10 && nivel <= 25)
   {  
   for(int i=31; i<=angulo; i=i+2)
    {     
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_ORANGE, TFT_BLACK, true);
    ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
    ArcSprite.pushSprite(0, 0, TFT_BLACK);   
    delay(50);
    }    
   }

   //------------- Lesser than 50 ------------------------------------------------

   if(nivel > 25 && nivel <= 50)
   {  
   for(int i=31; i<=angulo; i=i+5)
    {    
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_YELLOW, TFT_BLACK, true);
    ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
    ArcSprite.pushSprite(0, 0, TFT_BLACK);   
    delay(50);
    }
   }

   //------------- Lesser than 75 ------------------------------------------------

   if(nivel > 50 && nivel <= 75)
   {  
   for(int i=31; i<=angulo; i=i+10)
    {    
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_GREEN, TFT_BLACK, true);
    ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
    ArcSprite.pushSprite(0, 0, TFT_BLACK);   
    delay(50);
    }
   }

   //------------- Lesser than 100 ------------------------------------------------

   if(nivel > 75 && nivel <= 100)
   {  
   for(int i=31; i<=angulo; i=i+10)
    {     
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, i, TFT_BLUE, TFT_BLACK, true);
    ClockSprite.pushToSprite(&ArcSprite, 85, 85, TFT_BLACK);
    ArcSprite.pushSprite(0, 0, TFT_BLACK);   
    delay(50);
    }
   }   
  }





void loop()
 {


   DataIn();
   angulo = map(nivel, 0, 100, 30, 330);
      
   ArcSprite.fillRectVGradient(0, 0, 240, 230, TFT_BLUE, TFT_BLACK); 
   TextSprite.fillScreen(TFT_BLACK);

   //------------- Lesser than 10 ------------------------------------------------

   if(nivel < 10)     
   {        
     if(nivel == 0)
     {
      ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, 31, TFT_RED, TFT_BLACK, true);

      TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);
      TextSprite.setCursor(55, 0, 8);
      TextSprite.print(nivel);
      SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
      TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);

      ArcSprite.pushSprite(0, 0, TFT_BLACK);
     }
     else
     {
      ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, angulo, TFT_RED, TFT_BLACK, true);

      TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);
      TextSprite.setCursor(55, 0, 8);
      TextSprite.print(nivel);
      SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
      TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);

      ArcSprite.pushSprite(0, 0, TFT_BLACK);
     }
   }
   //------------- Lesser than 25 ------------------------------------------------

   if(nivel >= 10 && nivel <= 25)
   {  
      
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, angulo, TFT_ORANGE, TFT_BLACK, true);

    TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);
    TextSprite.setCursor(25, 0, 8);
    TextSprite.print(nivel);
    SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
    TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);

    ArcSprite.pushSprite(0, 0, TFT_BLACK);     

   }

   //------------- Lesser than 50 ------------------------------------------------

   if(nivel > 25 && nivel <= 50)
   {  
    
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, angulo, TFT_YELLOW, TFT_BLACK, true);

    TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);
    TextSprite.setCursor(25, 0, 8);
    TextSprite.print(nivel);
    SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
    TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);

    ArcSprite.pushSprite(0, 0, TFT_BLACK);
   }

   //------------- Lesser than 75 ------------------------------------------------

   if(nivel > 50 && nivel <= 75)
   {  
     
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, angulo, TFT_GREEN, TFT_BLACK, true);

    TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);
    TextSprite.setCursor(25, 0, 8);
    TextSprite.print(nivel);
    SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
    TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);

    ArcSprite.pushSprite(0, 0, TFT_BLACK);
   }

   //------------- Lesser than 100 ------------------------------------------------

   if(nivel > 75 && nivel <= 100)
   {  
    
    ArcSprite.drawSmoothArc(120, 115, 110, 85, 30, angulo, TFT_BLUE, TFT_BLACK, true);

    TextSprite.setTextColor(TFT_WHITE, TFT_BLACK);

    if(nivel == 100)
      {
      TextSprite.setCursor(0, 0, 8);
      TextSprite.print(nivel);
      SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
      TextSprite.pushToSprite(&ArcSprite, 35, 75, TFT_BLACK);
      }
    else
      {
      TextSprite.setCursor(25, 0, 8);
      TextSprite.print(nivel);
      SignalSprite.pushToSprite(&ArcSprite, 110, 195, TFT_BLACK);
      TextSprite.pushToSprite(&ArcSprite, 42, 75, TFT_BLACK);
      }
    

    ArcSprite.pushSprite(0, 0, TFT_BLACK);
   }
    // delay(1000);

    

}


void DataIn()
{
  nivel = map(analogRead(Potenciometro), 0, 4095, 0, 100);
}
