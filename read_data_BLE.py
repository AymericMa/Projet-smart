import pygatt
from binascii import hexlify, unhexlify
import logging

#logging.basicConfig()
#logging.getLogger('pygatt').setLevel(logging.DEBUG)

adapter = pygatt.GATTToolBackend()

listUUID = [
    "00002800-0000-1000-8000-00805f9b34fb",
    "00002a00-0000-1000-8000-00805f9b34fb",
    "00002a01-0000-1000-8000-00805f9b34fb",
    "00002a02-0000-1000-8000-00805f9b34fb",
#    "00002a03-0000-1000-8000-00805f9b34fb",
    "00002a04-0000-1000-8000-00805f9b34fb",
#    "00002a05-0000-1000-8000-00805f9b34fb",
    "00002901-0000-1000-8000-00805f9b34fb",
    "00002902-0000-1000-8000-00805f9b34fb",
    "00002803-0000-1000-8000-00805f9b34fb",
    "0000ffe1-0000-1000-8000-00805f9b34fb"

]

def write(data, write_uuid):
    device.char_write(write_uuid, unhexlify(data))

for uuid in listUUID:
    try:
        adapter.start()
        device = adapter.connect('7C:01:0A:7C:2E:76')
        print(uuid)
        value = device.char_read(uuid)
        print("Received data: %s" % hexlify(value))
        print(value)
        write(b'7777772e6a6e6875616d616f2e636b', "0000ffe1-0000-1000-8000-00805f9b34fb")
        value = device.char_read(uuid)
        print("Received data after write: %s" % hexlify(value))
    finally:
        adapter.stop()
#
#uuid = "0000ffe1-0000-1000-8000-00805f9b34fb"
#while True:
#    try:
#        adapter.start()
#        device = adapter.connect('7C:01:0A:7C:2E:76')
#        value = device.char_read(uuid)
#        print(value)
#    finally:
#        adapter.stop()
