const int green_led = D1;
const int yellow_led = D2;
const int red_led = D3;

const int pedestrian_led = D0;

const int button_reset = D5;
const int button_stop = D6;

int i;

void setup() {
  Serial.begin(115200);
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);

  pinMode(pedestrian_led, OUTPUT);

  pinMode(button_reset, INPUT);
  pinMode(button_stop, INPUT);

  i = 0;
}

void loop() {
  i++;

  if ( digitalRead(button_reset) == 1 )
  {
    Serial.print("Button reset : ");
    Serial.println(digitalRead(button_reset));
    i = 0;
  }
  else
  {
    Serial.print("Button reset : ");
    Serial.println(digitalRead(button_reset));
  }

  if (digitalRead(button_stop) == 0 )
  {
    Serial.print("Button stop : ");
    Serial.println(digitalRead(button_stop));

    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(pedestrian_led, HIGH);

    i = 1;
  }
  else
  {
    Serial.print("Button stop : ");
    Serial.println(digitalRead(button_stop));
  }

  if( i == 1 )
  {
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(pedestrian_led, HIGH);

    delay(1000);
  }
  else if( i == 2 )
  {
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
    digitalWrite(pedestrian_led, LOW);

    delay(1000);
  }
  else if( i == 3 )
  {
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(pedestrian_led, LOW);

    delay(1000);
    i = 0;
  }
  delay(100);
}
