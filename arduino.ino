int state = 0;

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);

  digitalWrite(7, HIGH); 
  digitalWrite(6, LOW);
}

void loop()
{
  int input2 = digitalRead(2);
  int input3 = digitalRead(3);
  int input4 = digitalRead(4);

  Serial.print("Input 2: ");
  Serial.print(input2);
  Serial.print(" Input 3: ");
  Serial.print(input3);
  Serial.print(" Input 4: ");
  Serial.println(input4);

  if (state == 0 && input2 == 1) {
    state = 1;
    Serial.println("Step 1: Input 2 correct");
  } 
  else if (state == 1 && input3 == 1) {
    state = 2;
    Serial.println("Step 2: Input 3 correct");
  }
  else if (state == 2 && input4 == 1) {
    state = 3;
    Serial.println("Step 3: Input 4 correct");
  }
  else if (state == 3 && input4 == 0) {
    state = 4;
    Serial.println("Step 4: Input 4 reset to 0");
  }
  else if (state == 4 && input3 == 0) {
    state = 5;
    Serial.println("Step 5: Input 3 reset to 0");
  }
  else if (state == 5 && input2 == 0) {
    state = 6;
    Serial.println("Step 6: Input 2 reset to 0");
  }

  if (state == 6) {
    digitalWrite(6, HIGH); 
    digitalWrite(7, LOW);
    Serial.println("Process Complete");
    if(input2 == 1||input3 == 1||input4 == 1) {
      state ==0;
    }

  } 
  else {
    digitalWrite(6, LOW); 
    digitalWrite(7, HIGH);
  }

  delay(500);
}
