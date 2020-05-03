int Din = 27;
int CS = 25;
int CLK = 23;

int xPin = A0;
int yPin = A1;

int swPin = A2;
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))
byte Display_matrix[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
byte Display_matrixA_1[] = {
  B00000000,
  B00110111,
  B01000111,
  B01000000,
  B01000000,
  B01000111,
  B00110111,
  B00000000
};

byte Display_matrixB[] = {
  B00000000,
  B00010111,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B00010111,
  B00000000
};

byte Display_matrixC[] = {
  B00001010,
  B01100101,
  B11100100,
  B11100000,
  B11100000,
  B11100100,
  B01100101,
  B00001010
};

byte Display_matrixD[] = {
  B00100010,
  B00010100,
  B10001000,
  B10000000,
  B10000000,
  B10001000,
  B00010100,
  B00100010
};

byte Display_matrixE[] = {
  B00000000,
  B00100000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B00100000,
  B00000000
};

byte Display_matrixF[] = {
  B00000000,
  B00000000,
  B00110000,
  B01001000,
  B01001000,
  B00110000,
  B00000000,
  B00000000
};
byte Scroll_matrix1[] = {
  B00000000,
  B01111110,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01111110,
  B00000000,

  B00000000,
  B00000000,
  B01111000,
  B10000000,
  B01100000,
  B10000000,
  B01111000,
  B00000000,

  B00000000,
  B01111110,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01111110,
  B00000000
};

byte Scroll_matrix2[] = {
  B00000000,
  B01111110,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B01111110,
  B00000000,

  B00000000,
  B00000000,
  B01111000,
  B10000000,
  B01100000,
  B10000000,
  B01111000,
  B00000000,

  B00000000,
  B01111110,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B01111110,
  B00000000
};

byte Scroll_matrix3[] = {
  B00000000,
  B01111110,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B01111110,
  B00000000,

  B01000000,
  B10000000,
  B01000000,
  B10000000,
  B01000000,
  B10000000,
  B01000000,
  B10000000,

  B00000000,
  B01111110,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B01111110,
  B00000000
};
void setup() {
  pinMode(13, OUTPUT);
  pinMode(Din, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.begin(9600);
  pinMode(swPin, INPUT);

  Setup_display_Reg();
  Display_Test(1);
  delay(1200);
  Display_Test(0);
  Set_decode_mode();
  Set_Scan();
  Clear();
}

void loop() {
  digitalWrite(13, HIGH);
  int x_analog = analogRead(xPin);
  int y_analog = analogRead(yPin);
  int sw = analogRead(swPin);
  Serial.print(x_analog);
  Serial.print(' ');
  Serial.print(y_analog);
  Serial.print(' ');
  byte x_cord =  map(x_analog, 10, 1000, 0, 3);
  byte y_cord =  map(y_analog, 0, 1000, 4, 1);

  byte LEYE1x = x_cord;
  byte LEYE1y = y_cord;
  byte LEYE2x = x_cord +1;
  byte LEYE2y = y_cord;

  byte LEYE3x = x_cord;
  byte LEYE3y = y_cord +4;
  byte LEYE4x = x_cord +1;
  byte LEYE4y = y_cord +4;

  Draw_Pixel(LEYE1x, LEYE1y);
  Draw_Pixel(LEYE2x, LEYE2y);
  Draw_Pixel(LEYE3x, LEYE3y);
  Draw_Pixel(LEYE4x, LEYE4y);
  
  Serial.print(x_cord);
  Serial.print(' ');
  Serial.print(y_cord);
  Serial.print(' ');
  Serial.println(sw);
  if(sw < 25){
  Draw_Matrix(Display_matrixF);
  } else {
    Draw_Matrix(Display_matrixE);
  }
  delay(10);
  Clear();
  digitalWrite(13, LOW);
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

void Draw_Matrix(byte Matrix[]) {
  for (byte column = 1; column <= 8; column++) {
    Write_to_MAX7221(column, Matrix[(column - 1)]);
  }
}

void Scroll_Matrix(byte Input[], int Scroll_length) {
  byte current_display[] = {
    B00000000,
    B00110111,
    B01000111,
    B01000000,
    B01000000,
    B01000111,
    B00110111,
    B00000000
  };
  for (byte index = 0; index < (Scroll_length - 8 ); index++) {
    for (byte column = 0; column < 8; column++) {
      current_display[column] = Input[column + index];
    }
    delay(100);
    Draw_Matrix(current_display);

  }

}

void Clear() {
  for (byte Address = 1; Address <= 8; Address++) {
    Write_to_MAX7221(Address, 0x00);
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

void Draw_Pixel(byte x, byte y) {
  byte address = y;
  byte data = 0x01;
  data = data << x;
  Write_to_MAX7221(address, data);
}
