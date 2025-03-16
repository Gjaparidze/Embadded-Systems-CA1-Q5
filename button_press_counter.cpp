#include "mbed.h"

// Create a DigitalIn object for PC_13 (button input pin)
DigitalIn button(PC_13);

// Variable to count the number of button presses
int press_count = 0;

// Function that is called every time the button is pressed
void on_button_press() {
    press_count++;
    printf("Button pressed %d times\n", press_count);
}

int main() {
    // Attach the function to the falling edge of the button (button press)
    button.fall(&on_button_press);

    // Infinite loop to keep the program running
    while (true) {
        // Do nothing, the interrupt will handle button presses
        wait_us(100000); // Optional: add a small delay to avoid CPU overload
    }
}
