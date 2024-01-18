This is a small project that acts as a serial relay between a DATECS VFD and the USB port.  Incoming serial USB traffic is relayed to the RX line of the VFD over a serial port on pins 16/17 (16 unused).

Commands like cursor home and screen clear and cursor position are "translated" to be what a MatrixOrbital unit might expect, so that this VFD can be used with AIDA64.

This code is public domain under GPL v3, a copy of which should be available in this folder (or which is broadly available on the Web).
