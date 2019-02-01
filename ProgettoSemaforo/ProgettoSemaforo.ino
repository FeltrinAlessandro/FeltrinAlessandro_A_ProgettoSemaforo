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
    digitalWrite(verde1,LOW);
  }
  void semaforoPrimaParte()
  {
    digitalWrite(rosso2,HIGH);
    digitalWrite(verde1,HIGH);
    delay durataSoloVerde;
    lampeggiaVerde();
  }
  void semaforoSecondaParte()
  {
    digitalWrite(giallo1,HIGH);
    digitalWrite(giallo2,HIGH);
    delay durataGiallo;
    digitalWrite(giallo1,LOW);
    digitalWrite(giallo2,LOW);
    digitalWrite(rosso2,LOW);
    digitalWrite(rosso1,HIGH);
    digitalWrite(verde1,HIGH);
  }

  void richiestaValori()
  {
    richiestaDurataSemaforo();
    richiestaDurataGiallo();
    richiestaNumeroLampeggi();
    trovaDurataSoloRosso();
    richiestaIntervalloLampeggi();
    trovaDurataSoloVerde();
  }

  void richiediDurataSemaforo()
  {
    print("quanto vuoi che duri il semaforo?(input in millisecondi)");
    while(Serial.available==0){};
    durataSemaforo = Serial.read().toInt();
  }

  void richiestaDurataGiallo()
  {
     bool finito = false;
    while(finito==false)
    {
      print("quanto vuoi che duri il giallo?(input in millisecondi)");
      while(Serial.available==0){};
      durataGiallo= Serial.read().toInt();
      if(durataGiallo<durataSemaforo)
      {
        finito = true;
      }
      else
      {
        print("valore dato non accettabile");
      }
    }
  }
  
  void richiestaNumeroLampeggi()
  {
    print("quante volte vuoi che lampeggi il verde?");
    while(Serial.available==0){};
    lampeggiVerde=Serial.read().toInt();
  }

  void trovaDurataSoloRosso()
  {
    durataSoloRosso=durataSemaforo-durataGiallo;
  }
  
  void richiestaIntervalloLampeggi()
  {
    bool finito = false;
    while(finito==false)
    {
      print("quanto vuoi che duri l'intervallo tra lampeggi?(input in millisecondi)")
      while(Serial.available==0){};
      intervalloLampeggi = Serial.read().toInt();
      if(intervalloLampeggi*lampeggiVerde<durataSoloRosso)
      {
        finito = true;
      }
      else
      {
        print("valore dato non accettabile");
      }
    }
  }

  void trovaDurataSoloVerde()
  {
    duraraSoloVerde=durataSoloRosso-intervalloLampeggi*lampeggiVerde;
  }
void loop() {
  digitalWrite(verde1,HIGH)
  digitalWrite(giallo2,HIGH)
  delay 3000;
  digitalWrite(giallo2,LOW)
  digitalWrite(rosso2,HIGH)
  delay 7000;
}
