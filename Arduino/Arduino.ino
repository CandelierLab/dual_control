/*
 *  ____  _   _   _    _     
 * |  _ \| | | | / \  | |    
 * | | | | | | |/ _ \ | |    
 * | |_| | |_| / ___ \| |___ 
 * |____/ \___/_/   \_\_____|
 *
 * For Arduino nano on electronics v2.1.1
 * raphael.candelier@upmc.fr
 * 
 *  ---
 * Commands:
 * 
 *  getId
 *  getInfo
 *  setVal:pin:val
 *  blink:ON/OFF
 *  blinkPeriod:period
 *  light:VIS/IR:ON/OFF
 *  run
 *  stop
 *  stepPeriod:period
 *  state:Active/Idle/Xmas/K2000
 */

// === DEFINITIONS ===============================================

const int id = 2;

// --- Motor
const int pMS1 = 2;
const int pMS2 = 3;
const int pMS3 = 4;
const int p_EN  = 5;
const int pDIR = 6;
const int pSTP = 7;

// --- Switches
const int pBOT = 8;
const int pTOP = 9;

// --- Lights
const int pVIS = 10;
const int p_IR = 11;
const int pP_V = 20;  // A6
const int pP_I = 21;  // A7

// --- Valves
const int puV1 = 14;  // A0
const int puV2 = 15;  // A1
const int puV3 = 16;  // A2
const int puV4 = 17;  // A3
const int puV5 = 18;  // A4
const int puV6 = 19;  // A5

// --- Variables

bool bVIS = false;
bool b_IR = false;
const int bSize = 100;
float VIS[bSize];
float IR[bSize];
int iVIS = 0;
int i_IR = 0;

// --- States

String state = "Idle";        // Active, Idle, Xmas, K2000

bool bBlink;
long int blinkPeriod = 100;   // Blink period, in ms

bool isRunning = false;
long int stepPeriod = 1250;   // Step period, in µs

long int tRef = 0;
int brightness = 0;
int fadeAmount = 5;
int K = 0;

// === SETUP =====================================================

void setup() {                

  // --- Serial communication  
  Serial.begin(115200);
  Serial.setTimeout(5);

  // --- Modes

  // Motor
  pinMode(pMS1, OUTPUT);
  pinMode(pMS2, OUTPUT);
  pinMode(pMS3, OUTPUT);
  pinMode(p_EN, OUTPUT);
  pinMode(pDIR, OUTPUT);
  pinMode(pSTP, OUTPUT);

  // Switches
  pinMode(pBOT, INPUT_PULLUP);
  pinMode(pTOP, INPUT_PULLUP);

  // Lights
  pinMode(pVIS, OUTPUT);
  pinMode(p_IR, OUTPUT);
  pinMode(pP_V, INPUT);
  pinMode(pP_I, INPUT);

  // Valves
  pinMode(puV1, OUTPUT);
  pinMode(puV2, OUTPUT);
  pinMode(puV3, OUTPUT);
  pinMode(puV4, OUTPUT);
  pinMode(puV5, OUTPUT);
  pinMode(puV6, OUTPUT);

  // --- Default states

  // Motor
  digitalWrite(pMS1, LOW);
  digitalWrite(pMS2, LOW);
  digitalWrite(pMS3, LOW);
  digitalWrite(p_EN, LOW);
  digitalWrite(pDIR, LOW);
  digitalWrite(pSTP, LOW);
  
  // Lights
  digitalWrite(pVIS, LOW);
  digitalWrite(p_IR, LOW);

  // Valves
  digitalWrite(puV1, LOW);
  digitalWrite(puV2, LOW);
  digitalWrite(puV3, LOW);
  digitalWrite(puV4, LOW);
  digitalWrite(puV5, LOW);
  digitalWrite(puV6, LOW);
  
}

// === LOOP ======================================================

