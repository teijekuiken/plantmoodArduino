# PlantMood

PlantMood is een verzameling van header files om de vochtigheid van de aarde van de grond van een plant te meten. De vochtigheid wordt omgezet in 3 levels: dry, wet of alive. Aan de hand van het level kunnen de volgende acties getriggerd worden:

- Er wordt een liedje afgespeeld;
- Op een LCD scherm wordt het vochtigheidspercentage op een levensbalk weergegeven;
- Wanneer de status ‘wet’ is wordt er een waterpomp voor een aantal seconden geactiveerd om de plant water te geven.

## Bijgesloten files

Wanneer dit project gedownload wordt, worden er een aantal mappen gedownload. De header files zitten in de map ‘include’.
De verschillende header files zijn ingedeeld op basis van het onderwerp.
De header files bestaan uit:

1. Communication
2. Lcd;
3. MoistureSensor;
4. Music;
5. Secrets;
6. Waterpump;
7. Wifi.

## Technologie

### Taal en IDE

1. De PlantMood code is geschreven in C++;
2. Visual Studio Code is gebruikt met de plugin PlatformIO.

#### Hardware

3. Deze code is geschreven en getest met de Arduino MKR1000 wifi;
4. De PlantMood code werkt alleen in combinatie met Arduino SAMD (32-bits ARM Cortex-M0+) boards.

#### Libraries

Hieronder een lijst met standaard libraries die gebruikt zijn:

5. Arduino.h;
6. SPI.h.

Hieronder een lijst met libraries die gedownload zijn voor de basiscode:

7. Wifi101 by Arduino.

Hieronder een lijst met libraries die gedownload zijn voor de optie muziek:

8. AudioZero by Arduino;
9. SD by Arduino.

Hieronder een lijst met libraries die gedownload zijn voor de optie LCD:

10. LcdBarGraph by Balazs Kelemen;
11. LiquidCrystal by F Malpartida.

#### Software en aanvullende programma's

12. De java applicatie 'Centralsystem' van het project PlantMood;
13. Lokale mqtt broker (bijvoorbeeld van mosquitto).

### Afbeelding

