#include <LiquidCrystal.h>
#include <cpe123.h>
#include <avr/pgmspace.h>
#define C0  16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
int YankeeNotes[] = {C4,C4,D4,E4,C4,E4, D4, C4, C4, D4, E4, C4, B3, C4, C4, D4, E4, F4, E4, D4, C4, B3, G3, LA3, B3, C4, C4};
int YankeeDur[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2};
String songs[] = {"Pokemon Theme", "Zelda Theme", "Totoro Theme", "Animal Crossing", "Wii Sports", "Imperial March", "Super Smash Bros", "MarioKart"};
const int PROGMEM PokemonNotes[] = {G3, B3, D4, Gb4, G4, G4, 0, G4, G4, G4, G4, G4, F4, F4, F4, F4, F4, Gb4, G4, B4, D5, C4, F4, F5, E5, Eb5, D5, F4, E4, Eb4, D4, C4, B3, C4, G4, B4, D5, 0, F5, E5, F5, G5, 
                      Bb5, G5, LA5, Bb5, F5, F5, F4, Bb5, B5, C6, G5, G5, G4, C6, Db6, D6, 0, D5, 0, D5, 0, D5, 0, D5, 0, D5, 0, D5, C6, C6, Db6, D6, 0, D5, 0, D5, 0, D5, 0, D5, D5, 0, D5, 0, D5};
const int PROGMEM PokemonDur[] = {16, 16, 16, 16, 4, 4, 8, 16, 16, 4, 4, 4, 12, 12, 12, 12, 12, 12, 8/3, 8, 2, 8/3, 8, 8/3, 16, 16, 2, 8/3, 16, 16, 2, 3, 3, 3, 8/3, 8, 2, 2, 3, 3, 3, 8/3, 8, 1, 2, 8/3, 8, 
                    2, 2, 4, 4, 8/3, 8, 2, 2, 4, 4, 16, 8, 16, 16/3, 16, 16/3, 16, 16/3, 16, 16/3, 16, 16/3, 16, 3, 3, 3, 16, 8, 16, 16/3, 16, 16/3, 16, 16/3, 16, 16, 8, 16, 16/3, 16};
const int PROGMEM ZeldaNotes[] = {Bb4, F4, Bb4, Bb4, C5, D5, Eb5, F5, Bb4, Bb4, C5, D5, Eb5, F5, Bb4, F4, Bb4, Bb4, C5, D5, Eb5, F5, Bb4, Bb4, C5, D5, Eb5, F5, Bb4, F4, Bb4, Bb4, C5, D5, Eb5,
                    F5, F5, F5, F5, Gb5, Ab5, Bb5, Bb5, Bb5, Ab5, Gb5, Ab5, Gb5, F5, F5, Eb5, Eb5, F5, Gb5, F5, Eb5, Db5, Db5, Eb5, F5, Eb5, Db5, C5, C5, D5, E5, G5, F5, F4, F4, F4, F4, F4, F4,
                    F4, F4, F4, F4, Bb4, F4, Bb4, Bb4, C5, D5, Eb5, F5, F5, F5, F5, Gb5, Ab5, Bb5, Db6, C6, Ab5, F5, E3, Bb3, Db4, E4, Bb4, Db5, E5, Bb5, LA5, F5, F5, E3, Bb3, Db4, E4, Bb4, 
                    Db5, E5, Bb5, LA5, F5, D5, Eb5, Gb5, F5, Db5, Bb4, C5, C5, D5, E5, G5, F5, F4, F4, F4, F4, F4, F4, F4, F4, F4, F4};
