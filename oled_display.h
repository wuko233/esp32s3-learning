#pragma once
#include <U8g2lib.h>
#include <Arduino.h>
#include <string.h>

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED;
extern const int OLED_SDA;
extern const int OLED_SCL;
static const unsigned char imageData[] U8X8_PROGMEM = {
  // 这里替换为你的实际128x64图像数据（1024字节）
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF8,0x03,0xF8,0xFF,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1F,0xFC,0xFF,0xFF,0x0F,0xE0,0x07,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0xFE,0xFF,0xFF,0x1F,0xFE,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x7F,0xFF,0xFF,0xFF,0x3F,0xFF,0x1F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0x00,0xC0,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x0F,0x00,0x00,0xFC,0xFF,0x0F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x07,0xF0,0xFF,0x01,0x40,0x01,0xF0,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,0x7F,0x00,0x38,0x02,0xC0,0xFF,0x03,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x09,0xC0,0x1F,0x00,0x04,0x44,0x00,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x07,0x60,0x00,0x34,0x03,0xFC,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x10,0x00,0x01,0x08,0x03,0x08,0x04,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x80,0x00,0x02,0x00,0x08,0x10,0x10,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x02,0x40,0x80,0x01,0x01,0x00,0x20,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x20,0x40,0x00,0x01,0x10,0x40,0xC0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x10,0x20,0x00,0x00,0x10,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x3C,0x10,0x00,0x00,0x10,0x00,0x01,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x24,0x53,0x08,0x00,0x00,0x10,0x00,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0x88,0x04,0x00,0x00,0x10,0x00,0x00,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xFB,0x00,0x13,0x08,0x00,0x30,0x04,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x04,0x02,0x80,0x01,0x30,0x08,0x20,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x80,0x00,0x09,0x84,0x01,0x50,0x08,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x88,0x82,0x04,0x94,0x11,0x90,0x09,0x08,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x40,0x50,0x80,0x02,0xC4,0x11,0xD0,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x64,0x41,0x03,0x48,0x13,0x10,0x09,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x20,0x28,0x41,0x03,0x4C,0x36,0x0C,0x09,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x10,0x81,0x01,0x54,0x24,0x08,0x0A,0x10,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x20,0x90,0x20,0x01,0x62,0x58,0x00,0x16,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x8C,0x40,0x01,0x62,0x10,0xF4,0x17,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x44,0x40,0x01,0xFD,0x05,0xF2,0x0C,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x20,0x00,0x01,0xE1,0x01,0xF1,0x20,0x04,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xA0,0x10,0x00,0x01,0xE1,0xC1,0xF0,0x20,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x04,0xE1,0x41,0xF0,0x20,0x34,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x10,0x10,0x00,0x8E,0xE1,0x01,0xF0,0x60,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8A,0xC1,0x01,0xE0,0x60,0x42,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x08,0x08,0x00,0x88,0xC0,0x00,0x60,0x00,0x89,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x00,0x95,0x02,0x00,0x00,0x10,0x88,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0x08,0x00,0x95,0x02,0x00,0x00,0x50,0x08,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xB8,0x80,0xA4,0x02,0x00,0x00,0x00,0x08,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x1C,0x81,0xC4,0x00,0xD0,0x03,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x3C,0x07,0x84,0x04,0x10,0x02,0x88,0x04,0x02,0x00,0x00,0x00,
    0x00,0x00,0x00,0x01,0x3C,0x5A,0x20,0x00,0x10,0x02,0x80,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x62,0x68,0x18,0x20,0x00,0xC6,0x01,0x04,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x7C,0x84,0xF7,0x30,0xC0,0x00,0x31,0x80,0x08,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x7E,0x00,0xD8,0x93,0x01,0xC0,0x0C,0x80,0x08,0x00,0x00,0x00,
    0x00,0x00,0x80,0x01,0x7E,0x08,0xB8,0xFF,0x0E,0xF8,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x7F,0x08,0xB8,0xFF,0xC7,0x41,0x70,0x80,0x11,0x00,0x00,0x00,
    0x00,0x00,0xC0,0x81,0x7F,0x00,0x78,0xFF,0xFF,0xFF,0xFF,0x80,0x11,0x00,0x00,0x00,0x00,0x00,0xC0,0x83,0x7F,0x10,0xF8,0xFF,0xFF,0xFF,0x7F,0x80,0x11,0x00,0x00,0x00,
    0x00,0x00,0xC0,0x8C,0x7F,0x10,0xFC,0xFE,0xFF,0xFF,0x7F,0x48,0x11,0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0x7F,0x10,0xFC,0xFC,0xFF,0xFF,0x7F,0x7E,0x00,0x00,0x00,0x00,
    0x00,0x00,0xC0,0xC0,0x7F,0x10,0xFC,0xEC,0xFF,0xFF,0xBF,0xF9,0x08,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0x3F,0x10,0xFC,0xBC,0xFF,0xFF,0x1F,0xFE,0x00,0x00,0x00,0x00,
    0x00,0x00,0xC0,0xC0,0x3F,0x10,0xFC,0x7C,0xFE,0xFF,0x03,0xFC,0x07,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0x3F,0x30,0xFC,0x7C,0xC0,0x3F,0x0E,0xFC,0x07,0x00,0x00,0x00,
    0x00,0x00,0xC0,0xC0,0x3F,0x30,0x7C,0x7C,0x00,0x80,0x0F,0xFC,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0xC1,0x3F,0x10,0x7C,0x7C,0x18,0x80,0x0F,0xFC,0x09,0x00,0x00,0x00,
    0x00,0x00,0x80,0xE1,0x1F,0x10,0x7C,0x7C,0x04,0x84,0x0F,0xFC,0x20,0x00,0x00,0x00,0x00,0x00,0x80,0xE1,0x1F,0x00,0x7C,0x7C,0x20,0xC1,0x07,0xFE,0x40,0x00,0x00,0x00,
    0x00,0x00,0x80,0xE1,0x1F,0x00,0x7C,0x7C,0x22,0xC0,0x07,0x7E,0x80,0x01,0x00,0x00,0x00,0x00,0x80,0xE1,0x1F,0x00,0xFC,0x7E,0x22,0xC0,0x07,0x7F,0x00,0x02,0x00,0x00,
    0x00,0x00,0x80,0xE1,0x0F,0x00,0x7C,0x7F,0x02,0xE1,0xC3,0x3F,0x00,0x04,0x00,0x00,0x00,0x00,0x80,0xE1,0x0F,0x80,0xFC,0x7F,0x14,0xE2,0xE3,0x3F,0x00,0x08,0x00,0x00
};

void display_menu();

void display(const char* info, int display_time);

void img_test();