#include <M5Stack.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ZoomKey");
 
void setup() {
  M5.begin();
  M5.Power.begin();
 
  bleKeyboard.begin();
  
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setTextSize(1);

  M5.Lcd.setCursor(40, 220);  
  M5.Lcd.println("MIC");

  M5.Lcd.setCursor(130, 220);  
  M5.Lcd.println("CAMERA");

  M5.Lcd.setCursor(230, 220);
  M5.Lcd.println("SHARE");

}
 
void loop() {
  M5.update();

  if (bleKeyboard.isConnected()) {

    M5.Lcd.setTextColor(BLACK, GREEN);
    M5.Lcd.setCursor(2, 2);
    M5.Lcd.println("BT Connect-OK");
  
    if (M5.BtnA.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('a');
      bleKeyboard.releaseAll();
    }

    if (M5.BtnB.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('v');
      bleKeyboard.releaseAll();
    }

    if (M5.BtnC.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('s');
      bleKeyboard.releaseAll(); 
    }
  
  } else {
    M5.Lcd.setTextColor(BLACK, RED);
    M5.Lcd.setCursor(2, 2);
    M5.Lcd.println("BT Connect-NG");
  }

}
