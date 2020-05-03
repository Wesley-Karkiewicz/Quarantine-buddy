#include <Tone.h>
Tone SpeakerA;
Tone SpeakerB;  
int Din = 27;
int CS = 25;
int CLK = 23;



int Base1[] ={
  //Page1
  //Bar 1 (12)
  0, 0, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_B4,NOTE_B4, NOTE_G4, NOTE_G4, NOTE_E4,NOTE_E4,
  //Bar2 (12)
  NOTE_DS4, NOTE_DS4, NOTE_FS4, NOTE_FS4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_FS4, NOTE_FS4,
  //Bar3 (12)
  NOTE_D4,  NOTE_D4,  NOTE_G4,  NOTE_G4,  NOTE_B4, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_G4,  NOTE_G4,
  //Bar 4 (6)
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_B3,
  //Bar5 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar6 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4,NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,
  //Bar7 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar8 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar9 (12)
  NOTE_B3, NOTE_B3, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_B4, NOTE_B4,  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4,
  //Bar10 (12)
  NOTE_B3, NOTE_B3, NOTE_FS4, NOTE_FS4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_FS4, NOTE_FS4,
  //Bar11 (12)
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_B4, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_G4,
  //Bar12(6)
  NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,

  //Page2
  //Bar 13 (12)
   NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar 14 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4,NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,
  //Bar 15 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar 16 (12)
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4,
  //Bar 17 (12)
  NOTE_B3, NOTE_B3, NOTE_G4, NOTE_G4,  NOTE_B4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_B4,NOTE_G4, NOTE_G4,
  //Bar 18 (12)
  NOTE_FS4, NOTE_FS4, NOTE_B4, NOTE_B4, NOTE_DS5, NOTE_DS5, NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_B4,
  //Bar 19  (12)
  NOTE_G4, NOTE_G4, NOTE_B4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_B4,
  //Bar 20 (6)(Switched to Treble for some fucking reason, fuck u joji)
  NOTE_C6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5,
  //Bar 21 (12)
  NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5,
  //Bar 22 (12)
   NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5,
   //Bar23 (12)
   NOTE_C6, NOTE_C6, NOTE_C6,  NOTE_C6, NOTE_C6, NOTE_C6,  NOTE_C6, NOTE_C6, NOTE_C6,  NOTE_C6, NOTE_C6, NOTE_C6, 
   //Bar24(6)
   NOTE_C6, NOTE_C6, NOTE_C6,  NOTE_D6, NOTE_D6, NOTE_D6, 
   //Bar25(12)
   NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, 
   //Bar26 (12)
   NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, 
   //Bar27 (12)
   NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5,
}; 



int Melody1[] = {
  //page1
  //Bar1 (12)
  0,0,0,0,0,0,0,0,0,0,0,0,
  //Bar2 (12)
  0,0,0,0,0,0,0,0,0,0,0,0,
  //Bar3 (12)
  0,0,0,0,0,0,0,0,0,0,0,0,
  //Bar4 (6)
  0,0,0,0,0,0,
  //Bar5(12)
  0,0,0,0, NOTE_B5, 0, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5,
  //Bar 6(12)
  NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5,0,0,
  //Bar 7(12)
  0,0,0,0, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5,NOTE_A5,NOTE_A5, NOTE_G5, NOTE_G5,
  //Bar 8(12)
  NOTE_G5, NOTE_G5, NOTE_G5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,0,0,
  //Bar 9(12)
  0,0,0,0, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_E6,
  //Bar 10(12)
  NOTE_FS6, NOTE_G6, NOTE_G6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_B5, 0, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5,
  //Bar 11(12) (the numbers to give a voice like sound)
  NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5 +1, NOTE_G5-2, NOTE_G5+2,  NOTE_G5-2, NOTE_G5, 0,0,0,0,
  //Bar 12 (6)
  0,0,0,0,0,0,

  //Page 2
  //Bar 13 (12)
  0,0,0,0, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_G5, 
  //Bar 14 (12)
  NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5 , 0,0,0,0,0,0, 
  //Bar 15 (12)
  0,0, NOTE_B5, NOTE_B5,NOTE_B5, NOTE_B5,NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  //Bar 16 (12)
  NOTE_G5, NOTE_G5,NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, 0,0,
  //Bar 17 (12)
  0, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B5, NOTE_B5, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_E6,
  //Bar 18(12)
  NOTE_G6, NOTE_G6, NOTE_E6, NOTE_D6, NOTE_B5,NOTE_B5,0, NOTE_A5, NOTE_A5, NOTE_D6, NOTE_D6,
  //Bar 19 (12)
  NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 0,0,0,0,0, NOTE_G6,
  //Bar 20 (6)
  NOTE_C7, NOTE_B6, NOTE_B6, NOTE_A6, NOTE_A6, NOTE_G6,
  //Bar 21 (12)
  NOTE_A6, NOTE_G6, NOTE_E6, NOTE_E6, 0, 0, 0, 0, NOTE_A6, NOTE_A6, NOTE_B6, NOTE_B6,
  //Bar 22 (12)
   NOTE_A6, NOTE_A6, NOTE_G6, NOTE_G6, NOTE_G6, NOTE_E6, NOTE_C7, NOTE_D7, NOTE_D7, NOTE_A6, NOTE_A6, NOTE_G6,
  //Bar 23 (12)
   NOTE_A6, NOTE_G6, NOTE_E6, NOTE_E6, 0,0, 0, NOTE_A6, NOTE_A6, NOTE_B6, NOTE_B6,

   //Page 3
   //Bar 24 (12)
   NOTE_A6, NOTE_A6, NOTE_G6, NOTE_G6, NOTE_G6, NOTE_G6, NOTE_C7, NOTE_C7, NOTE_A6, NOTE_A6, NOTE_G6, NOTE_G6,
   //Bar 25 (12)
   NOTE_A6, NOTE_A6,NOTE_A6, NOTE_A6,NOTE_A6, NOTE_A6, NOTE_G6, NOTE_E6 ,NOTE_G6, NOTE_G6, NOTE_E6, NOTE_D6,
   //BAR 26 (12)
   NOTE_E6, NOTE_E6,NOTE_E6, NOTE_E6, NOTE_D6, NOTE_B5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_B5, NOTE_A5,
   //Bar 27 (12)
   NOTE_B5, NOTE_B5, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, 0,0
  //Bar 28 (6)
   
};
byte Face_1[] = {
  B00000000,
  B00100100,
  B01000000,
  B01000000,
  B01000000,
  B01000100,
  B00100000,
  B00000000
};
byte Face_2[] = {
  B00000000,
  B00000010,
  B00110000,
  B01001000,
  B01001010,
  B00110000,
  B00000000,
  B00000000
};

