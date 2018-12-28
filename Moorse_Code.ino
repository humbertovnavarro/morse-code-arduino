//Sets the time for one unit in milliseconds. Higher values = faster signaling. Lower values = slower signaling.
int unitInterval = 100;
String sentence = "";
int pin = LED_BUILTIN;
//Listens through the serial monitor for input.
//You may set sentence to whatever you're trying to broadcast instead
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
char input = '%';
void setup() {
  
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}
void unit(){
  delay(unitInterval);
}
void dot(){
  digitalWrite(pin, HIGH);
  delay(unitInterval);
  digitalWrite(pin, LOW);
  unit();
}
void dash(){
  digitalWrite(pin, HIGH);
  delay(unitInterval * 3);
  digitalWrite(pin, LOW);
  unit();
}
void wordspace(){
  delay(unitInterval * 7);
}
void loop() {
  bool valid = true;
  /*Wait for input & basic input validation.*/
  while(input != '\n'){
      if(Serial.available() > 0){
        input = char(Serial.read());
        //If it is a number
        if(input >= 65 && input <= 90){
          sentence+=input; 
        }
        //or if it is a upper or lowercase letter
        else if( (input >= 48 && input <= 57) || (input >= 97 && input <= 122) ){
          sentence+=input; 
        }
        //or if it is a space
        else if(input == 32){
          sentence+=input; 
        }
        else if(input > 32){
          Serial.print("\n");
          Serial.write(input);
          Serial.print(" is not a valid character!");
          Serial.print("\n");
          valid = false;
        }
      }
   }
   if(valid){
     sentence.toUpperCase();
     //Iterate through the string and blink the corresponding moorse code sequence
     Serial.write("\n");
     Serial.write("output: ");
     for (int i = 0; i < sentence.length(); i++)
    {
      Serial.print(sentence[i]);   // Print your message as it is fed to the translator
    }
     for(int i = 0; i < sentence.length(); i++){
        convert(sentence.charAt(i));
     }
     Serial.print("\n");
     Serial.write("\n Done!");
     Serial.print("\n");
   }
   else
   {
     Serial.write("Finished with error: Invalid chars.");
   }
   //Reset vars
    input = '%';
    sentence = "";
}
//The legwork!
void convert(char in){
  switch(in){
    case 'A' :
    dot();
    dash();
    break;
    case 'B' :
    dash();
    dot();
    dot();
    dot();
    break;
    case 'C' :
    dash();
    dot();
    dash();
    dot();
    break;
    case 'D' :
    dash();
    dot();
    dot();
    break;
    case 'E' :
    dot();
    break;
    case 'F' :
    dot();
    dot();
    dash();
    dot();
    break;
    case 'G' :
    dash();
    dash();
    dot();
    break;
    case 'H' :
    dot();
    dot();
    dot();
    dot();
    break;
    case 'I' :
    dot(); 
    dot();
    break;
    case 'J' :
    dot(); 
    dash();
    dash();    
    dash();
    break;
    case 'K' :
    dash();
    dot();
    dash();
    break;
    case 'L' :
    dot();
    dash();
    dot();
    dot();
    break; 
    case 'M' :
    dash();
    dash();
    break;
    case 'N' :
    dash();
    dot();
    break;
    case 'O' :
    dash();
    dash();
    dash();
    break;
    case 'P' :
    dot();
    dash();
    dash();
    dot();
    break;
    case 'Q' :
    dash();
    dash();
    dot();
    dash();
    break; 
    case 'R' :
    dot();
    dash();
    dot();
    break;
    case 'S' :
    dot();
    dot();
    dot();
    break;
    case 'T' :
    dash();
    break;
    case 'U' :
    dot();
    dot();
    dash();
    break;
    case 'V' :
    dot();
    dot();
    dash();
    break;
    case 'W' :
    dot();
    dash();
    dash();
    break;
    case 'X' :
    dash();
    dot();
    dot();
    dash();
    break;
    case 'Y' :
    dash();
    dot();
    dash();
    dash();
    break;
    case 'Z' :
    dash();
    dash();
    dot();
    dot();
    break;
    case '1' :
    dot();
    dash();
    dash();
    dash();
    dash();
    break;
    case '2' :
    dot();
    dot();
    dash();
    dash();
    dash();
    break;
    case '3' :
    dot();
    dot();
    dot();
    dash();
    dash();
    break;
    case '4' :
    dot();
    dot();
    dot();
    dot();
    dash();
    break;
    case '5' :
    dot();
    dot();
    dot();
    dot();
    dot();
    break;
    case '6' :
    dash();
    dot();
    dot();
    dot();
    dot();
    break;
    case '7' :
    dash();
    dash();
    dot();
    dot();
    dot();
    break;
    case '8' :
    dash();
    dash();
    dash();
    dot();
    dot();
    break;
    case '9' :
    dash();
    dash();
    dash();
    dash();
    dot();
    break;
    case '0' :
    dash();
    dash();
    dash();
    dash();
    dash();
    break;
    case 32 :
      wordspace();
    break;
  }
  /*Only if input char isn't a space! (ascii dec 32*/
  if(in != 32){
    /*Since the space beetween letters is three units, and the dash
     * and dot methods both have a unit of space at the end of them, (because i'm lazy.)
     * we must only pause for two units here instead of writing in the pauses manually. 
     */
    unit();
    unit();
  }
}
