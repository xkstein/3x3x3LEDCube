/*
  This is my attempt at making the code for a 3x3x3 led cube without
  actually having one. 

  Dunno if it'll work, we can debug at some point 

  I'll comment the code with "//" every once in a while, and
  occasionally I'll add a "//!!" which is just to signify that I
  need you to do something (probably input the pins you're using)
*/

//!! Input your pin values for both columns and layers
int columns[3][3] = {{3,4,5},       // This just indicates which pins
                     {6,7,8},       // are connected to which columns
                     {9,10,11}};
int layer[3] = {A0,A1,A2};          // This indicates which pins are connected to which layer

void setup() {
  for (int i = 0; i < 3; i++) {         // These cycle through the columns
    for (int j = 0; i < 3; j++) {       // array and initialize each pin
      pinMode(columns[i][j], OUTPUT);
    }
  }

  for (int i = 0; i < 3; i++) {
    pinMode(layer[i], OUTPUT);
  }
}

//!! What I'd recommend here is to choose a function you like and just set it to that
// Sorry, I guarentee that trailAround() won't work, we can debug and write more sometime
void loop() {
  allOff();     // Calling a function to reset the cube (written below)
  flicker();
  trailAround();
}

void allOff() {   // This function just resets the cube
  for (int i = 0; i < 3; i++) {
    for (int j = 0; i < 3; j++) {
      digitalWrite(columns[i][j], HIGH);   // Sets every pin to be off
    }
  }
  for (int i = 0; i < 3; i++) {
    digitalWrite(layer[i], LOW);
  }
}

void allOn() {   // This function just turns on the entire cube
  for (int i = 0; i < 3; i++) {
    for (int j = 0; i < 3; j++) {
      digitalWrite(columns[i][j], LOW);   // Sets every pin to be off
    }
  }
  for (int i = 0; i < 3; i++) {
    digitalWrite(layer[i], HIGH);
  }
}

void flicker() {      // Just turns the cube on and off
  allOff();
  int tick = 0;
  while (tick < 10) {
    allOn();
    delay(326);       // Change the delay value to set the frequency of ticks
    allOff();         // Fun fact it SHOULD be at the same tempo as "Africa" by Toto

    tick++;
  }
}

void trailAround() {    // This probably won't really work
  int r, c;
  for (int l = 0; l < 3; l++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; i < 3; j++) {
        allOff();
        r = i;
        c = j;

        if (i == 1) {
          c = 2 - j;  
        }
        if (l == 1) {
          r = 2 - i;
          c = 2 - c;  
        }
        
        digitalWrite(layer[l], HIGH);
        digitalWrite(columns[r][c], LOW);   // Sets every pin to be off

        delay(10);
      }
    }
  }
}