byte Face_3[] = {
  B00000000,
  B00000001,
  B00111000,
  B01000100,
  B01000100,
  B00111001,
  B00000000,
  B00000000
};

void setup() {
  SpeakerA.begin(3);
  SpeakerB.begin(4); 
  pinMode(Din, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(CLK, OUTPUT); 
  Setup_display_Reg();
  Display_Test(1);
  delay(1200);
  Display_Test(0);
  Set_decode_mode();
  Set_Scan();
  //Clear();
}

void loop() {
 Draw_Matrix(Face_1);
 delay(500);
 Play_6_8ths(Base1,Melody1,300);
 SpeakerA.stop();
 SpeakerB.stop();
 Draw_Matrix(Face_1);
 delay(5000);
 //SpeakerA.play(NOTE_G6);
}
void Play_6_8ths(int NotesB[],int NotesA[],int Length){
  int past_Note = 0;
  
for(int note = 0; note < Length; note++){
    if(NotesB[note] == 0){
      SpeakerB.stop();
    } else {
      SpeakerB.play(NotesB[note]);
    }

    if(NotesA[note] == 0){
      SpeakerA.stop();
      Draw_Matrix(Face_1);
    } else {
      Draw_Matrix(Face_2);
      if(past_Note == NotesA[note])
      Draw_Matrix(Face_2);
      else {
        Draw_Matrix(Face_3);
        past_Note = NotesA[note];
      }
      SpeakerA.play(NotesA[note]);
    }

    
    delay(190);
 }
}

void Draw_Matrix(byte Matrix[]) {
  for (byte column = 1; column <= 8; column++) {
    Write_to_MAX7221(column, Matrix[(column - 1)]);
  }
}

void Write_to_MAX7221(byte Address, byte Data) {
  digitalWrite(Din, LOW);
  digitalWrite(CS, LOW);
  digitalWrite(CLK, LOW);
  //the bits are received MSB first on the display but
  //bitread starts with LSB so Have to start at 8 and
  //count down to send the first 8 bits correctly
  for (int cycles = 7; cycles >= 0; cycles--) {
    //Set the value of DIN then send a clock plus for
    //that cycle to store that bit then move to next bit
    digitalWrite(Din, bitRead(Address, cycles));
    //Only reads On rising edge so we make sure we are low
    digitalWrite(CLK, LOW);
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
  // Same as with sending address bits but we have to pull
  //CS HIGH during or after the 16th clock pulse but before
  //the 17th clock pulse to load the data in regs.
  for (int cycles = 7; cycles >= 0; cycles--) {
    digitalWrite(Din, bitRead(Data, cycles));
    //Only reads On rising edge so we make sure we are low
    digitalWrite(CLK, LOW);
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
  digitalWrite(CS, HIGH);
}

void Setup_display_Reg() {
  byte Address = 0x0C;
  byte Data = 0x01;
  Write_to_MAX7221(Address, Data);
}

void Display_Test(byte Data) {
  byte Address = 0x0F;
  Write_to_MAX7221(Address, Data);
}

void Set_decode_mode() {
  byte Address = 0x09;
  byte Data = 0x00;
  Write_to_MAX7221(Address, Data);
}

void Set_Scan() {
  byte Address = 0x0B;
  byte Data = 0x07;
  Write_to_MAX7221(Address, Data);
}
