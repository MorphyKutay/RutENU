# RutENU

A reverse shell C script is generated with the IP address and port information received from the user.
The code contains a socket program that establishes a TCP connection to the target IP and launches a command line shell `(/bin/sh)` after the connection is successful. This allows the attacker to connect to the target computer and execute commands.

![alt text](https://raw.githubusercontent.com/MorphyKutay/RutENU/refs/heads/main/ss.png)

Reverse shell is an attack method that firewalls and network monitoring systems (IDS/IPS) usually struggle to detect. To prevent this type of attack, careful monitoring and port filtering should be performed on the network.
