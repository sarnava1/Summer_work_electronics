

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    uint16_t start = 0xA0;
    uint16_t j, reg, a = start;


    Serial.println("PRBS-9 sequence starting with 0xA0");
    Serial.println(a&0x0001);
    for(j = 0; ; j++) {

        reg = ((a) ^ (a >> 4)) & 1;
        a = ((a >> 1) | reg << (8));

        
//        reg=reg&0x0001;
        /* Print bit stream */
        Serial.println(reg&0x0001);


        /* Stop condition */
        if (a == start) {
            Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            //break;
        }
        //delay(1000);
    }
}
