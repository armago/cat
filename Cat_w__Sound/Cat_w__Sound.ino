#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>

#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>


int trackNumber = 1; // variable for track number

SdFat sd; // Create SDFat object. 

SFEMP3Shield MP3player; // Create SFEMP3Shield object

//Settings for MP3 player
const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max



#include <Servo.h> // Including servo library
Servo tail;// attach tail servo
Servo paw;// attach paw servo


void setup() {
pinMode(A2, OUTPUT); // trigger pin
pinMode(A3, INPUT); // echo pin
Serial.begin(9600);
pinMode(A0, OUTPUT); // light
pinMode(A1, OUTPUT); // light
  paw.attach(10);// attaching servo  
  tail.attach(5); 
  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}

void loop() {
  // put your main code here, to run repeatedly:
 int distance = getDistance(A2, A3, "cm"); // finding distance of ultrasonic
  Serial.print(distance); // Printing value of ultrasonic
  Serial.println(" centimeters"); // Printing centimeters after value of ultrasonic
  
  if (distance < 30){
   int randomnumber = random(1, 3); // Picking random number
   digitalWrite(A0, HIGH); // Turning on light
   digitalWrite(A1, HIGH); // Turning on other light
   uint8_t result = MP3player.playTrack(trackNumber); //plays track
   delay(1000);
    if (randomnumber == 1){
      tail.write(80);// wags tail
      delay(500);
      tail.write(170); // wags tail
      } else if (randomnumber == 2){
        paw.write(80); // moves paw
        delay(500);
        paw.write(170); // moves paw
        }
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      switchTrack(trackNumber);
    }
}

void switchTrack(int numberTrack){ // Function to switch track numbers
  if (numberTrack == 1){
    numberTrack = 2;
    }
    else if (numberTrack == 2){
      numberTrack == 1;
      }
  }



//function to intialize SD card. Leave it alone unless you know what you're doing.

void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}


//function to intialize MP3 player. Leave it alone unless you know what you're doing

void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}
