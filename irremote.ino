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
    IrSender.sendNECRaw(0xF708BF40, 0); //new
    delay(DELAY_AFTER_SEND);
  }
  delay(100);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
