/*
 * LED47.h - 这个库专为这个四位数码管产品而写
 * http://item.taobao.com/item.htm?id=19372334234
 */
#include "Arduino.h"
#include "LED47.h"


const int POS_CODE[] = {0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10};

LED47::LED47(int sclkPin, int rclkPin, int dioPin)
{
    pinMode( sclkPin, OUTPUT);
    pinMode( rclkPin, OUTPUT);
    pinMode( dioPin,  OUTPUT);

    _sclkPin = sclkPin;
    _rclkPin = rclkPin;
    _dioPin  = dioPin;
}

void LED47::display(int number)
{
    char str[4];
    itoa(number, str, 10);

    int len = 0;
    while(str[len]) len++;
    int offset = 4 - len;

    for(int i=0; i<len; i++ )
    {
        if( str[i] ) {
          displayDigital( i + offset, str[i]);
        } else {
          break;
        }
    }
}

void LED47::displayDigital( int pos, char letter )
{
    digitalWrite(_rclkPin, LOW);  
    shiftOut(_dioPin, _sclkPin, MSBFIRST, getBinCode(letter));
    shiftOut(_dioPin, _sclkPin, MSBFIRST, getPosCode(pos));
    digitalWrite(_rclkPin, HIGH);  
}

int LED47::getPosCode( int pos )
{
    return POS_CODE[pos];
}

int LED47::getBinCode( char code )
{
    switch(code)
    {
        case '0': return 0xC0;
        case '1': return 0xF9;
        case '2': return 0xA4;
        case '3': return 0xB0;
        case '4': return 0x99;
        case '5': return 0x92;
        case '6': return 0x82;
        case '7': return 0xF8;
        case '8': return 0x80;
        case '9': return 0x90;
        case 'A': return 0x8C;
        case 'B': return 0xBF;
        case 'C': return 0xC6;
        case 'D': return 0xA1;
        case 'E': return 0x86;
        case 'F': return 0xFF;
        case '-': return 0xbf;
    };
}
