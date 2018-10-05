void setup() {

char * message = "Hello World";
char * apn = "internet.fido.ca";
char * apn_login = "fido";
char * apn_password = "fido";
char * server_ip = "52.206.151.197";
char * server_port = "1000";

  
Serial.begin(115200); //initialize Serial(i.e. USB port)
Serial1.begin(115200); //initialize Serial1

delay(3000);

Serial1.println("AT+CIPSHUT");
delay(400);
Serial1.println("AT+CIPMUX=0");
delay(400);
Serial1.println("AT+CGATT=1");
delay(400);

Serial1.print("AT+CSTT=\"");
Serial1.print(apn);
Serial1.print("\",\"");
Serial1.print(apn_login);
Serial1.print("\",\"");
Serial1.print(apn_password);
Serial1.println("\"");

delay(400);

Serial1.println("AT+CIICR");
delay(6000); // This can take a while

Serial1.println("AT+CIFSR");
delay(400);

Serial1.print("AT+CIPSTART=\"TCP\",\"");
Serial1.print(server_ip);
Serial1.print("\",\"");
Serial1.print(server_port);
Serial1.println("\"");
delay(10000);

Serial1.println("AT+CIPSEND");
delay(400);

Serial1.println(message);
Serial1.write(0x1A);

Serial1.println("AT+CIPCLOSE");
delay(400);
Serial1.println("AT+CIPSHUT");
delay(400);  
}

void loop() {
  //If Serial1 receive data, print out to Serial
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  //If Serial receive data, print out to Serial1
  while (Serial.available()) {
    Serial1.write(Serial.read());
  }
  delay(1);  //delay for a short time to
  // avoid unstable USB communication
}
