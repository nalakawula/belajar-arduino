                      D0   D1   RST
       GND  GND  VCC  RX   TX   /DTR
        +--------------------------------+
        |  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  |
        |              FTDI              |
    D1  | [ ]1/TX                 RAW[ ] |    
    D0  | [ ]0/RX                 GND[ ] |    
        | [ ]RST        SCL/A5[ ] RST[ ] |   C6
        | [ ]GND        SDA/A4[ ] VCC[ ] |    
    D2  | [ ]2/INT0    ___         A3[ ] |   C3
    D3  |~[ ]3/INT1   /   \        A2[ ] |   C2
    D4  | [ ]4       /PRO  \       A1[ ] |   C1
    D5  |~[ ]5       \ MINI/       A0[ ] |   C0
    D6  |~[ ]6        \___/    SCK/13[ ] |   B5
    D7  | [ ]7          A7[ ] MISO/12[ ] |   B4
    B0  | [ ]8          A6[ ] MOSI/11[ ]~|   B3
    B1  |~[ ]9                  SS/10[ ]~|   B2
        |           [RST-BTN]            |    
        +--------------------------------+  
    
    http://busyducks.com/ascii-art-arduinos
