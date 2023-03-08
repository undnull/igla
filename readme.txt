Igla AFSK (Audio Frequency-Shift Keying)

Being a programming goblin I am, I decided to create
something of a convention that would be a more functional
alternative to RTTY in the world of modern computers.

Igla allows for transmitting binary (presumably UTF-8)
data at 80 baud or 10 bytes per second. In some cases
it may be possible to increase that to 800 baud or 100 bytes a second.

Igla's signals fit within 5 kHz band and hence are pretty
trivial to modulate via AM, NFM, LSB, USB and whatnot.

Baud Rate: 80/800 baud
Mark frequency: 3200 Hz
Space frequency: 1600 Hz
Bit order: LSB -> MSB (bit 0 to bit 7)

