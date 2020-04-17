 /*Arduino speaker song tutorial
* This program will play the theme song of the Malayalam movie
* 'Ennu Ninte Moideen'. The song is 'Mukkathe Penne'.
* The song is played on the speaker connected to pin 3 and GND.
* 
* Created 26 Oct 2015
* by Akshay James
* Video at https://www.youtube.com/watch?v=LgtcUxe8fmA
*/

#include"pitches.h"

// notes in the song 'Mukkathe Penne'
int melody1[] = {
NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
NOTE_C4, NOTE_D4,0,                                 

NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
NOTE_C4, NOTE_D4,0,                                       

NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58

NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,

NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
NOTE_C4, NOTE_D4, 0,
NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
NOTE_C4, NOTE_D4, END

};


// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations1[] = {       //duration of the notes
8,4,8,4,
4,4,4,12,
4,4,4,4,4,4,
4,16,4,

8,4,8,4,
4,2,1,1,2,1,1,12,
4,4,4,4,4,4,
4,16,4,

4,4,4,4,4,4,
4,4,4,12,
4,4,4,4,4,4,
4,4,4,12,

4,4,4,4,4,4,
2,1,1,2,1,1,4,8,4,
2,6,4,2,6,4,
2,1,1,16,4,

4,8,4,4,4,
4,16,4,
4,8,4,4,4,
4,20,
};

int melody_err[] = {
  0, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0, END
};

int noteDurations_err[] = {
  8, 4, 2, 2, 4, 4, 4, 4, 4, 4, 0
};

//old macdonald
int melody_farm[]={
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4,//7
  NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_D4,//6
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4,//7
  NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_D4, //7
  NOTE_G4, NOTE_G4, NOTE_G4,       0, NOTE_G4, NOTE_G4, NOTE_G4, 0,//8
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,//6
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,//6
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4,//7
  NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,//5 
  END
};

int noteDurations_farm[]={
  4, 4, 4, 4, 4, 4, 8,//7
  4, 4, 4, 4,12, 4,//6
  4, 4, 4, 4, 4, 4, 8,//7
  4, 4, 4, 4,12, 2, 2,//7
  4, 4, 4, 4, 4, 4, 4, 4,//8
  2, 2, 4, 2, 2, 4, //6
  2, 2, 2, 2, 4, 4, //6
  4, 4, 4, 4, 4, 4, 8,//7
  4, 4, 4, 4,12,//5 //59
  0 
};

//Bingo
int melody_bingo[]={
  NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_G3,//There was a far mer had a dog and
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_C4, // bin go was his name o 
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4,  //B I N G O
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, //B I N G O
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, //B I N G O and
  NOTE_B3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_C4, //Bin go was his name o
  END
};

int noteDurations_bingo[]={
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 4, 4,
  4, 4, 2, 2, 4,
  4, 4, 2, 2, 4, 
  4, 4, 2, 2, 2, 2, 
  2, 2, 2, 2, 4, 2,
  0 
};

//waterloo chorus
int melody_yaya[]={
  NOTE_B4, NOTE_B4, NOTE_A4,       0, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_G4, 0, //Wa ter loo I was de feat ed you won the war
  NOTE_B4, NOTE_B4, NOTE_A4,       0, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, 0, //Wa ter loo prom ise to love you for ev er more
  NOTE_B4, NOTE_B4, NOTE_A4,       0, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_G4, 0, //Wa ter loo could nt es cape if I want ed to
  NOTE_B4, NOTE_A4, NOTE_A4,       0, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 0, //Wa ter loo know ing my fate is to be with you
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_A4,       0, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,0 //Wa wa wa wa wa ter loo fi nal ly fac ing my wa ter loo
 END};

int noteDurations_yaya[]={
  4, 1, 4, 6, 4, 1, 2, 4, 1, 2, 4, 1, 4, 16,
  4, 1, 4, 6, 4, 1, 2, 4, 1, 2, 4, 1, 4, 16,
  4, 1, 4, 6, 4, 1, 2, 4, 1, 2, 4, 1, 4, 16,
  4, 1, 4, 6, 4, 1, 2, 4, 1, 2, 4, 1, 4, 16,
  4, 4, 4, 2, 4, 1, 4, 4, 4, 1, 2, 4, 1, 2, 4, 1, 4,16
};

const int speaker=8;
const int ledPin=13;

int incomingByte = 0; // for incoming serial data

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);//LED Pin for testing
}

void loop() {
    if (Serial.available() > 0) {
    // read the incoming byte:
      incomingByte = Serial.read();
      //W waterloo, B bingo, M old macdonald, S secret, E error song
    if (incomingByte=='E'){
      playSong(melody_err,noteDurations_err,90);
    } else if (incomingByte=='B'){
      playSong(melody_bingo,noteDurations_bingo,90);
    } else if (incomingByte=='M'){
      playSong(melody_farm,noteDurations_farm,90);
    } else if (incomingByte=='S'){
      playSong(melody1,noteDurations1,90);
    } else if (incomingByte=='W'){
      playSong(melody_yaya,noteDurations_yaya,90);
    } else {
      digitalWrite(ledPin,HIGH);
      delay(1000);
    }
    }
    digitalWrite(ledPin,LOW);

}

void playSong(int melody[], int noteDurations[],int speed){
    for (int thisNote=0; melody[thisNote]!=END; thisNote++) {
      int noteDuration=speed*noteDurations[thisNote];
      tone(speaker,melody[thisNote],noteDuration*.95);
      Serial.println(melody[thisNote]);
      delay(noteDuration);
      noTone(speaker);
    }
}

