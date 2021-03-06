  int rosso1;
  int rosso2;
  int verde1;
  int verde2;
  int giallo1;
  int giallo2;
  int durataSemaforo;
  int durataGiallo;
  int lampeggiVerde;
  int intervalloLampeggi;
  int durataSoloRosso;
  int durataSoloVerde;

void setup() {
  rosso1 = 8;
  rosso2 = 5;
  verde1 = 10;
  verde2 = 7;
  giallo1 = 9;
  giallo2 = 6;

  pinMode(rosso1,OUTPUT);
  pinMode(rosso2,OUTPUT);
  pinMode(verde1,OUTPUT);
  pinMode(verde2,OUTPUT);
  pinMode(giallo1,OUTPUT);
  pinMode(giallo2,OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  richiestaValori();
  semaforoPrimaParte(rosso2, verde1);
  semaforoSecondaParte(verde2, rosso1, rosso2, giallo1, giallo2);
  semaforoPrimaParte(rosso1,verde2);
  semaforoSecondaParte(verde1, rosso2, rosso1, giallo2, giallo1); 
}

void lampeggiaVerde(int verde)//Questo metodo fa lampeggiare il verde
  {
    for(int i=0;i<lampeggiVerde;i++)
  {
    digitalWrite(verde,LOW);
    delay(intervalloLampeggi);
    digitalWrite(verde,HIGH);
    delay(intervalloLampeggi);
  }
    digitalWrite(verde,LOW);
  }
  void semaforoPrimaParte(int rosso_,int verde)//Questo metodo si occupa della prima parte del ciclo del semaforo(dall'inizio fino a quando il verde lampeggia)
  {
    digitalWrite(rosso_,HIGH);
    digitalWrite(verde,HIGH);
    delay(durataSoloVerde);
    lampeggiaVerde(verde);
  }
  void semaforoSecondaParte(int verde_, int rosso, int rosso_, int giallo, int giallo_)//Questo metodo si occupa della seconda parte del ciclo del semaforo(dall' accensione dei led gialli alla fine del ciclo)
  {
    digitalWrite(giallo,HIGH);
    digitalWrite(giallo_,HIGH);
    delay(durataGiallo);
    digitalWrite(giallo,LOW);
    digitalWrite(giallo_,LOW);
    digitalWrite(rosso_,LOW);
    digitalWrite(rosso,HIGH);
    digitalWrite(verde_,HIGH);
  }

  void richiestaValori()//Questo metodo serve per richiedere tutti i valori necessari al funzionamento del programma
  {
    richiestaDurataSemaforo();
    richiestaDurataGiallo();
    richiestaNumeroLampeggi();
    trovaDurataSoloRosso();
    richiestaIntervalloLampeggi();
    trovaDurataSoloVerde();
  }

  void richiestaDurataSemaforo()
  {
    Serial.println("quanto vuoi che duri il semaforo?(input in millisecondi)");
    while(Serial.available() == 0){};
    String inp = Serial.readString();
    durataSemaforo  = inp.toInt();
  }
  
  void richiestaNumeroLampeggi()
  {
    Serial.println("quante volte vuoi che lampeggi il verde?");
    while(Serial.available() == 0){};
    String inp = Serial.readString();
    lampeggiVerde = inp.toInt();

  }
  void richiestaDurataGiallo()
  {
     bool finito = false;
    while(!finito)
    {
      Serial.println("quanto vuoi che duri il giallo?(input in millisecondi)");
      while(Serial.available() == 0){};
      String inp = Serial.readString();
      durataGiallo  = inp.toInt();
      if(durataGiallo<durataSemaforo)
      {
        finito = true;
      }
      else
      {
        Serial.println("valore dato non accettabile");
      }
    }
  }
  


  void trovaDurataSoloRosso()
  {
    durataSoloRosso=durataSemaforo-durataGiallo;
  }
  
  void richiestaIntervalloLampeggi()
  {
    bool finito = false;
    while(!finito)
    {
      Serial.println("quanto vuoi che duri l'intervallo tra lampeggi?(input in millisecondi)");
      while(Serial.available() == 0){};
      String inp = Serial.readString();
      intervalloLampeggi = inp.toInt();
      if(intervalloLampeggi*lampeggiVerde<durataSoloRosso)
      {
        finito = true;
      }
      else
      {
        Serial.println("valore dato non accettabile");
      }
    }
  }

  void trovaDurataSoloVerde()
  {
    durataSoloVerde=durataSoloRosso-intervalloLampeggi*lampeggiVerde;
     intervalloLampeggi=intervalloLampeggi/2;
  }
