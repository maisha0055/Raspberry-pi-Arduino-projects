import serial
import RPi.GPIO as GPIO
from rpi_lcd import LCD
from time import sleep
# GPIO pins for LEDs
LEFT_LED = 18      # Red LED
RIGHT_LED = 19     # Green LED  
FORWARD_LED = 20   # Blue LED
# GPIO setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(LEFT_LED, GPIO.OUT)
GPIO.setup(RIGHT_LED, GPIO.OUT)
GPIO.setup(FORWARD_LED, GPIO.OUT)
# Initialize LCD and Serial (from class experiments)
lcd = LCD()
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)
def control_leds(status):
    """Control LEDs based on sensor status"""
    # Turn off all LEDs first
    GPIO.output(LEFT_LED, GPIO.LOW)
    GPIO.output(RIGHT_LED, GPIO.LOW)
    GPIO.output(FORWARD_LED, GPIO.LOW)
   
    # Control LEDs according to lab task requirements
    if status == "LEFT":
        GPIO.output(LEFT_LED, GPIO.HIGH)
        print("LEFT LED ON")
    elif status == "RIGHT":
        GPIO.output(RIGHT_LED, GPIO.HIGH)
        print("RIGHT LED ON")
    elif status == "FORWARD":
        GPIO.output(LEFT_LED, GPIO.HIGH)
        GPIO.output(RIGHT_LED, GPIO.HIGH)
        GPIO.output(FORWARD_LED, GPIO.HIGH)
        print("ALL LEDs ON")
    else:  # STOP or UNCERTAIN
        print("ALL LEDs OFF")

try:
    print("Lab Task Started - LED Control Based on IR Sensor Status")
    while True:
        if ser.in_waiting > 0:
            # Read sensor status from Arduino
            line = ser.readline().decode('utf-8', errors='ignore').strip()
           
            # Update LCD (maintaining class experiment functionality)
            lcd.clear()
            lcd.text('IR Status: ', 1)
            lcd.text(line, 2)
           
            # Lab Task: Control LEDs based on status
            control_leds(line)
           
except KeyboardInterrupt:
    print("\nProgram terminated by user")
finally:
    # Cleanup
    lcd.clear()
    GPIO.cleanup()
    ser.close()
    print("GPIO cleaned up and serial connection closed")