/*
  Dual - Arduino
 
 ---
 Commands exemples
 
 setMode:1:OUT
 setMode:12:IN
 
 ---
 Notes
 
 Minimal value for dm: 300µs
 
 */

// === DEFINITIONS ===============================================

int id = 1;
boolean isRunning = false;

int pDir = 8;
int pStep = 9;
int pBottom = 19;
int pTop = 20;
int period = 1000;

// === SETUP =====================================================

void setup() {                

  // Serial communication  
  Serial.begin(115200);
  Serial.setTimeout(0);

}

// === LOOP ======================================================

void loop() {

  // === Manage inputs ===========================================

  if (Serial.available()) {   

    // Get serial commad string
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
     */

    // --- IDENTIFIER ---------------------------------------
    if (cmd.equals("getId")) {

      Serial.println(String(id));

      // --- INFORMATION --------------------------------------
    } 
    else if (cmd.equals("getInfo")) {

      Serial.println("----------------------------");
      Serial.println("Dual #" + String(id));
      Serial.println("");
      Serial.println("Pin DIR:" + String(pDir));
      Serial.println("Pin STEP:" + String(pStep));
      Serial.println("Period:" + String(period) + "us");
      Serial.println("----------------------------");

      // --- SET PIN MODE -------------------------------------
    } 
    else if (cmd.equals("setMode")) {
      
      if (val.equals("INPUT")) { 
        pinMode(key.toInt(), INPUT); 
      }
      else if (val.equals("OUTPUT")) { 
        pinMode(key.toInt(), OUTPUT); 
      }
      else if (val.equals("INPUT_PULLUP")) {
        pinMode(key.toInt(), INPUT_PULLUP);
      }

      Serial.println("Pin " + key + " set to " + val);

      // --- SET VALUE ----------------------------------------
    } 
    else if (cmd.equals("setVal")) {

      digitalWrite(key.toInt(), val.equals("ON")? HIGH : LOW);
      // Serial.println("Pin " + key + " set to " + val);

      // --- PERIOD -------------------------------------------
    } 
    else if (cmd.equals("setPeriod")) {

      period = key.toInt();
      Serial.println("Period set to " + key + "us");

      // --- RUN ----------------------------------------------
    } 
    else if (cmd.equals("run")) {

      isRunning = true;
      Serial.println("Running");

      // --- STOP ---------------------------------------------
    } 
    else if (cmd.equals("stop")) {

      isRunning = false;
      Serial.println("Stopped (by command)");

    }

    // Flush output
    Serial.flush();

  }

  // === Actions =================================================

  // --- RUN -------------------------------------------------

  if (isRunning) {
    
    // --- Checks

    if (digitalRead(pTop)==LOW & digitalRead(pDir)==HIGH) {
      isRunning = false;
      Serial.println("[STOP]");
      Serial.println("Stopped (by top switch)");
      return;
    }

    if (digitalRead(pBottom)==LOW & digitalRead(pDir)==LOW) { 
      isRunning = false;
      Serial.println("[STOP]");
      Serial.println("Stopped (by bottom switch)");
      return;
    }

    digitalWrite(pStep, HIGH); 
    delayMicroseconds(period/2);

    digitalWrite(pStep, LOW);
    delayMicroseconds(period/2);

  }

}