![Hardware](https://git.fhict.nl/o-s3/team-projects/oop-a/arduino/-/blob/develop/Images/ProjectFoto.JPG)
Dit zijn alle opties aangesloten op de Arduino. De zwarte stekker kan worden aangesloten op zijn eigen voedingsbron (rode powerbank), of gewoon aan de computer.

### Installatie

<u>Doorloop eerst de readme van de java applicatie. Hierin worden al een aantal benodigde programma's/applicaties benoemd</u>

We doorlopen hieronder ieder file die onder de 'include' map aanwezig zijn.
Er wordt aangegeven welke componenten zijn gebruikt voor het eindproduct van de auteur en voldoen aan de gestelde eisen.
Aanvullend zijn er stappen toegevoegd die je moet doorlopen voor het juiste gebruik van de code en de hardwarecomponenten.

***LET OP:*** Het veranderen van pinnummers wordt afgeraden. De meeste pinnummers zijn gekozen voor de specifieke functie die die pin heeft.

### Basiscode: basis, wifi, communication en moistureSensor

#### Benodigdheden

- Visual Studio met de PlatformIO plugin;
- Mqtt broker;
- Arduino MKR1000 wifi (Voor andere mogelijkheden zie paragraaf Technologie);
- Kabel van usb naar micro-USB;
- Breadboard 830;
- RobotDyn Bodemvocht Sensor Module;
- Plant welke in aarde staat;
- Voor het hele project ongeveer 45 jumper wires in verschillende aansluitingen: male-male en male-female. De lengte is je eigen voorkeur;
- Optioneel: Printplaat om het breadboard, de Arduino en ander hardwarecomponenten op vast te zetten.

#### Stappen

1. [Installeer](https://mosquitto.org/download/) een mqtt broker als je deze nog niet hebt.
2. De defaultpoort van de mqtt broker is poort 1883. Mocht dit niet zo zijn kun je de poort in de code aanpassen in 'communication'
```c++
const int defaultportMosquitto = hier invullen;
```
3. Installeer de library Wifi101 by Arduino.
4. Sluit de GND van de Arduino aan op de - van het breadboard en de VCC op de + van het breadboard aan.
5. Ga naar het hoofdstuk circuittekening hieronder en sluit alle hardwarecomponenten die onder ‘Benodigdheden’ van deze paragraaf worden genoemd.
6. Steek de sensor in de aarde van de plant.
7. Ga naar de 'wifi' file en vul tussen de haakjes het IP adres in. ***LET OP:*** Gebruik , ipv . in het ip adres. 
```c++
IPAddress server(hier invullen);
```
8. Ga naar de ‘secrets’ file en vul je loginnaam en wachtwoord van je wifi verbinding in.
```c++
#define SECRET_SSID "Hier loginnaam invullen"
#define SECRET_PASS "Hier het wachtwoord opvullen"
```

Deze opties zijn nu klaar voor gebruik.

### Muziek afspelen: music

#### Benodigdheden

- Kleine speaker -4 Ohm 3W;
- 2x3W stereo audio versterker mini 5V PAM8403 Volume control 2V;
- SD Kaart Adapter Module 3.3-5V;
- Originele micro SD HC 16GB of minder GB;
- Originele micro SD kaart adapter naar SD;
- benodigdheden van de basiscode.

#### Stappen

1. Installeer de libraries AudioZero by Arduino en SD by Arduino.
2. Convert 3 liedjes (voor de levels: wet, dry en alive) naar een .wav file via bijvoorbeeld [deze site](https://audio.online-convert.com/convert-to-wav) met de volgende opties:
- 8 bit;
- 16000Hz;
- Mono;
- Kies hoeveel seconde en welk deel van het liedje je wilt horen;
- Sla de liedjes met de volgende namen op:
   - Naam van het liedje wanneer de aarde van de plant te nat is: wetSong.wav
   - Naam van het liedje wanneer de aarde van de plant te droog is: drySong.wav
   - Naam van het liedje wanneer de aarde van de plant goed is: aliveSong.wav
3. Formateer de SD kaart.
4. Zet de drie liedjes op de SD kaart (zonder ze in in een map te plaatsen).
5. SD kaart module testen:
- Open via Visual Studio: PioHome – Libraries – Installed – SD – Examples – Cardinfo.
- Schuif de SD kaart in de SD kaart module.
- Sluit de SD kaart module aan zoals beschreven in de sketch.
- Upload de sketch op de Arduino en Run.
- Wanneer er in de terminal “Wiring is correct and a card is present” ziet verschijnen en de kaartgegevens te zien krijgt is de SD kaart goed en is SD kaart module goed aangesloten. Je kunt de SD kaart module weer ontkoppelen van je Arduino.
- Als je een foutmelding krijgt kun je datgene oplossen wat de foutmelding aangeeft en probeer je het opnieuw totdat je de melding van het vorige punt in je terminal ziet verschijnen.
6. Sluit de 5V van de Arduino op de + van het breadboard aan.
***LET OP:*** Dit is de andere + op het breadboard dan de + die je bij de basiscode hebt gebruikt.
7. Ga naar het hoofdstuk circuittekening hieronder en sluit alle hardwarecomponenten die onder ‘Benodigdheden’ van deze paragraaf worden genoemd.
8. Wanneer de CS pin op de SD kaart module niet in pin 4 zit van de Arduino kun je die veranderen op regel 28 van de originele code, maar dit wordt afgeraden. De meeste pinnummers zijn gekozen voor de specifieke functie die die pin heeft.

Deze optie is nu klaar voor gebruik.

### LCD scherm: lcd

#### Benodigdheden

- LCD Display 16*2 karakters met witte tekst en blauwe backlight;
- 10Ohm potmeter standaard;
- benodigdheden van de basiscode.

#### Stappen

1. Installeer de libraries: LcdBarGraph by Balazs Kelemen en LiquidCrystal by F Malpartida.
2. Ga naar het hoofdstuk circuittekening hieronder en sluit alle hardwarecomponenten die onder ‘Benodigdheden’ van deze paragraaf worden genoemd.
3. Wanneer je de pinaansluitingen van stap 3 niet hebt gevolgd moet je de juiste pinnummers in de code aanpassen. Dit wordt echter afgeraden, omdat de meeste pinnummers zijn gekozen voor de specifieke functie die die pin heeft.
Ga naar de ‘lcd’ file in de map ‘include’. De nummers die in het object LiguidCrystal staan corresponderen met de aansluitingen van het LCD scherm welke als commentaar achter dit object staan. Verander de cijfers in de pinnummers die jij gebruikt hebt
```c++
LiquidCrystal lcd(Hier rs, Hier e, Hier db4, Hier db5, Hier db6, Hier db7);
```

Deze optie is nu klaar voor gebruik.

### Waterpompsysteem: waterpump

#### Benodigdheden

- Waterslang voor onderwaterpomp – transparant- 1 meter;
- Onderwaterpomp 3-6V;
- Transistor P2N2222AG;
- Diode 1N4001;
- Weerstand 2.2K;
- 3x batterijhouder met losse draden;
- 3x 1.5V AA batterijen;
- Bakje met water;
- benodigdheden van de basiscode.

#### Stappen

1. Sluit een kant van de waterslang aan op de waterpomp.
2. Leg de waterpomp in de bak met water.
3. Leg de andere kant van de waterslang in de plantenbak.
4. Ga naar het hoofdstuk circuittekening hieronder en maak het circuit van het waterpompsysteem met de (hardware)componenten die onder ‘Benodigdheden’ van deze paragraaf worden genoemd verder af.
5. Wanneer je de pinaansluitingen van stap 3 niet hebt gevolgd moet je het juiste pinnummer voor het waterpompsysteem aanpassen. Dit wordt echter afgeraden, omdat de meeste pinnummers zijn gekozen voor de specifieke functie die die pin heeft.
Ga naar de ‘waterpump’ file in de map ‘include’ Verander de variabele 'waterpin' in het pinnummer die jij gebruikt hebt.
```c++
int waterPin = Hier invullen;
```
Deze optie is nu klaar voor gebruik.

### Laatste stap

Wanneer alles aangesloten is, laad je de sketch op de Arduino. Gefeliciteerd, met je werkende PlantMood! :tulip:

## Circuittekening

Hieronder is de tekening te vinden met de aansluitingen voor alle opties. Aan de hand van de opties die gebruikt gaan worden kun je de hardcomponenten aansluiten. Er hoeft niks aangepast te worden wanneer een optie niet gebruikt wordt. Je hoeft simpelweg deze componenten niet aan te sluiten.  
Volg de pinaansluitingen nauwgezet omdat de pinnummers zijn gedefinieerd in de code.
![Circuittekening](https://git.fhict.nl/o-s3/team-projects/oop-a/arduino/-/blob/develop/Images/MoodPlant_Sketch_bb.png)

## Status

Op dit moment bestaat de verzameling code uit een werkende versie. Deze bestaat uit de basiscode en opties die door de gebruiker zelf kunnen worden gekozen.

## Auteur

De PlantMood code is geschreven en wordt onderhouden door het projectteam OOP-A.

## Bijdrage

Deze code staat altijd open voor verbetering en uitbreiding. Wanneer je denkt bij te kunnen dragen willen we je vragen de volgende stappen te doorlopen:

1. Maak een issue aan op git waar je duidelijk uitlegt wat je verandert of toegevoegd wilt zien.
2. Ieder issue wordt bekeken. Het akkoord op de issue wordt in git gegeven.

Bij goedkeuring:

3. Clone het project.
4. Maak via het issue in git een ‘create merge request aan met als source de ‘master’.
5. Wanneer je klaar bent push de branch naar git.
6. Geef in git aan dat het issue is opgelost: WIP: resolve “Naam van issue”.
7. Als de code werkt met de code bekent in de master branch, wordt deze door de onderhouder van PlantMood gepushed naar de master en het issue afgesloten.