const int PROGMEM ZeldaDur[] = {4, 8/3, 8, 16, 16, 16, 16, 8, 8, 16, 16, 16, 16, 2, 4, 8/3, 8, 16, 16, 16, 16, 8, 8, 16, 16, 16, 16, 2, 4, 8/3, 8, 16, 16, 16, 16, 2, 8, 8, 12, 12, 12, 8/5, 8, 12, 12, 12, 16/3, 16, 2,
                    4, 8, 16, 16, 2, 8, 8, 8, 16, 16, 2, 8, 8, 8, 16, 16, 2, 4, 8, 16, 16, 8, 16, 16, 8, 16, 16, 8, 8, 4, 8/3, 8, 16, 16, 16, 16, 2, 8, 8, 12, 12, 12, 4/3, 4, 4, 2, 4, 12, 12, 12, 12, 12, 12,
                    4, 4, 4, 2, 4, 12, 12, 12, 12, 12, 12, 4, 4, 4, 2, 4, 4/3, 4, 4, 2, 4, 8, 16, 16, 2, 4, 8, 16, 16, 8, 16, 16, 8, 16, 16, 8, 8};
const int PROGMEM TotoroNotes[] = {Eb5, F5, C6, Eb6, F6, C7, Eb5, F5, C6, D5, Eb5, Bb5, D6, Eb6, Bb6, D5, Eb5, Bb5, D6, Eb6, Bb6, D5, Eb5, Bb5, D6, Eb6, Bb6, C4, Eb4, F4, F4, G4, Eb4, C4, Eb4, F4, F4, Bb4, G4, G4, Bb4, C5, C5, 
                     C5, Eb5, D5, C5, Bb4, Ab4, G4, F4, G4, C4, Eb4, F4, F4, G4, Eb4, C4, Eb4, F4, Bb4, G4, G4, Bb4, C5, C5, C5, Eb5, D5, C5, G4, C4, Eb4, C4, Eb4, F4, F4, G4, Eb4, C4, Eb4, F4, F4, F4, Bb4, G4, G4, 
                     Bb4, C5, C5, C5, Eb5, D5, C5, Bb4, Ab4, G4, F4, G4, C4, Eb4, F4, F4, G4, Eb4, C5, Eb5, F4, F4, F4, Bb4, G4, G4, Bb4, C5, C5, C5, Eb5, D5, C5, G4, C4, Eb4, C4, 0, C4, B3, Db4, Ab5, Ab5, Db5, Ab5, C6, Db6, Ab6};
const int PROGMEM TotoroDur[] = {16, 16, 4, 16, 16, 4, 16, 16, 8, 16, 16, 4, 16, 16, 2, 16, 16, 4, 16, 16, 2, 16, 16, 4, 16, 16, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 4, 4, 8, 8, 
                      8, 8, 8, 8, 8, 8, 8, 8, 4/3, 8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8/3, 16, 16, 2};
const int PROGMEM BirthdayNotes[] = {G4, G4, LA4, G4, C5, B4, G4, G4, LA4, G4, D5, C5, G4, G4, G5, E5, C5, B4, LA4, F5, F5, E5, C5, D5, C5};
const int PROGMEM BirthdayDur[] = {16/3, 16, 4, 4, 4, 2, 16/3, 16, 4, 4, 4, 2, 16/3, 16, 4, 4, 4, 4, 4, 16/3, 16, 4, 4, 4, 2};
const int PROGMEM AnimalNotes[] = {LA3, 0, LA3, Bb3, 0, Bb3, C4, 0, D4, C4, LA3, F3, D3, F3, G3, F3, F3, 0, Bb3, LA3, 0, LA3, Bb3, 0, Bb3, C4, 0, D4, C4, LA3, F3, D3, F3, Ab3, C4, Eb4, G4, F4, D4, Bb3, Bb3, D4, 
                     F4, C4, LA3, D4, D4, Bb3, D4, F4, C4, LA3, D4, D4, Bb3, D4, Eb4, 0, Eb4, F4, 0, G4, Bb3, Eb4, G4, F4, Eb4, Bb3, Bb3, 0, G3, Bb3, Ab3, Bb3, 0, Bb3, Ab3, Bb3, Eb4, Eb5, C6, LA5, Bb5, C6, C5, Bb5, LA5, F5, G5, 
                     LA5, C5, LA4, Bb4, C5, 0, Bb4, LA4, F4, G4, LA4, D4, G4, C5, LA4, Bb4, C5, 0, D5, C5, LA4, F4, G4, D4, D4, 0, Eb4, 0, Db4, 0, Eb4, F4, Eb4, Db4, 0, F4, 0, G4, F4, Eb4, Bb3, 0, Db4, 0, G4, F4, Eb4, F4};
