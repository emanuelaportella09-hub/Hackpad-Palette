#include <Keyboard.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUM_ROWS 4
#define NUM_COLS 4

int pinRow[NUM_ROWS] = {0,1,2,3};
int pinColomn[NUM_COLS] = {7,8,9,10};

int mapButtons[NUM_ROWS][NUM_COLS] = {
  {KEY_F13, KEY_F14 , KEY_F15 , KEY_F16 },
  {KEY_F17, KEY_F18 , KEY_F19 , KEY_F20 },
  {KEY_F21, KEY_F22 , KEY_F23 , KEY_F24 },
  {KEY_KP_1, KEY_KP_2 , KEY_KP_3 , KEY_KP_4}
};


String mapNames [NUM_ROWS][NUM_COLS] ={
  {"Rosso","Arancione", "Giallo","Verde"},
  {"Ciano","Blu","Viola","Magenta"},
  {"Rosa","Marrone","Nero","Bianco"},
  {"Grigio", "Verde scuro", "Blu scuro", "Oro"},
};

bool statebefore[NUM_ROWS][NUM_COLS];

void setup() {
  Keyboard.begin();



  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,8);
  display.println("Palette");
  display.display();



  for(int r =0; r < NUM_ROWS; r++ ){
    pinMode(pinRow[r], OUTPUT);
    digitalWrite(pinRow[r], HIGH);
  }

  for(int c =0; c < NUM_COLS; c++ ){
    pinMode(pinColomn[c], INPUT_PULLUP);
  }

   for(int r =0; r < NUM_ROWS; r++ ){
    for(int c =0; c < NUM_COLS; c++ ){
      statebefore[r][c] = HIGH;
    }}
}

void loop() {
  scanMatrix();
  delay(5);
}

void scanMatrix(){
  for(int r =0; r < NUM_ROWS; r++ ){
    digitalWrite(pinRow[r],LOW);
    for(int c =0; c < NUM_COLS; c++ ){
      bool stateNow = digitalRead(pinColomn[c]);
      if (stateNow == LOW && statebefore[r][c] == HIGH){
        Keyboard.press(mapButtons[r][c]);
        Keyboard.release(mapButtons[r][c]);
        showColorOnDisplay(mapNames[r][c]);
      }
      statebefore[r][c] = stateNow;
    }
    digitalWrite(pinRow[r],HIGH);
  }
}

void showColorOnDisplay(String ColorName){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,8);
  display.println(ColorName);
  display.display();

}



