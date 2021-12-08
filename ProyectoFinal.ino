int pinAplus = 8;
int pinBplus = 9;
int pinAmin = 10;
int pinBmin = 11;

int trig = 6;
int echo = 7;

int led = 4;
int ledStop = 12;
int bocina = 13;

int rotorAplus = 0;
int rotorBplus = 1;
int rotorAmin = 2;
int rotorBmin = 3;

int flag = 0;
int flag2 = 0;
int atorado = 0;
int lastStep;

void setup() {
  pinMode(pinAplus, OUTPUT);
  pinMode(pinBplus, OUTPUT);
  pinMode(pinAmin, OUTPUT);
  pinMode(pinBmin, OUTPUT);

  pinMode(rotorAplus, OUTPUT);
  pinMode(rotorBplus, OUTPUT);
  pinMode(rotorAmin, OUTPUT);
  pinMode(rotorBmin, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(bocina, OUTPUT);
  
  pinMode(led, OUTPUT);
  pinMode(ledStop, OUTPUT);
}

void loop() {
  float distancia = sensor();
  
  if(distancia < 15){

    if(atorado >= 4){
      for(int alarma = 0;alarma < 5; alarma++){
        digitalWrite(ledStop,HIGH);
        tone(bocina ,5919.9108);
        delay(500);
        noTone(bocina);
        digitalWrite(ledStop,LOW);
        delay(500);
      }
    }
    
    flag++;
    if(flag%2 != 0){
      cambioDireccion();  
      flag2 = 1;
    }else {
      cambioDireccion1();
      flag2 = 2;
    }

    delay(1000);
    corrimiento1();
    delay(500);
    corrimiento2();
    delay(500);
    corrimiento3();
    delay(500);
    corrimiento4();

    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
    distancia = sensor();
    delay(2000);
    atorado++;
  }else{
    atorado = 0;
    if(flag2 == 1){
      forward();  
    }else if(flag2 == 2) {
      forward1();
    }
    corrimiento1();
    delay(500);
    corrimiento2();
    delay(500);
    corrimiento3();
    delay(500);
    corrimiento4();
    delay(500);
  }
 
}

float sensor(){
  digitalWrite(trig, HIGH),
  delay(1);
  digitalWrite(trig, LOW);
  int duracion = pulseIn(echo, HIGH);
  //Distancia en CM
  float distancia = duracion / 58.2;

  return distancia;
}

int corrimiento1(){
  digitalWrite(pinAplus, HIGH);
  digitalWrite(pinBplus, LOW);
  digitalWrite(pinAmin, LOW);
  digitalWrite(pinBmin, LOW);
  return 1;
}

int corrimiento2(){
  digitalWrite(pinAplus, LOW);
  digitalWrite(pinBplus, HIGH);
  digitalWrite(pinAmin, LOW);
  digitalWrite(pinBmin, LOW);
  return 2;
}

int corrimiento3(){
  digitalWrite(pinAplus, LOW);
  digitalWrite(pinBplus, LOW);
  digitalWrite(pinAmin, HIGH);
  digitalWrite(pinBmin, LOW);
  return 3;
}

int corrimiento4(){
  digitalWrite(pinAplus, LOW);
  digitalWrite(pinBplus, LOW);
  digitalWrite(pinAmin, LOW);
  digitalWrite(pinBmin, HIGH);
  return 4;
}

void cambioDireccion(){
  digitalWrite(rotorAplus, HIGH);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, LOW);

  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, HIGH);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, LOW);
}

void cambioDireccion1(){
  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, HIGH);
  digitalWrite(rotorBmin, LOW);

  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, HIGH);
}



void forward(){
  digitalWrite(rotorAplus, HIGH);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, LOW);

  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, HIGH);
}

void forward1(){
  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, HIGH);
  digitalWrite(rotorAmin, LOW);
  digitalWrite(rotorBmin, LOW);

  digitalWrite(rotorAplus, LOW);
  digitalWrite(rotorBplus, LOW);
  digitalWrite(rotorAmin, HIGH);
  digitalWrite(rotorBmin, LOW);
}
