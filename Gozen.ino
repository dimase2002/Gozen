/*
  Test program to use game controller buttons as Bluetooth keyboard input
 */

#define USE_NIMBLE
#include BleKeyboard.h

BleKeyboard bleKeyboard(Suzuka, Vulpex studios, 100);

#define Key1 25
#define Key2 26
#define Key3 27
#define Key4 22
#define Key5 12
#define Key6 13
#define Key7 21
#define Key8 19
#define Key9 18
#define Key10 5
#define Key11 4
#define Key12 15


bool keyStates[12] = { false, false, false, false, false, false, false, false, false, false, false, false };
int keyPins[12] = { Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9, Key10, Key11, Key12 };
uint8_t keyCodes[12] = { 'g', 'z', 'q', (KEY_TAB) , 'r', ' ','f', (KEY_LEFT_CTRL) , 'x' , (KEY_LEFT_SHIFT) , 'n','e'};
int xValue;
int yValue;
int bValue;

void setup() {
  Serial.begin(115200);
  Serial.println(Code running...);
  setInputs();
  bleKeyboard.begin();
}

bool connectNotificationSent = false;

void loop() {
  int counter;
  handleJoystick();
  if (bleKeyboard.isConnected()) {
    if (!connectNotificationSent) {
      Serial.println(Code connected...);
      connectNotificationSent = true;
    }
    for (counter = 0; counter  12; counter++) {
      handleButton(counter);
    }
  }
}


void setInputs() {
  pinMode(Key1, INPUT_PULLUP);
  pinMode(Key2, INPUT_PULLUP);
  pinMode(Key3, INPUT_PULLUP);
  pinMode(Key4, INPUT_PULLUP);
  pinMode(Key5, INPUT_PULLUP);
  pinMode(Key6, INPUT_PULLUP);
  pinMode(Key7, INPUT_PULLUP);
  pinMode(Key8, INPUT_PULLUP);
  pinMode(Key9, INPUT_PULLUP);
  pinMode(Key10, INPUT_PULLUP);
  pinMode(Key11, INPUT_PULLUP);
  pinMode(Key12, INPUT_PULLUP);
}

