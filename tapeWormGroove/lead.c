#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/guitar-electric/"
#define base "clean_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "lead";
char *PROGRAM_VERSION = "0.01";

void preintro(void);
void intro(void);
void verse(void);
void refrain(void);
void bridge(void);
void outro(void);

int instrument;
int octave = 3;

int main() {
    songInit();

    instrument = readScale(dir,base);

    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("lead.rra",0,0);

    #include "song"

    closeOutput();
    return 0;
  }

void preintro(void) {
  rest(W);
}

void intro(void){
  goto here;
here:;
  int i;
  for(i=0; i<4; ++i) {
    //b(1, Q, instrument, octave,   "xxx", SX);
    cpower2(1, I, instrument, octave);
    cpower2(1, I, instrument, octave);
    rest(Q);
    b(1, I, instrument, octave+1,   "-x-", SX);
    b(1, I, instrument, octave+1,   "--x", SX);
    b(1, Q, instrument, octave+1,   "x--", SX);

    //b(6, Q, instrument, octave-1, "xxx", SX);
    cpower2(6, I, instrument, octave-1);
    cpower2(6, I, instrument, octave-1);
    b(6, I, instrument, octave, "--x", SX);
    b(6, I, instrument, octave, "--x", SX);
    b(6, Q, instrument, octave, "x--", SX);
    b(6, Q, instrument, octave, "x--", SX);

    //b(4, Q, instrument, octave-1, "xxx", SX);
    cpower2(4, I, instrument, octave-1);
    cpower2(4, I, instrument, octave-1);
    rest(Q);
    b(4, I, instrument, octave, "-x-", SX);
    b(4, I, instrument, octave, "--x", SX);
    b(4, Q, instrument, octave, "x--", SX);

    //b(5, Q, instrument, octave-1, "xxx", SX);
    cpower2(5, I, instrument, octave-1);
    cpower2(5, I, instrument, octave-1);
    b(5, I, instrument, octave, "--x", SX);
    b(5, I, instrument, octave, "--x", SX);
    b(5, Q, instrument, octave, "x--", SX);
    b(5, Q, instrument, octave, "x--", SX);
  }
  return;
}

void bridge(void){
  cchord(2, H, instrument, octave-1, "xxx");
  cchord(2, Q, instrument, octave-1, "x-x");
  cchord(2, Q, instrument, octave-1, "-x-");
  cchord(2, H, instrument, octave-1, "xXx");
  rest(Q);
  cchord(4, H, instrument, octave-1, "xXx");
  cchord(4, Q, instrument, octave-1, "xXx");
  cchord(4, Q, instrument, octave-1, "-x-");
  cchord(4, Q, instrument, octave-1, "x-x");
  cchord(4, H, instrument, octave-1, "xXx");
  rest(Q);
  cchord(1, Q, instrument, octave, "xxx");
  cchord(1, H, instrument, octave, "xxx");
  cchord(3, Q, instrument, octave, "xxx");
  cchord(4, Q, instrument, octave-1, "x-x");
  cchord(4, H, instrument, octave-1, "xXx");
  cchord(5, Q, instrument, octave-1, "xxxX");
  cchord(5, Q, instrument, octave-1, "xxXx");
  cchord(5, Q, instrument, octave-1, "xXxx");
  cchord(5, Q, instrument, octave-1, "Xxxx");

  cchord(1, Q, instrument, octave-1, "xXx");
  cchord(1, Q, instrument, octave-1, "XxX");
  cchord(1, Q, instrument, octave-1, "xXx");
  
  rest(H);
  return;
}

void verse(void){
  cchord(4, W, instrument, octave-1, "xxx");
  cchord(4, H, instrument, octave-1, "x-x");
  cchord(4, Q, instrument, octave-1, "-xx");
  cchord(4, Q, instrument, octave-1, "-xx");
  cchord(4, Q, instrument, octave-1, "xx-");
  cchord(4, Q, instrument, octave-1, "xx-");
  rest(H);
  rest(W);
  cchord(2, W, instrument, octave,   "x-x");
  cchord(6, H, instrument, octave,   "xxx");
  cchord(6, H, instrument, octave,   "x-x");
  cchord(5, I, instrument, octave,   "xxx");
  cchord(5, I, instrument, octave,   "xxx");
  rest(W);
  rest(H);
  rest(Q);
  rest(Q);
  rest(Q);

  return;
}

void refrain(void){
  return;
}

void outro(void){
  cchord(4, Q, instrument, octave-1, "xxx");
  cchord(4, I, instrument, octave,   "x--");
  cchord(4, I, instrument, octave,   "-x-");
  cchord(4, Q, instrument, octave,   "--x");
  rest(Q);
  cchord(5, Q, instrument, octave-1, "xxx");
  cchord(5, I, instrument, octave,   "x--");
  cchord(5, I, instrument, octave,   "-x-");
  cchord(5, Q, instrument, octave,   "--x");
  rest(Q);
  cchord(6, Q, instrument, octave-1, "xxx");
  cchord(6, I, instrument, octave,   "x--");
  cchord(6, I, instrument, octave,   "-x-");
  cchord(6, Q, instrument, octave,   "--x");
  rest(Q);
  cchord(1, Q, instrument, octave,   "xxx");
  cchord(1, I, instrument, octave+1, "x--");
  cchord(1, I, instrument, octave+1, "-x-");
  cchord(1, Q, instrument, octave+1, "--x");
  rest(Q);
  cchord(6, Q, instrument, octave-1, "xxx");
  cchord(6, I, instrument, octave,   "--x");
  cchord(6, I, instrument, octave,   "-x-");
  cchord(6, Q, instrument, octave,   "x--");
  rest(Q);
  cchord(5, Q, instrument, octave-1, "xxx");
  cchord(5, I, instrument, octave,   "--x");
  cchord(5, I, instrument, octave,   "-x-");
  cchord(5, Q, instrument, octave,   "x--");
  cchord(4, Q, instrument, octave-1, "xxx");
  cchord(4, I, instrument, octave,   "--x");
  cchord(4, I, instrument, octave,   "-x-");
  cchord(4, Q, instrument, octave,   "x--");
  cpower(1, Q, instrument, octave);
  rest(Q);
  return;
}

/* 
   // A 50's Progression
c(1,H,instrument,octave);
c(6,H,instrument,octave-1);
c(4,H,instrument,octave-1);
c(5,H,instrument,octave-1);

   // Let's end it with a POWER CHORD!
cpower(1, H, instrument, octave);
cpower2(1, H, instrument, octave);
*/
