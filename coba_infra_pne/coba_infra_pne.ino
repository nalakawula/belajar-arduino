#define cock  27
#define servis  29
#define infra 52

int led = 13;
char sendBT;

void setup() {
  Serial3.begin(9600);
  Serial3.println("Coba Fix Service");

  pinMode(cock,OUTPUT);
  pinMode(servis,OUTPUT);
  pinMode(infra,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}

void loop() {
  if (Serial3.available()){

    sendBT=Serial3.read();
    if(sendBT== 'o'){
      Serial3.println("data : servis infrared");
      servis();
    }
  }
}

void servis(){
  Serial3.println("data : servis \t");
  digitalWrite(servis,LOW);
  digitalWrite(cock,HIGH);
  digitalWrite(led,HIGH);
  digitalWrite(servis,HIGH);
}