void loop() {

  // === Manage inputs ===========================================

  if (Serial.available()) {   

    // Get serial command string
    String input = Serial.readString();
    input.trim();

    // Split serial command
    char arg1[32]={}, arg2[16]={}, arg3[16]={};
    for (int i=0, p1=0, p2=0, p3=0, c=1; i<input.length(); i++) { 
      if (input.charAt(i)== ':') { 
        c++; 
        continue; 
      }
      switch (c) {
      case 1: 
        arg1[p1++] = input.charAt(i); 
        break;
      case 2: 
        arg2[p2++] = input.charAt(i); 
        break;
      case 3: 
        arg3[p3++] = input.charAt(i); 
        break;
      }
    }

    String cmd(arg1);
    String key(arg2);
    String val(arg3);

    /*
    // --- DEBUG ---
     Serial.println("Command (" + String(cmd.length()) + "): " + cmd);
     Serial.println("Key (" + String(key.length()) + "):     " + key);
     Serial.println("Value (" + String(val.length()) + "):   " + val);
     // -------------
    /**/

    // --- IDENTIFIER ---------------------------------------
    if (cmd.equals("getId")) {

      Serial.println(String(id));

      // --- INFORMATION --------------------------------------
      
    } else if (cmd.equals("getInfo")) {

      Serial.println(F("----------------------------"));
      Serial.println("Dual #" + String(id));
      Serial.println("State: " + state);
      Serial.println("Blink period: " + String(blinkPeriod) + "ms");
      Serial.println("Steps period: " + String(stepPeriod) + "us");
      Serial.println(F("----------------------------"));

      // --- SET VALUE --------------------------------------
      
    } else if (cmd.equals("setVal")) {

      digitalWrite(key.toInt(), val.equals("ON")? HIGH : LOW);

      // --- BLINK ------------------------------------------
      
    } else if (cmd.equals("blink")) {

      if (key=="ON") { 
        bBlink = true; 
        tRef = millis(); 
      }
      if (key=="OFF") { 
        bBlink = false; 
        digitalWrite(puV1, LOW);
        digitalWrite(puV2, LOW);
        digitalWrite(puV3, LOW);
        digitalWrite(puV4, LOW);
        digitalWrite(puV5, LOW);
        digitalWrite(puV6, LOW);
      }

      // --- BLINK PERIOD -------------------------------------
      
    } else if (cmd.equals("blinkPeriod")) {

      blinkPeriod = key.toInt();
      Serial.println("Blink period set to " + key + "ms");

      // --- STEP PERIOD --------------------------------------
      
    } else if (cmd.equals("stepPeriod")) {

      stepPeriod = key.toInt();
      Serial.println("Step period set to " + key + "us");

      // --- RUN ----------------------------------------------
      
    }  else if (cmd.equals("run")) {

      isRunning = true;
      Serial.println("Running");

      // --- STOP ---------------------------------------------
      
    } else if (cmd.equals("stop")) {

      isRunning = false;
      Serial.println("Stopped (by command)");

      // --- LIGHT --------------------------------------------
      
    } else if (cmd.equals("light")) {
      
      if (key.equals("VIS")) { bVIS = val.equals("ON"); }
      if (!bVIS) { analogWrite(pVIS, 0); }
      
      if (key.equals("IR")) { b_IR = val.equals("ON"); }
      if (!b_IR) { analogWrite(p_IR, 0); }

    // --- STATE --------------------------------------------
      
    } else if (cmd.equals("state")) {
      
      state = key;
      tRef = millis();
      
      if (state=="Active") {
         digitalWrite(puV1, LOW);
         digitalWrite(puV2, LOW);
         digitalWrite(puV3, LOW);
         digitalWrite(puV4, LOW);
         digitalWrite(puV5, LOW);
         digitalWrite(puV6, LOW);
         digitalWrite(pVIS, LOW);
         digitalWrite(p_IR, LOW);
         digitalWrite(pDIR, LOW);
         digitalWrite(pSTP, LOW);
      }

      if (state=="Idle") {
         brightness = 0;
         digitalWrite(puV1, LOW);
         digitalWrite(puV2, LOW);
         digitalWrite(puV3, LOW);
         digitalWrite(puV4, LOW);
         digitalWrite(puV5, LOW);
         digitalWrite(puV6, LOW);
         digitalWrite(pVIS, LOW);
         digitalWrite(p_IR, LOW);
         digitalWrite(pSTP, LOW);
      }

      if (state=="K2000") {
         K = 0;
         digitalWrite(puV1, HIGH);
         digitalWrite(puV2, LOW);
         digitalWrite(puV3, LOW);
         digitalWrite(puV4, LOW);
         digitalWrite(puV5, LOW);
         digitalWrite(puV6, LOW);
         digitalWrite(pVIS, LOW);
         digitalWrite(p_IR, LOW);
         digitalWrite(pDIR, LOW);
      }

    }

    // Flush output
    Serial.flush();

  }

  // === Actions =================================================

  // --- Light -------------------------------------------------
  
  if (bVIS) {
    
    VIS[iVIS] = float(analogRead(pP_V)-50)*255/850;
    iVIS++;
    
    if (iVIS==bSize) {
      float M = 0;
      for (int i=0 ; i<bSize ; i++) { M += VIS[i]; }
      M /= bSize;
      if (M<0) { M = 0; }
      if (M>255) { M = 255; }
      analogWrite(pVIS, M);
      iVIS = 0;
    }

  }

  if (b_IR) {
    
    IR[i_IR] = float(analogRead(pP_I)-50)*255/850;
    i_IR++;
    
    if (i_IR==bSize) {
      float M = 0;
      for (int i=0 ; i<bSize ; i++) { M += IR[i]; }
      M /= bSize;
      if (M<0) { M = 0; }
      if (M>255) { M = 255; }
      analogWrite(p_IR, M);
      i_IR = 0;
    }
  }

  // --- Blinking ----------------------------------------------

  if (bBlink && millis() > tRef+blinkPeriod) {

    digitalWrite(puV1, !digitalRead(puV1));    
    digitalWrite(puV2, !digitalRead(puV2));    
    digitalWrite(puV3, !digitalRead(puV3));    
    digitalWrite(puV4, !digitalRead(puV4));    
    digitalWrite(puV5, !digitalRead(puV5));    
    digitalWrite(puV6, !digitalRead(puV6));    
    
    tRef = millis();  
  }

  // --- Motor -------------------------------------------------

  if (isRunning) {
    
    // --- Checks

    if (digitalRead(pTOP)==LOW & digitalRead(pDIR)==HIGH) {
      isRunning = false;
      Serial.println("[STOP]");
      Serial.println("Stopped (by top switch)");
      return;
    }

    if (digitalRead(pBOT)==LOW & digitalRead(pDIR)==LOW) { 
      isRunning = false;
      Serial.println("[STOP]");
      Serial.println("Stopped (by bottom switch)");
      return;
    }

    digitalWrite(pSTP, HIGH); 
    delayMicroseconds(stepPeriod/2);

    digitalWrite(pSTP, LOW);
    delayMicroseconds(stepPeriod/2);

  }

  // --- Idle state --------------------------------------------
  
  if (state=="Idle" && millis() > tRef+20) {
    
    brightness += fadeAmount;

    if (brightness<=0 ) {
      brightness = 0;
      fadeAmount = -fadeAmount;
    }
    if (brightness>=255) { 
      brightness = 255;
      fadeAmount = -fadeAmount; 
    }
    
    analogWrite(pDIR, brightness);
    tRef = millis();
    
  }

  if (state=="Xmas") {

   int X = random(5000);
   if (X==1) { digitalWrite(puV1, !digitalRead(puV1)); }
   if (X==2) { digitalWrite(puV2, !digitalRead(puV2)); }
   if (X==3) { digitalWrite(puV3, !digitalRead(puV3)); }
   if (X==4) { digitalWrite(puV4, !digitalRead(puV4)); }
   if (X==5) { digitalWrite(puV5, !digitalRead(puV5)); }
   if (X==6) { digitalWrite(puV6, !digitalRead(puV6)); }
   if (X==7) { digitalWrite(pVIS, !digitalRead(pVIS)); }
   if (X==8) { digitalWrite(p_IR, !digitalRead(p_IR)); }
   if (X==9) { digitalWrite(pDIR, !digitalRead(pDIR)); }
   if (X==0) { digitalWrite(pSTP, !digitalRead(pSTP)); }
   
  }

  if (state=="K2000" && millis() > tRef+200) {

    K = (K+1) % 22;

    if (K==3 || K==18) { digitalWrite(puV1, !digitalRead(puV1)); }
    if (K==1 || K==4 || K==17 || K==21) { digitalWrite(puV2, !digitalRead(puV2)); }
    if (K==2 || K==5 || K==16 || K==20) { digitalWrite(puV3, !digitalRead(puV3)); }
    if (K==3 || K==6 || K==15 || K==19) { digitalWrite(puV4, !digitalRead(puV4)); }
    if (K==4 || K==7 || K==14 || K==18) { digitalWrite(puV5, !digitalRead(puV5)); }
    if (K==5 || K==8 || K==13 || K==17) { digitalWrite(puV6, !digitalRead(puV6)); }
    if (K==6 || K==9 || K==12 || K==16) { digitalWrite(pVIS, !digitalRead(pVIS)); }
    if (K==7 || K==10 || K==11 || K==15) { digitalWrite(p_IR, !digitalRead(p_IR)); }
    if (K==8 || K==13) { digitalWrite(pDIR, !digitalRead(pDIR)); }

    tRef = millis();
   
  }
  
}


