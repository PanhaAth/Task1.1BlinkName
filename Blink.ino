const int dotDuration = 200;
const int dashDuration = 600;
const int letterGap = 600;
const int wordGap = 1400;

const char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  blinkWord("Panha");
  delay(wordGap);
}

//The loop fucntion runs over and over again forever
void blinkWord(const String &word) {
  for (int i = 0; i < word.length(); i++){
     char ch = word.charAt(i);
    if (ch >= 'a' && ch <= 'z'){
      blinkLetter(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z'){
      blinkLetter(letters[ch - 'A']);
    }
    else if (ch == ' '){
      delay(wordGap);
    }
    delay(letterGap);
  }
}

void blinkLetter(const char* sequence) {
  for (int i = 0; sequence[i] != '\0'; i++) {
    if (sequence[i] == '.') {
      blinkDot();
    }
    else if (sequence[i] == '-') {
      blinkDash();
    }
    delay(dotDuration); // Gap between parts of the same letter
  }
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotDuration); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration); 
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);   
}