const int PROGMEM AnimalDur[] = {8, 4, 8, 8, 4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 4, 8, 8/3, 8, 8/5, 8, 4, 8, 8, 4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 8, 8, 8/3, 8, 8, 8/3, 8/3, 8, 2, 4, 8, 4, 8/3, 8/3, 8, 2, 4, 8, 4, 
                   8, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8/5, 1, 8, 8, 8, 8/3, 8, 8/5, 8, 8, 8, 1, 8, 8, 8, 8/3, 8, 8/5, 8, 8, 8, 8/5, 8/3, 1, 8, 8, 8, 8/3, 8, 8/3, 8, 8/3, 8, 2, 2, 8, 
                   8/3, 8/5, 8/3, 8/5, 8/3, 16/9, 16, 16, 8, 4, 8/5, 8/3, 16/9, 16, 16, 8, 4, 8/5, 8/3, 16/9, 16, 16, 8, 4, 1};
const int PROGMEM SportsNotes[] = {B5, Db6, E6, Eb6, Db6, B5, 0, Gb6, Eb5, 0, E5, 0, Gb5, B5, Bb5, B5, Gb5, Eb5, B4, Db5, Eb5, Db5, 0, Eb5, 0, E5, Eb5, E5, Gb5, B5, Db6, B5, 0, B5, Db6, E6, Eb6, Db6, B5, Gb5, Ab5, Db6, Db6, 0, 
                    Db6, Eb6, E6, Eb6, Db6, B5, Gb5, 0, B5, Db6, E6, Eb6, Db6, B5, Gb6, 0, Gb6, Ab6, LA6, Ab6, Gb6, E6, 0, G6, Gb6, E6, D6, 0, F6, E6, D6, C6, G5, E5, C5, F5, C6, C6, 0, F5, E5, B5, B5, E5, Gb5, Ab5, 
                    B5, Ab5, LA5, B5, E6, D6, E6, Gb6, B6, LA6, 0, Ab5, LA5, B5, LA5, Ab5, LA5, E5, LA5, E6, LA6, B6, LA6, Ab6, F6, Gb6, Ab6, 0, Eb6, F6, Gb6, F6, Eb6, Db6, 0, Ab5, Bb5, 0, Eb6, F6, Gb6, F6, Eb6, Db6, 0, Ab6,
                    0, C5, Db5, Eb5, Gb5, Eb5, F5, Gb5, C6, Bb5, C6, Db6, Gb6, Eb5, 0, F5, 0, Gb5, 0, C6, 0, Bb5, Db6};
const int PROGMEM SportsDur[] = {16, 16, 16/3, 16/3, 8, 8, 8, 1, 8/3, 8, 8/3, 8, 16/3, 16/3, 8, 16/3, 16/3, 8, 16/3, 16/3, 8, 1, 2, 8/3, 8, 8/3, 16, 16, 16/3, 16/3, 8, 4, 8, 16, 16, 16/3, 16/3, 8, 4, 8, 4, 8, 2, 8, 16, 16, 16/3, 16/3, 8, 4, 1, 8, 16, 16, 16/3, 16/3,
                   8, 4, 1, 8, 16, 16, 16/3, 16/3, 8, 16/3, 8, 16/3, 16/3, 8, 8, 8, 16/3, 16/3, 16/3, 16/3, 16/3, 16/3, 8, 8/3, 8, 1, 8/3, 8, 8/3, 8, 4/3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 1, 8/3, 16, 16, 8/3, 16, 16, 4, 4, 4, 4, 8/3, 16, 16, 8/3, 16, 
                   16, 4/3, 8, 16, 16, 16/3, 16/3, 8, 8, 8, 4, 4/3, 8, 16, 16, 16/3, 16/3, 8, 8, 8, 1, 4, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 16, 8, 16, 8, 1};
