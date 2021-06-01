// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Arduino_IRremote_Practice.ino
    Created:	2021/5/26 14:47:35
    Author:     AIRWOLF-SURFACE\Michael Wolf
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
#include <IRremote.h>
#define IR_SEND_PIN         3

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

/*
 * Set up the data to be sent.
 * For most protocols, the data is build up with a constant 8 (or 16 byte) address
 * and a variable 8 bit command.
 * There are exceptions like Sony and Denon, which have 5 bit address.
 */
uint16_t sAddress = 0x10;
//��Դ
uint8_t sCommand1 = 0x5D;
//��
uint8_t sCommand2 = 0x45;
//��
uint8_t sCommand3 = 0x55;
//��
uint8_t sCommand4 = 0x7;
//��
uint8_t sCommand5 = 0x1;
//ok
uint8_t sCommand6 = 0x41;
//����
uint8_t sCommand7 = 0x0;
uint8_t sRepeats = 3;
int inByte = 0;         // incoming serial byte
//����
unsigned int buf1[67] = { 4450,4450,550,1650,550,1650,550,1700,500,600,550,550,550,550,550,550,550,550,550,1700,500,1700,550,1650,550,550,550,550,550,600,550,550,550,550,550,1650,550,550,550,550,550,600,500,600,550,550,550,550,550,550,550,550,550,1700,500,1700,550,1650,550,1650,550,1700,500,1700,550,1650,550 };
//��Դ
unsigned int buf2[67] = { 4450,4500,500,1700,550,1650,550,1700,500,600,550,550,550,550,550,550,550,600,500,1700,550,1650,550,1700,500,600,550,550,550,550,550,550,550,550,550,600,500,1700,550,550,550,550,550,600,500,600,550,550,550,550,550,1650,550,600,500,1700,550,1650,550,1700,500,1700,550,1650,550,1700,550 };
//����+
unsigned int buf3[67] = { 4450,4450,550,1650,600,1650,550,1650,550,550,550,550,550,550,600,500,600,550,550,1650,550,1650,600,1600,600,550,550,550,550,550,550,550,550,550,600,1650,550,1650,550,1650,600,500,600,500,600,550,550,550,550,550,550,550,600,500,600,500,600,1650,550,1650,550,1650,600,1650,550,1650,550 };
//����-
unsigned int buf4[67] = { 4450,4450,550,1650,600,1600,600,1650,550,550,550,550,550,550,600,500,600,550,550,1650,550,1650,550,1650,600,550,550,550,550,550,550,550,550,550,550,1650,600,1650,550,550,550,1650,550,550,600,500,600,550,550,550,550,550,550,550,550,1650,600,500,600,1650,550,1650,550,1650,600,1650,550 };
//�յ���
unsigned int buf5[291] = { 3416, 1744, 412, 1296, 412, 1300, 412, 456, 412, 456, 412, 456, 412, 1296, 412, 456, 412, 456, 412, 1276, 436, 1296, 412, 456, 412, 1276, 436, 432, 436, 456, 412, 1276, 432, 1300, 412, 456, 412, 1296, 412, 1300, 408, 460, 412, 456, 408, 1300, 412, 456, 412, 456, 412, 1300, 408, 460, 408, 460, 412, 456, 408, 460, 408, 460, 412, 456, 408, 460, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 408, 460, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 408, 460, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 1296, 412, 1300, 412, 456, 412, 456, 412, 456, 412, 1296, 412, 456, 412, 432, 436, 1300, 412, 456, 412, 456, 412, 456, 412, 432, 436, 456, 412, 1272, 436, 1276, 436, 456, 412, 1300, 408, 460, 408, 1300, 412, 456, 412, 456, 412, 456, 412, 1296, 412, 1300, 412, 1296, 412, 456, 412, 1300, 408, 460, 412, 456, 412, 456, 412, 456, 412, 456, 408, 460, 412, 456, 412, 456, 412, 456, 408, 460, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 460, 408, 460, 408, 456, 412, 460, 408, 456, 412, 456, 412, 456, 412, 456, 412, 456, 412, 460, 408, 460, 408, 460, 408, 460, 408, 460, 408, 460, 408, 460, 408, 460, 408, 460, 408, 460, 412, 456, 412, 456, 408, 1300, 412, 456, 412, 1276, 432, 1276, 436, 1276, 432 };
void loop() 
{
    
    // if we get a valid byte, read analog ins:
    if (Serial.available() > 0) 
    {
        // get incoming byte:
        inByte = Serial.read();
        /*
        * Print current send values
        */
        Serial.println(inByte);

        // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
        //��1�ǵ�Դ
        if (inByte == 49)
        {
            IrSender.sendRaw(buf2, 67, 38);
        }
        //��2������ѡ��
        if (inByte == 50)
        {
            IrSender.sendRaw(buf1, 67, 38);
        }
        //��3������+
        if (inByte == 51)
        {
            IrSender.sendRaw(buf3, 67, 38);
        }
        //��4������-
        if (inByte == 52)
        {
            IrSender.sendRaw(buf4, 67, 38);
        }
        //��5�ǿյ���
        if (inByte == 53)
        {
            IrSender.sendRaw(buf5, 291, 38);
        }
        //��z�ǵ�Դ
        if (inByte == 122)
        {
            IrSender.sendNEC(sAddress, sCommand1, sRepeats);
        }
        //��w����
        if (inByte == 119)
        {
            IrSender.sendNEC(sAddress, sCommand2, sRepeats);
        }
        //��s����
        if (inByte == 115)
        {
            IrSender.sendNEC(sAddress, sCommand3, sRepeats);
        }
        //��a����
        if (inByte == 97)
        {
            IrSender.sendNEC(sAddress, sCommand4, sRepeats);
        }
        //��d����
        if (inByte == 100)
        {
            IrSender.sendNEC(sAddress, sCommand5, sRepeats);
        }
        //��e��OK
        if (inByte == 101)
        {
            IrSender.sendNEC(sAddress, sCommand6, sRepeats);
        }
        //��q�Ƿ���
        if (inByte == 113)
        {
            IrSender.sendNEC(sAddress, sCommand7, sRepeats);
        }

        delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    }
    
}
