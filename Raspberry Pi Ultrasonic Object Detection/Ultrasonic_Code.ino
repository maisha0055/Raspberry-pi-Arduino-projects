from gpiozero.pins.pigoio import PiGPIOFactory
from gpiozero import Device, AngularServo, DistanceSensor
from time import sleep

Device.pin_factory - PiGPIOFactory ()
servo = AngularServo (17, min_angle=0, max_angle=180, min_pulse_width = 0.5/1000, max pulse width = 2.5/1000

sensor = DistanceSensor (echo = 20, trigger = 21, max_distance = 1.0)

while True:
    distance - sensor. distance * 100 #centimeters
    print (f"Distance: (distance: 1f) cm"

    if distance < 5:
        servo.angle = 180
    else:
        servo.angle = 90
    sleep (0.5)