const int PROGMEM ImperialNotes[] = {G4, G4, G4, Eb4, Bb4, G4, Eb4, Bb4, G4, D5, D5, D5, Eb5, Bb4, Gb4, Eb4, Bb4, G4, G5, G4, G4, G5, Gb5, F5, E5, Eb5, E5, 0, Ab4, Db5, C5, B4, Bb4, LA4, Bb4, 0, Eb4, Gb4, Eb4, Gb4, Bb4, G4, Bb4, D5, G5, G4, G4, G5, Gb5, F5, E5, Eb5, E5, 0, Ab4, Db5, C5, B4, Bb4, LA4, Bb4, 0,
                                     Eb4, Gb4, Eb4, Bb4, G4, Eb4, Bb4, G4};
const int PROGMEM ImperialDur[] = {4, 4, 4, 16/3, 16, 4, 16/3, 16, 2, 4, 4, 4, 16/3, 16, 4, 16/3, 16, 2, 4, 16/3, 16, 4, 16/3, 16, 16, 16, 8, 8, 8, 4, 16/3, 16, 16, 16, 8, 8, 8, 4, 16/3, 16, 4, 16/3, 16, 2, 4, 16/3, 16, 4, 16/3, 16, 16, 16, 8, 8, 8, 4, 16/3, 16, 16, 16, 8, 8, 8, 4, 16/3, 16, 4, 16/3, 16, 2};
const int PROGMEM SmashNotes[] = {D4, E4, F4, G4, LA4, G4, LA4, B4, LA4, B4, C5, C5, D5, B4, G4, D4, F4, F4, G4, E4, C4, LA3, D4, D4, D4, G3, G3, D4, E4, F4, G4, LA4, G4, LA4, B4, LA4, B4, C5, D5, C5, B4, D5, E5, F5, G5, F5, 
                                  E5, C5, LA4, D5, 0, C4, C4, D4, D4, B5, C6, D6, E6, F6, F6, G6, F6, E6, G5, E5, D5, C6, D6, E6, E6, F6, E6, E6, D6, 0, Bb5, 0, LA5, Bb5, C6, 0, Bb5, C6, D6, 0, D6, E6, F6, F6, E6, 0, F6, F6, G6, F6, E6, G5, E5, D5, 
                                  C6, D6, E6, E6, F6, E6, D6, D6, 0, Bb5, 0, LA5, Bb5, C6, 0, Bb5, C6, D6, D6, E6, F6, LA6, G6, LA6, Bb6, LA6, E6, Db6, LA5, E5, Db5, LA4, LA6, E6, LA5, LA4, G4, LA4, B4, LA4, B4, C5, C5, D5, B4, G4, D4, F4, F4, 
                                  G4, E4, C4, LA3, D4, C4, C4, D4, D4, D5, E5, F5, G5, LA5, G5, LA5, B5, LA5, B5, C6, D6, C6, D6, D5, E6, F6, G6, F6, E6, C6, LA5, D6, D4};
const int PROGMEM SmashDur[] = {16, 16, 16, 16, 4, 16, 16, 8, 16, 16, 4, 16, 16, 3, 3, 3, 4, 16, 16, 3, 3, 3, 8, 8, 4, 8, 4, 16, 16, 16, 16, 4, 16, 16, 8, 16, 16, 4, 16, 16, 3, 3, 3, 8/3, 16, 16, 3, 3, 3, 2, 8/5, 8, 4, 8, 8, 16, 16, 16, 16, 2, 3, 3, 3, 
                                4, 4, 4, 8, 16, 16, 2, 3, 3, 3, 3, 3/2, 2, 4, 8, 16, 16, 4, 8, 16, 16, 4, 4, 3, 3, 3, 2, 1, 2, 2, 3, 3, 3, 4, 4, 4, 8, 16, 16, 2, 3, 3, 3, 3, 3/2, 2, 4, 8, 16, 16, 4, 8, 16, 16, 2, 3, 3, 3, 2, 4, 4, 1, 12, 12, 12, 12, 12, 12, 4, 3, 3, 3, 4, 16, 16, 8, 16, 16, 4, 
                                16, 16, 3, 3, 3, 4, 16, 16, 3, 3, 3, 8, 8, 4, 8, 8, 16, 16, 16, 16, 8/3, 16, 16, 8/3, 16, 16, 8/3, 16, 16, 3, 3, 3, 6/5, 3, 3, 8/3, 8/3, 4, 1, 1};
