import RPi.GPIO as GPIO
import serial
import time
# Set up GPIO for button
button
pin = 17 # GPIO pin 17
_
GPIO.setmode(GPIO.BCM)
GPIO.setup(button
pin, GPIO.IN)
_
# Set up UART (Serial) communication with Arduino
ser = serial.Serial('/dev/serial0'
, 9600)
print("Raspberry Pi is ready. Press the button to blink the LED...
try:
")
while True:
if GPIO.input(button
pin) == GPIO.LOW: # If button is pressed
_
print("Button pressed! Sending signal to Arduino...
")
ser.write(b'1') # Send signal to Arduino to blink LED
time.sleep(0.2) # Debounce delay
else:
print("Button not pressed. Waiting for press...
")
time.sleep(0.1) # Short delay to avoid excessive CPU usage
except KeyboardInterrupt:
print("Program interrupted.
")
finally:
GPIO.cleanup()
print("GPIO cleaned up. Exiting program.
")