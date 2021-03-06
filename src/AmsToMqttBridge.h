#ifndef _AMSTOMQTTBRIDGE_H
#define _AMSTOMQTTBRIDGE_H

#define WIFI_CONNECTION_TIMEOUT 30000;

#define INVALID_BUTTON_PIN  0xFFFFFFFF


#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

// Build settings for custom hardware by Roar Fredriksen
#if HW_ROARFRED
#define LED_PIN 2 // The blue on-board LED of the ESP8266 custom AMS board
#define LED_ACTIVE_HIGH 0
#define AP_BUTTON_PIN 0

#if DEBUG_MODE
#if SOFTWARE_SERIAL
#include <SoftwareSerial.h>
SoftwareSerial *hanSerial = new SoftwareSerial(3);
#else
HardwareSerial *hanSerial = &Serial;
#endif
#else
HardwareSerial *hanSerial = &Serial;
#endif

// Build settings for Wemos Lolin D32
#elif defined(ARDUINO_LOLIN_D32)
#define LED_PIN 5
#define LED_ACTIVE_HIGH 0
#define AP_BUTTON_PIN 4

HardwareSerial *hanSerial = &Serial2;

// Build settings for Wemos D1 mini
#elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)
#define LED_PIN D4
#define LED_ACTIVE_HIGH 0
#define AP_BUTTON_PIN D2

#define SOFTWARE_SERIAL 1
#include <SoftwareSerial.h>
SoftwareSerial *hanSerial = new SoftwareSerial(D1);

// Build settings for Adafruit Feather ESP32
#elif defined(ARDUINO_FEATHER_ESP32)
#define LED_PIN LED_BUILTIN
#define LED_ACTIVE_HIGH 1
#define AP_BUTTON_PIN INVALID_BUTTON_PIN

HardwareSerial *hanSerial = &Serial2;

// Default build settings
#else
#define LED_PIN 2
#define LED_ACTIVE_HIGH 0
#define AP_BUTTON_PIN INVALID_BUTTON_PIN
#define SOFTWARE_SERIAL 1
#include <SoftwareSerial.h>
SoftwareSerial *hanSerial = new SoftwareSerial(5);
#endif

#endif
