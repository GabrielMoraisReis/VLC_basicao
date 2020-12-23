#define length 8

int byt = 0;
const int LDR = 0;
int ldrValue[10];   //Stores the LDR value
int byteValue = 0;
int value, average, lastValue = 0;
boolean flag = false;
int bin[length];    //stores data in binary
int ascii = 0;      //Stores data in ascii
char character;     //Stores data in characters
int i = 0;

void read();
void converter();

void setup() 
{
  Serial.begin(9600);
  Serial.print("Pronto");
  delay(4500);
}// end setup

void loop() 
{
  start:
    for(i=0;i<length;i++)// read data
    {
      read();
      bin[i] = byt;
      Serial.print(bin[i]);
      delay(4500);
    }
    Serial.print(" \n"); 
    converter();
}// end loop

void read()
{
  
  byteValue = analogRead(A0);
  float voltage = byteValue * (5.0 / 1023.0);

  if(voltage == 0)
    byt = 0;

  
  if(voltage > 0)
    byt = 1;
    

 
 //Serial.print("byt:");
 //Serial.println(byt);
 //Serial.print("byteValue: ");
 //Serial.println(byteValue);

}// end read

void converter()
{
  ascii += bin[7] * 1;
  ascii += bin[6] * (2);
  ascii += bin[5] * (2*2);
  ascii += bin[4] * (2*2*2);
  ascii += bin[3] * (2*2*2*2);
  ascii += bin[2] * (2*2*2*2*2);
  ascii += bin[1] * (2*2*2*2*2*2);
  ascii += bin[0] * (2*2*2*2*2*2*2);
  Serial.print(" ascii: ");
  Serial.print(ascii);
  //Serial.print("\n");
  character = (char) ascii;
  Serial.print(" Character: ");
  Serial.print(character);
  Serial.print("\n");
  ascii = 0;
}