void handleJoystick() {
  xValue = analogRead(32);
  yValue = analogRead(33);
  Serial.print(x=);
  Serial.print(xValue, DEC);
  Serial.print(,);
  Serial.print(y=);
  Serial.print(yValue, DEC);
  Serial.print(,);
  Serial.print(n);

  up
  if ((yValue = 1700 && yValue = 3000) && (xValue = 0 && xValue = 400)) {
    bleKeyboard.press('s');
    Serial.print(s);
    bleKeyboard.release('w');
    bleKeyboard.release('d');
    bleKeyboard.release('a');
  } 

  down-left
  if ((xValue = 0 && xValue = 400) && (yValue = 0 && yValue = 400)) {
    bleKeyboard.press('s');
    bleKeyboard.press('a');
    Serial.print(as);
    bleKeyboard.release('w');
    bleKeyboard.release('d');
  } 

  left
  if ((xValue = 1700 && xValue = 2000) && yValue == 0) {
    bleKeyboard.press('a');
    Serial.print(a);
    bleKeyboard.release('w');
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  up-left
  if ((xValue = 2565 && xValue = 4095) && (yValue = 0 && yValue = 400)) {
    bleKeyboard.press('w');
    bleKeyboard.press('a');
    Serial.print(w);
    Serial.print(a);
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  down
  if (xValue = 4095 && (yValue = 1700 && yValue = 2000)) {
    bleKeyboard.press('w');
    Serial.print(w);
    bleKeyboard.release('a');
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  down-right
  if ((xValue = 3000 && xValue = 4095) && (yValue = 3000 && yValue = 4095)) {
    bleKeyboard.press('d');
    bleKeyboard.press('w');
    Serial.print(w);
    Serial.print(d);
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    delay(1);
  } 

  right
  if ((xValue = 1700 && xValue = 2000) && yValue = 4095) {
    bleKeyboard.press('d');
    Serial.print(d);
    bleKeyboard.release('w');
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    delay(1);
  } 

  up-right
  if ((xValue = 0 && xValue = 400) && (yValue = 3000 && yValue = 4095)) {
    bleKeyboard.press('d');
    bleKeyboard.press('s');
    Serial.print(d);
    Serial.print(s);
    bleKeyboard.release('a');
    bleKeyboard.release('w');
    delay(1);
  } 
  idle
  if ((xValue = 1700 && xValue = 1800) && (yValue = 1700 && yValue = 1800)) {
    bleKeyboard.release('d');
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    bleKeyboard.release('w');
    Serial.print(idle);
    delay(1);
  } 
  delay(1);
}

void handleButton(int keyIndex) {
   handle the button press
  if (!digitalRead(keyPins[keyIndex])) {
     button pressed
    if (!keyStates[keyIndex]) {
       key not currently pressed
      keyStates[keyIndex] = true;
      bleKeyboard.press(keyCodes[keyIndex]);
    }
  } else {
     button not pressed
    if (keyStates[keyIndex]) {
       key currently pressed
      keyStates[keyIndex] = false;
      bleKeyboard.release(keyCodes[keyIndex]);
    }
  }
}/*
 * Test program to use game controller buttons as Bluetooth keyboard input
 */

#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Suzuka", "Vulpex studios", 100);

#define Key1 25
#define Key2 26
#define Key3 27
#define Key4 22
#define Key5 12
#define Key6 13
#define Key7 21
#define Key8 19
#define Key9 18
#define Key10 5
#define Key11 4
#define Key12 15


bool keyStates[12] = { false, false, false, false, false, false, false, false, false, false, false, false };
int keyPins[12] = { Key1, Key2, Key3, Key4, Key5, Key6, Key7, Key8, Key9, Key10, Key11, Key12 };
uint8_t keyCodes[12] = { 'g', 'z', 'q', (KEY_TAB) , 'r', ' ','f', (KEY_LEFT_CTRL) , 'x' , (KEY_LEFT_SHIFT) , 'n','e'};
int xValue;
int yValue;
int bValue;

void setup() {
  Serial.begin(115200);
  Serial.println("Code running...");
  setInputs();
  bleKeyboard.begin();
}

bool connectNotificationSent = false;

void loop() {
  int counter;
  handleJoystick();
  if (bleKeyboard.isConnected()) {
    if (!connectNotificationSent) {
      Serial.println("Code connected...");
      connectNotificationSent = true;
    }
    for (counter = 0; counter < 12; counter++) {
      handleButton(counter);
    }
  }
}


void setInputs() {
  pinMode(Key1, INPUT_PULLUP);
  pinMode(Key2, INPUT_PULLUP);
  pinMode(Key3, INPUT_PULLUP);
  pinMode(Key4, INPUT_PULLUP);
  pinMode(Key5, INPUT_PULLUP);
  pinMode(Key6, INPUT_PULLUP);
  pinMode(Key7, INPUT_PULLUP);
  pinMode(Key8, INPUT_PULLUP);
  pinMode(Key9, INPUT_PULLUP);
  pinMode(Key10, INPUT_PULLUP);
  pinMode(Key11, INPUT_PULLUP);
  pinMode(Key12, INPUT_PULLUP);
}

void handleJoystick() {
  xValue = analogRead(32);
  yValue = analogRead(33);
  Serial.print("x=");
  Serial.print(xValue, DEC);
  Serial.print(",");
  Serial.print("y=");
  Serial.print(yValue, DEC);
  Serial.print(",");
  Serial.print("\n");

  //up
  if ((yValue >= 1700 && yValue <= 3000) && (xValue >= 0 && xValue <= 400)) {
    bleKeyboard.press('s');
    Serial.print("s");
    bleKeyboard.release('w');
    bleKeyboard.release('d');
    bleKeyboard.release('a');
  } 

  //down-left
  if ((xValue >= 0 && xValue <= 400) && (yValue >= 0 && yValue <= 400)) {
    bleKeyboard.press('s');
    bleKeyboard.press('a');
    Serial.print("as");
    bleKeyboard.release('w');
    bleKeyboard.release('d');
  } 

  //left
  if ((xValue >= 1700 && xValue <= 2000) && yValue == 0) {
    bleKeyboard.press('a');
    Serial.print("a");
    bleKeyboard.release('w');
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  //up-left
  if ((xValue >= 2565 && xValue <= 4095) && (yValue >= 0 && yValue <= 400)) {
    bleKeyboard.press('w');
    bleKeyboard.press('a');
    Serial.print("w");
    Serial.print("a");
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  //down
  if (xValue >= 4095 && (yValue >= 1700 && yValue <= 2000)) {
    bleKeyboard.press('w');
    Serial.print("w");
    bleKeyboard.release('a');
    bleKeyboard.release('s');
    bleKeyboard.release('d');
    delay(1);
  } 

  //down-right
  if ((xValue >= 3000 && xValue <= 4095) && (yValue >= 3000 && yValue <= 4095)) {
    bleKeyboard.press('d');
    bleKeyboard.press('w');
    Serial.print("w");
    Serial.print("d");
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    delay(1);
  } 

  //right
  if ((xValue >= 1700 && xValue <= 2000) && yValue >= 4095) {
    bleKeyboard.press('d');
    Serial.print("d");
    bleKeyboard.release('w');
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    delay(1);
  } 

  //up-right
  if ((xValue >= 0 && xValue <= 400) && (yValue >= 3000 && yValue <= 4095)) {
    bleKeyboard.press('d');
    bleKeyboard.press('s');
    Serial.print("d");
    Serial.print("s");
    bleKeyboard.release('a');
    bleKeyboard.release('w');
    delay(1);
  } 
  //idle
  if ((xValue >= 1700 && xValue <= 1800) && (yValue >= 1700 && yValue <= 1800)) {
    bleKeyboard.release('d');
    bleKeyboard.release('s');
    bleKeyboard.release('a');
    bleKeyboard.release('w');
    Serial.print("idle");
    delay(1);
  } 
  delay(1);
}

void handleButton(int keyIndex) {
  // handle the button press
  if (!digitalRead(keyPins[keyIndex])) {
    // button pressed
    if (!keyStates[keyIndex]) {
      // key not currently pressed
      keyStates[keyIndex] = true;
      bleKeyboard.press(keyCodes[keyIndex]);
    }
  } else {
    // button not pressed
    if (keyStates[keyIndex]) {
      // key currently pressed
      keyStates[keyIndex] = false;
      bleKeyboard.release(keyCodes[keyIndex]);
    }
  }
}
