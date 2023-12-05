#include <Servo.h>

Servo s1,s2,s3,s4;

int i, j, k;

void setup()
{
  Serial.begin(115200);

  s1.attach(3, 0, 180);
  s2.attach(5, 0, 180);
  s3.attach(6, 0, 180);
  s4.attach(9, 0, 180);

  home();
}

void loop()
{
//condição caso sistema de visão visualize o cilindro
  if (Serial.available() > 0)
  {
    String byteRead = Serial.readString();
    Serial.println(byteRead); 

    if(Serial.find("cilindro"))
     {
      home();
      delay(300);

      pick();
      delay(300);

      placeCilindro();
      delay(300);

      home();
      delay(300);
     }
  
//condição caso sistema de visão visualize a piramide
     if(Serial.find("piramide"))
     
     {
      home();
      delay(300);

      pick();
      delay(300);

      placePiramide();
      delay(300);
      
      home();
      delay(300);
    }
  }   
}

void home()
{
  s1.write(100);
  s2.write(100);
  s3.write(60);
  s4.write(0); // garra aberta
  delay(500);
}

void pick()
{
// Garante que o robô está em ponto de home com a garra aberta
  s1.write(100);
  s2.write(100);
  s3.write(60);
  s4.write(0); // garra aberta
  delay(500);

  for (k = 60; k <=130; k++)
  {
    s3.write(k);
    delay(20);
  }
  delay(500);

// fecha a garra no ponto de pega
  s4.write(110); // garra fechada
  delay(1000);

 // retorna o eixo 3 para seguir para o ponto de depósito 
  for (k = 130; k >=60; k--)
  {
    s3.write(k);
    delay(20);
  }
  delay(1000);
}

void placeCilindro()
{
// Gira a base do robô para o ponto de depósito do cilindro
  for (i = 100 ; i >= 55; i--)
  {
    s1.write(i);
     delay(5);
  }
  delay(500);

// Avança o eixo 3 para ponto próximo do depósito do cilindro
  for (k = 60; k <=80; k++)
  {
    s3.write(k);
    delay(20);
  }
  delay(500);

// abre a garra para depositar o cilindro
  s4.write(0); // garra aberta
  delay(750);

// se move do ponto de deposito do cilindro até o ponto de home
  for (k = 80; k >=60; k--)
  {
    s3.write(k);
    delay(20);
  }
  delay(500);
  for (i = 55 ; i <= 100; i++)
  {
    s1.write(i);
     delay(5);
  }
  delay(500);

  s1.write(100);
  s2.write(100);
  s3.write(60);
  s4.write(0); // garra aberta
  delay(500);
}

void placePiramide()
{
// Gira a base do robô para o ponto de depósito do cilindro
  for (i = 100 ; i <= 145; i++)
  {
    s1.write(i);
     delay(5);
  }
  delay(500);

// Avança o eixo 3 para ponto próximo do depósito do cilindro
  for (k = 60; k <=80; k++)
  {
    s3.write(k);
    delay(20);
  }
  delay(500);

// abre a garra para depositar o cilindro
  s4.write(0); // garra aberta
  delay(750);

// se move do ponto de deposito do cilindro até o ponto de home
  for (k = 80; k >=60; k--)
  {
    s3.write(k);
    delay(20);
  }
  delay(500);
  for (i = 145 ; i >= 100; i--)
  {
    s1.write(i);
     delay(5);
  }
  delay(500);

  s1.write(100);
  s2.write(100);
  s3.write(60);
  s4.write(0); // garra aberta
  delay(500);
}