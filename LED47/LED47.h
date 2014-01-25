/*
 * LED47.h - 这个库专为这个四位数码管产品而写
 * http://item.taobao.com/item.htm?id=19372334234
 *
 * 目前只支持 0-9999 的整数显示
 */
#ifndef LED47_h
#define LED47_h

#include "Arduino.h"

class LED47
{
    int _sclkPin, _rclkPin, _dioPin;

    public:
        LED47(int sclkPin, int rclkPin, int dioPin);
        void display(int number);
        void display(char word);

    private:
        void displayDigital( int pos, char letter );
        int getPosCode( int pos );
        int getBinCode( char letter );
};

#endif