const int PROGMEM KartNotes[] = {LA4, B4, B4, Db5, D5, LA4, LA4, D5, Gb5, G5, Gb5, D5, E5, D5, 0, D5, E5, D5, Ab5, LA5, F5, D5, LA4, LA4, D5, LA4, Gb4, LA5, G5, Gb5, G5, Gb5, D5, E5, D5, D5, E5, D5, LA5, F5, D5, LA4, 0, Gb5, D5, B4, LA4, B4, D5, LA4, B4, B4, C5, B4, 0, 
                                 LA4, B4, D5, Gb5, D5, C5, D5, 0, B4, 0, B4, LA4, B4, 0, Gb5, D5, LA4, B4, D5, D5, LA4, B4, D5, E5, Gb5, G5, Gb5, D5, LA5, F5, Eb5, F5, C5, 0, Gb5, G5, G5, G5, 0, F5, Gb5, E5, D5, E5, D5, B4, LA4, B4, D5, E5, D5, C5, C5, Gb5, G5, Gb5, D5, 
                                 B4, D5, E5, B4, G4, G4, C5, B4, G5, Gb5, G5, LA5, Gb5, D5, D5, G5, Gb5, G5, LA5, Gb5, D5, B4, D5, LA4, C5, B4, LA4, G4, G4, B4, G4, LA4, 0, LA4, E4, LA5, LA5, B5, LA5, Ab5, E6, B5, D6, Db6, B5, Db6, D6, LA5, LA5, B5, LA5, Ab5, E6, D6, Gb6, 
                                 D6, Db6, E6, D6, LA4, B4, D5, Gb5, G5, LA5, LA5, LA5, B5, LA5, Ab5, E6, B5, D6, Db6, B5, Db6, D6, LA5, LA5, LA5, B5, LA5, Ab5, E6, D6, F6, D6, Db6, E6, D6};
const int PROGMEM KartDur[] = {16/3, 16/5, 16/3, 16/3, 9/8, 9/8, 8, 8, 8, 8, 8, 16, 8, 16/9, 8, 8, 8, 8, 16, 8, 16/5, 4, 4, 16, 16, 2, 16/5, 8, 8, 8, 8, 8, 16, 8, 16/11, 8, 8, 8, 16/3, 16/3, 4, 8/3, 1, 8, 8, 8, 8, 16, 8, 16/5, 4, 4, 16/3, 16/5, 0, 8, 16, 8, 16/3, 8, 8, 8, 8, 
                               8, 16, 16/3, 16/3, 16/5, 8, 8, 8, 8, 16/3, 16, 8, 8, 8, 8, 8, 8, 8, 16, 16/5, 8, 8, 8, 16, 16/5, 8, 8, 16, 8, 16/5, 16/9, 16, 16, 8, 16, 16/3, 8, 8, 8, 8, 8, 8, 8, 16/3, 16/5, 8, 8, 8, 8, 16, 8, 16/3, 4, 8, 4, 16/3, 16/5, 8, 8, 16, 8, 16/3, 4, 
                               8, 8, 8, 16, 8, 16/3, 8, 8, 4, 8, 4, 16/3, 16/3, 4, 8, 8, 16, 16, 16, 16, 8/3, 2, 16/3, 16/3, 8, 8/3, 4, 8/3, 8, 8, 16/3, 16/3, 16/5, 4/3, 2, 16/3, 16/3, 8, 8/3, 4, 8/3, 4, 4, 16/3, 16/3, 4, 8, 8, 8, 16/3, 16/3, 8, 2, 16/3, 16/3, 8, 8/3, 4, 8/3, 
                               4, 4, 16/3, 16/3, 16/5, 4/3, 2, 16/3, 16/3, 8, 8/3, 4, 8/3, 4, 16/3, 16/3, 1};

