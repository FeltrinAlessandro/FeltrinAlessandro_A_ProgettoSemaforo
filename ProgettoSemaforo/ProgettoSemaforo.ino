void setup() {
int rosso1 = 2;
int rosso2 = 4;
int verde1 = 7;
int verde2 = 8;
int giallo1 = 12;
int giallo2 = 13;
int durataSemaforo;
int durataGiallo;
int lampeggiVerde;
int intervalloLampeggi;
int durataSoloRosso;
int durataSoloVerde;
pinMode(rosso1,OUTPUT);
pinMode(rosso2,OUTPUT);
pinMode(verde1,OUTPUT);
pinMode(verde2,OUTPUT);
pinMode(giallo1,OUTPUT);
pinMode(giallo2,OUTPUT);
}

void lampeggiaVerde()
  {
    for(int i=0,i<lampeggiVerde,i++)
  {
    digitalWrite(verde1,LOW);
    delay intervalloLampeggi;
    digitalWrite(verde1,HIGH);
  }
    digitalWrite(led,LOW);
  }
  void metodo1()
  {
    digitalWrite(rosso2,HIGH);
    digitalWrite(verde1,HIGH);
    delay durataSoloVerde;
    lampeggiaVerde();
  }

void loop() {
  digitalWrite(verde1,HIGH)
  digitalWrite(giallo2,HIGH)
  delay 3000;
  digitalWrite(giallo2,LOW)
  digitalWrite(rosso2,HIGH)
  delay 7000;
}
