#include <IRremote.hpp>
const int IR_RECEIVE_PIN=8;
#define DELAY_AFTER_SEND 2000


void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // Just to know which program is running on my Arduino
  Serial.println(F("Starting " __FILE__ " from " __DATE__ "\r\n\tUsing library version " VERSION_IRREMOTE));
  IrSender.begin(3); // Start with IR_SEND_PIN as send pin and enable feedback LED at default feedback LED pin
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial); // optional use new print version
    IrReceiver.resume(); // Enable receiving of the next value
  }

  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    String str = Serial.readString();  //read until timeout
    str.trim();                        // remove any \r \n whitespace at the end of the String  }
    Serial.print("Received:[");
    Serial.print(str);
    Serial.println("]");
 //   IrSender.sendNECRaw(0xF708BF40, 0); //new
    if (str == "on" || str == "off") {
      Serial.println("Sending On/Off...");
      IrSender.sendNEC(0x4, 0x08, 0);  
    }
    else if (str == "me" || str == "ME") {
      Serial.println("Sending Menu...");
      IrSender.sendNEC(0x4, 0x43, 0);  
    }
    else if (str == "re" || str == "RE") {
      Serial.println("Sending Return...");
      IrSender.sendNEC(0x4, 0x28, 0);  
    }
    else if (str == "ok" || str == "OK") {
      Serial.println("Sending Ok...");
      IrSender.sendNEC(0x4, 0x44, 0);  
    }
    else if (str == "up" || str == "UP") {
      Serial.println("Sending Up...");
      IrSender.sendNEC(0x4, 0x40, 0);  
    }
    else if (str == "do" || str == "DO") {
      Serial.println("Sending Down...");
      IrSender.sendNEC(0x4, 0x41, 0);  
    }
    else if (str == "le" || str == "LE") {
      Serial.println("Sending Left...");
      IrSender.sendNEC(0x4, 0x07, 0);  
    }
    else if (str == "ri" || str == "RI") {
      Serial.println("Sending Rigth...");
      IrSender.sendNEC(0x4, 0x06, 0);  
    }
    else if (str == "green" || str == "GREEN") {
      Serial.println("Sending Green...");
      IrSender.sendNEC(0x4, 0x71, 0);  
    }
    else if (str == "red" || str == "RED") {
      Serial.println("Sending Red...");
      IrSender.sendNEC(0x4, 0x72, 0);  
    }
    else if (str == "yellow" || str == "YELLOW") {
      Serial.println("Sending Yellow...");
      IrSender.sendNEC(0x4, 0x63, 0);  
    }
    else if (str == "blue" || str == "BLUE") {
      Serial.println("Sending Blue...");
      IrSender.sendNEC(0x4, 0x61, 0);  
    }
    else if (str == "0") {
      Serial.println("Sending 0...");
      IrSender.sendNEC(0x4, 0x10, 0);  
    }
    else if (str == "1") {
      Serial.println("Sending 1...");
      IrSender.sendNEC(0x4, 0x11, 0);  
    }
    else if (str == "2") {
      Serial.println("Sending 2...");
      IrSender.sendNEC(0x4, 0x12, 0);  
    }
    else if (str == "3") {
      Serial.println("Sending 3...");
      IrSender.sendNEC(0x4, 0x13, 0);  
    }
    else if (str == "4") {
      Serial.println("Sending 4...");
      IrSender.sendNEC(0x4, 0x14, 0);  
    }
    else if (str == "5") {
      Serial.println("Sending 5...");
      IrSender.sendNEC(0x4, 0x15, 0);  
    }
    else if (str == "6") {
      Serial.println("Sending 6...");
      IrSender.sendNEC(0x4, 0x16, 0);  
    }
    else if (str == "7") {
      Serial.println("Sending 7...");
      IrSender.sendNEC(0x4, 0x17, 0);  
    }
    else if (str == "8") {
      Serial.println("Sending 8...");
      IrSender.sendNEC(0x4, 0x18, 0);  
    }
    else if (str == "9") {
      Serial.println("Sending 9...");
      IrSender.sendNEC(0x4, 0x19, 0);  
    }
    else if (str == "+") {
      Serial.println("Sending +...");
      IrSender.sendNEC(0x4, 0x00, 0);  
    }
    else if (str == "-") {
      Serial.println("Sending -...");
      IrSender.sendNEC(0x4, 0x01, 0);  
    }
    
    delay(DELAY_AFTER_SEND);
    IrReceiver.resume();
  }
  delay(100);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
