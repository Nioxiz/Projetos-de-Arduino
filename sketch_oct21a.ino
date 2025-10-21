#include <Wire.h>
int letra[8,8,8,8,8];
const int MPU_ADDR = 0x68;
const int NUM_LEITURAS = 15;
float sensibilidadeX = 0.15;
float sensibilidadeY = 0.15;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  float somaX = 0, somaY = 0, somaZ = 0;
  
  for (int i = 0; i < NUM_LEITURAS; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 6, true);
    
    int16_t AcX = Wire.read() << 8 | Wire.read();
    int16_t AcY = Wire.read() << 8 | Wire.read();
    int16_t AcZ = Wire.read() << 8 | Wire.read();
    
    // Converte para g e acumula
    somaX += AcX / 16384.0;
    somaY += AcY / 16384.0;
    somaZ += AcZ / 16384.0;
    
    delay(5);
  }
  
  // Calcula médias em g
  float mediaX = somaX / NUM_LEITURAS;
  float mediaY = somaY / NUM_LEITURAS;
  float mediaZ = somaZ / NUM_LEITURAS;
  


  if(abs(mediaZ>1)){
    if(mediaX >= sensibilidadeX && mediaY >= sensibilidadeY){
      Serial.println(" diagonal ");
      for(int i=0;i<5;i++){
        if(letra[i]==8){
        letra[i]==2;
        break;
        }
      }
    }
    
    else if(mediaX < sensibilidadeX || mediaY<sensibilidadeY){  
      if (abs(mediaX) > sensibilidadeX) {
        Serial.println(" Vertical ");
        for(int i=0;i<5;i++){
          if(letra[i]==8){
          letra[i]==0;
          break;
      }
      }
      if (abs(mediaY) > sensibilidadeY) {
        Serial.println(" Horizontal ");
        for(int i=0;i<5;i++){
        if(letra[i]==8){
          letra[i]==1;
          break;
      }
      }
    }
    
  }
  delay(300);
}
void cria_letra(){
  
}