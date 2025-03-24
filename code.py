from machine import Pin, SPI
import time
import xpt2046
import keyboard

# Setup SPI interface for the touch controller
spi = SPI(1, baudrate=2000000, polarity=0, phase=0)
cs = Pin(15, Pin.OUT)
irq = Pin(14, Pin.IN)

# Create an instance of the XPT2046 touchscreen controller
touch = xpt2046.XPT2046(spi, cs, irq)

# Function to simulate a key press
def simulate_key_press(x, y):
    # Define the screen touch area and corresponding key mapping.
    if 0 < x < 200 and 0 < y < 100:
        keyboard.press('a')
        print("Pressed 'a'")
    elif 200 < x < 400 and 0 < y < 100:
        keyboard.press('b')
        print("Pressed 'b'")
    elif 0 < x < 200 and 100 < y < 200:
        keyboard.press('c')
        print("Pressed 'c'")
    elif 200 < x < 400 and 100 < y < 200:
        keyboard.press('d')
        print("Pressed 'd'")
    else:
        keyboard.release_all()  # Release all keys if outside the touch zones

# Main loop to detect touch and simulate key press
while True:
    if touch.touched():
        # Get the touch point
        x, y = touch.touch_point()
        print("Touched at x:", x, "y:", y)
        
        # Simulate key press based on the touch point
        simulate_key_press(x, y)
        
        time.sleep(0.1)  # To avoid spamming key presses
