#include "pitches.h"

int speakerpin = D0;
int note[] = {2093, 2349, 2637, 2793, 3136, 3520, 3951, 4186};

void schoolplay() {
  int melody[] = {NOTE_G7, NOTE_G7, NOTE_A7, NOTE_A7, NOTE_G7,
                  NOTE_G7, NOTE_E7, NOTE_G7, NOTE_G7, NOTE_E7,
                  NOTE_E7, NOTE_D7, NOTE_G7, NOTE_G7, NOTE_A7,
                  NOTE_A7, NOTE_G7, NOTE_G7, NOTE_E7, NOTE_G7,
                  NOTE_E7, NOTE_D7, NOTE_E7, NOTE_C7
                 };
  int noteDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};
  for (int thisNote = 0; thisNote < 24; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerpin, melody[thisNote], noteDuration); //소리를 낸다.
    int pauseBetweenNotes = noteDuration * 1.30;      //delay 계산식
    delay(pauseBetweenNotes);                         //delay
    noTone(speakerpin);                               //대상핀 출력 중단
  }
}

void superplay() {
  int melody2[] = {
    NOTE_E7, NOTE_E7, 1, NOTE_E7, 1, NOTE_C7, NOTE_E7, 1, NOTE_G7, 1, 1,  1, NOTE_G6, 1, 1, 1,
    NOTE_C7, 1, 1, NOTE_G6, 1, 1, NOTE_E6, 1, 1, NOTE_A6, 1, NOTE_B6, 1, NOTE_AS6, NOTE_A6, 1,
    NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 1, NOTE_F7, NOTE_G7, 1, NOTE_E7, 1, NOTE_C7, NOTE_D7, NOTE_B6, 1, 1,
    NOTE_C7, 1, 1, NOTE_G6, 1, 1, NOTE_E6, 1, 1, NOTE_A6, 1, NOTE_B6, 1, NOTE_AS6, NOTE_A6, 1,
    NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 1, NOTE_F7, NOTE_G7, 1, NOTE_E7, 1, NOTE_C7, NOTE_D7, NOTE_B6, 1, 1
  };
  int noteDurations2[] = {
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  };
  int size = sizeof(melody2) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(speakerpin, melody2[thisNote], noteDuration); //소리를 낸다.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerpin);                               //대상핀 출력 중단
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(speakerpin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char inputData = Serial.read();
    if (inputData == 's') {
      schoolplay();
    }
    else if (inputData == 'p') {
      superplay();
    }
    else if (inputData == 'a') {
      int elementCount = sizeof(note) / sizeof(int);
      for (int i = 0; i < elementCount; i++)  //note를 play
      {
        tone(speakerpin, note[i], 500);
        delay(750);
      }
    }
    else if (inputData == 'n') {
      char temp = Serial.read();
      int sel_note;
      if (temp == 'C') {
        sel_note = 0;
      }
      else if (temp == 'D') {
        sel_note = 1;
      }
      else if (temp == 'E') {
        sel_note = 2;
      }
      else if (temp == 'F') {
        sel_note = 3;
      }
      else if (temp == 'G') {
        sel_note = 4;
      }
      else if (temp == 'A') {
        sel_note = 5;
      }
      else {
        sel_note = 6;
      }
      tone(speakerpin, note[sel_note], 500);
    }
  }
}

