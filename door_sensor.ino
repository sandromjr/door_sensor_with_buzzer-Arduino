unsigned long millist1 = millis();
unsigned long millist2 = millis();
const int led1 = 13; //Left door led
const int led2 = 12; //Right door led
const int redled = 7; //Indicator if button is OFF
const int greenled = 6; //Indicator if button is ON
const int switch1 = 9; //Left door reed switch
const int switch2 = 8; //Right door reed switch
const int buzz = 2;
const int button = 0; //ON/OFF switch button
int status1 = 0;
int status2 = 0;
int statusbutton = 0;

void setup() {
//Define inputs and output pins
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(redled, OUTPUT);
    pinMode(switch1, INPUT);
    pinMode(switch2, INPUT);
    pinMode(button, INPUT);
    
}

void loop() {
//Read logic signal in 0
  
    statusbutton = digitalRead(button);
    
//If button is pressed (ON), turn off red indicator, turn on green indicador and call both functions

    if (statusbutton == HIGH){
        digitalWrite(greenled,HIGH);
        digitalWrite(redled,LOW);
        door1();
        door2();
    }

//If button pressed is OFF, turn off green led and turn on red led
    else {
        digitalWrite(redled,HIGH);
        digitalWrite(greenled,LOW);
    }
}

void door1() {
//Verify if door is opened (megnet isn't close to the reed switch, that indicates LOW logical signal in 9)
    
    status1 = digitalRead(switch1);

    if (status1 == LOW) {
        digitalWrite(led1,HIGH); //Left led is turned on
        if ((millis() - millist1) > 120000) {
//If the left door is opened for more than 2 minutes, the buzzer will bip
            
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
//Verify if door is opened (megnet isn't close to the reed switch, that indicates LOW logical signal in 8)
  
    status2 = digitalRead(switch2);

    if (status2 == LOW) {
        digitalWrite(led2,HIGH); //Right led is turned on
        if ((millis() - millist2) > 120000) {
//If the right door is opened for more than 2 minutes, the buzzer will bip
            
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
    