int pace = 1000;
int song = 0;
int selection = 0;
int note = -1;
int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;
LiquidCrystal lcd(lcdRSPin, lcdEPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);
Button button2(9);
Button button1(10);
void setup() 
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  lcd.begin(16, 2);
  lcd.print(" Happy Birthday ");
  lcd.setCursor(0, 1);
  lcd.print("     Kellie     ");
  playBirthday();
  lcd.clear();
  song = -1;
  Serial.println(sizeof(KartNotes)/sizeof(int));
  Serial.println(sizeof(KartDur)/sizeof(int));
}
void loop() 
{
  songselect();
  printlcd();
  playSongs();
}
void songselect()
{
  if(button2.isPushed() == true)
  {
    if(selection == 7)
    {
      selection = 0;
      lcd.clear();
    }
    else
    {
      selection++;
      lcd.clear();
    }
  }
  if(button1.isPushed() == true)
  {
    note = -1;
    song = selection;
  }
}
void printlcd()
{
  lcd.setCursor(0, 0);
  lcd.print(songs[selection]);
  lcd.setCursor(0, 1);
  lcd.print("Play        Next");
}
void playSongs()
{
  if(song == 0)
  {
    playPokemon();
  }
  else if(song == 1)
  {
    playZelda();
  }
  else if(song == 2)
  {
    playTotoro();
  }
  else if(song == 3)
  {
    playAnimal();
  }
  else if(song == 4)
  {
    playSports();
  }
  else if(song == 5)
  {
    playImperial();
  }
  else if(song == 6)
  {
    playSmash();
  }
  else if(song == 7)
  {
    playKart();
  }
}
void playBirthday()
{
  for(int note = 0; note < sizeof(BirthdayNotes)/sizeof(int); note++)
  {
    int divisor = pgm_read_word_near(BirthdayDur + note);
    int noted = pgm_read_word_near(BirthdayNotes + note);
    tone(8, noted, pace/divisor);
    delay(pace/divisor + 50);
  }
}
void playPokemon()
{
  static MSTimer timer(100);
  pace = 1000;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(PokemonDur + note);
    int noted = pgm_read_word_near(PokemonNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(PokemonNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playZelda()
{
  static MSTimer timer(100);
  pace = 1250;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(ZeldaDur + note);
    int noted = pgm_read_word_near(ZeldaNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(ZeldaNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playTotoro()
{
  static MSTimer timer(100);
  pace = 2500;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(TotoroDur + note);
    int noted = pgm_read_word_near(TotoroNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(TotoroNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}

void playAnimal()
{
  static MSTimer timer(100);
  pace = 1250;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(AnimalDur + note);
    int noted = pgm_read_word_near(AnimalNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(AnimalNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playSports()
{
  static MSTimer timer(100);
  pace = 1500;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(SportsDur + note);
    int noted = pgm_read_word_near(SportsNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(SportsNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playImperial()
{
  static MSTimer timer(100);
  pace = 1600;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(ImperialDur + note);
    int noted = pgm_read_word_near(ImperialNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(ImperialNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playSmash()
{
  static MSTimer timer(100);
  pace = 1000;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(SmashDur + note);
    int noted = pgm_read_word_near(SmashNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(SmashNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
void playKart()
{
  static MSTimer timer(100);
  pace = 1100;
  if(timer.done() == true)
  {
    note++;
    int divisor = pgm_read_word_near(KartDur + note);
    int noted = pgm_read_word_near(KartNotes + note);
    tone(8, noted, pace/divisor);
    timer.set(pace/divisor + 50);
    if(note == sizeof(KartNotes)/sizeof(int))
    {
      song = -1;
    }
  }
}
