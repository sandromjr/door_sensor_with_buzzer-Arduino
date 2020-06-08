unsigned long millist1 = millis();
unsigned long millist2 = millis();
const int led1 = 13;
const int led2 = 12;
const int redled = 7;
const int greenled = 6;
const int switch1 = 9;
const int switch2 = 8;
const int buzz = 2;
const int button = 0;
int status1 = 0;
int status2 = 0;
int statusbutton = 0;

void setup() {

    pinMode(led1, OUTPUT);
    pinMode(but1, INPUT);
    
}

void loop() {
  
    statusbutton = digitalRead(button);

    if (statusbutton == HIGH){
        digitalWrite(greenled,HIGH);
        digitalWrite(redled,LOW);
        door1();
        door2();
    }
    else {
        digitalWrite(redled,HIGH);
        digitalWrite(greenled,LOW);
    }
}

void door1() {
  
    status1 = digitalRead(switch1);

    if (status1 == LOW) {
        digitalWrite(led1,HIGH);
        if ((millis() - millist1) > 120000) {
            tone(buzz,5000, 100);
            delay(300);
            tone(buzz,5000, 100);
            millist1 = millis();
            }
    }
    else {
        digitalWrite(led1, LOW);
        millist1 = millis();
    }
    
}

void door2() {
  
    status2 = digitalRead(switch2);

    if (status2 == LOW) {
        digitalWrite(led2,HIGH);
        if ((millis() - millist2) > 120000) {
            tone(buzz,5000, 100);
            delay(300);
            tone(buzz,5000, 100);
            millist2 = millis();
            }
    }
    else {
        digitalWrite(led2, LOW);
        millist2 = millis();
    }
}
    
