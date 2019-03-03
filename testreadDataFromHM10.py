import pygatt
from binascii import hexlify
import logging
import time

#logging.basicConfig()
#logging.getLogger('pygatt').setLevel(logging.DEBUG)
adapter = pygatt.GATTToolBackend()

def handle_data(handle, value):
    """
    handle -- integer, characteristic read handle the data was received on
    value -- bytearray, the data returned in the notification
    """
    print("Received data: %s" % hexlify(value))

try:
    adapter.start()
    device = adapter.connect('7C:01:0A:7C:2E:76')

    device.subscribe("0000ffe1-0000-1000-8000-00805f9b34fb",
                     callback=handle_data)
    while True:
        time.sleep(10)
finally:
    adapter.stop()
