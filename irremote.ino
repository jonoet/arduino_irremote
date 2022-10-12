#include <IRremote.hpp>
const int IR_RECEIVE_PIN=8;

void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // Just to know which program is running on my Arduino
  Serial.println(F("Starting " __FILE__ " from " __DATE__ "\r\n\tUsing library version " VERSION_IRREMOTE));
  
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
  }
  delay(100);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
