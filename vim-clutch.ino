#include <Bounce.h>

int led = 11;
int footPedal = 9;
char mode = 'n';

Bounce button = Bounce(footPedal, 10);

void setup() {
    Serial.begin(9600);
    pinMode(footPedal, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    delay(1000);
}

void loop() {
    button.update();
    if (button.fallingEdge()) {
        if (mode == 'i') {
            normalMode();
        } else {
            insertMode();
        }
    }
}

void insertMode() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('[');
    Keyboard.releaseAll();
    delay(100);
    Keyboard.write("l");
    Keyboard.write("i");
    digitalWrite(led, HIGH);
    mode = 'i';
}

void normalMode() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('[');
    Keyboard.releaseAll();
    digitalWrite(led, LOW);
    mode = 'n';
}
