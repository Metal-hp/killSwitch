##killSwitch project by Metal.hp
    Here lies the intructions, code, diagrams and test documentation for killSwitch.

*Purpose*
    killSwitch is a firmware to be embbeded in 80-00s Honda fuel injection engine management systems.
Acts as a security intermediate between ingition switch and ECU power supply. We aim to reduce
posibility of vehicle theft in case of break in. By embedding, we'll be updating the vehicle security system. Thieve must posses broader knowledge/skills in electronics.
The time cost for a successfull theft shall increase as well.

*How it works*
    killSwitch works by key authentication. Powered by ignition 1 or accesory power supply. When powered, it will read a digital file (or "key") in the form of SD memory card. Once the controler matches the given key with it's stored key, it opens the gate (built in MOSFET) for ignition 2 fully powering the ECU.

*Other security methods*
    We plan on replacing ECU housing hardware. Later on we will develop irregular bolt sapes with 
their respective tool to screw them in and out. Plus a braket to secure the ECU from simply being
replaced by a generic one.
