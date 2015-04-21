#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/cello/"
#define base "pluck_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.01";

void intro(void);
void verse(void);
void refrain(void);
void bridge(void);

int instrument;
int octave = 3;

int main() {
    songInit();

    instrument = readScale(dir,base);

    setStride(0.02);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("bass.rra",0,0);

    #include "song"

    closeOutput();
    return 0;
  }

void intro(void){
  rest(W);
  rest(W);
  rest(W);
  rest(H);

  rest(W);
  rest(W);
  rest(W);
  rest(H);
  
  rest(W);
  rest(W);
  rest(W);
  rest(H);
  rest(Q);
  b(3, H, instrument, octave,   "x--", SX);
  b(3, Q, instrument, octave,   "x--", SX);
  b(2, H, instrument, octave,   "x--", SX);
  b(2, Q, instrument, octave,   "x--", SX);
  b(1, H, instrument, octave,   "x--", SX);
  b(1, Q, instrument, octave,   "x--", SX);
  b(0, H, instrument, octave,   "x--", SX);
  b(0, Q, instrument, octave,   "x--", SX);
  /*
  rest(W);
  int i;
  for(i=0; i<2; ++i) {
    //b(1, Q, instrument, octave,   "xxx", SX);
    cpower2(1, I, instrument, octave);
    cpower2(1, I, instrument, octave);
    rest(Q);
    b(1, I, instrument, octave,   "-x-", SX);
    b(1, I, instrument, octave,   "x--", SX);
    b(1, Q, instrument, octave,   "--x", SX);

    //b(6, Q, instrument, octave-1, "xxx", SX);
    cpower2(6, I, instrument, octave-1);
    cpower2(6, I, instrument, octave-1);
    b(6, I, instrument, octave-1, "x--", SX);
    b(6, I, instrument, octave-1, "x--", SX);
    b(6, Q, instrument, octave-1, "--x", SX);
    b(6, Q, instrument, octave-1, "--x", SX);

    //b(4, Q, instrument, octave-1, "xxx", SX);
    cpower2(4, I, instrument, octave-1);
    cpower2(4, I, instrument, octave-1);
    rest(Q);
    b(4, I, instrument, octave-1, "-x-", SX);
    b(4, I, instrument, octave-1, "x--", SX);
    b(4, Q, instrument, octave-1, "--x", SX);

    //b(5, Q, instrument, octave-1, "xxx", SX);
    cpower2(5, I, instrument, octave-1);
    cpower2(5, I, instrument, octave-1);
    b(5, I, instrument, octave-1, "x--", SX);
    b(5, I, instrument, octave-1, "x--", SX);
    b(5, Q, instrument, octave-1, "--x", SX);
    b(5, Q, instrument, octave-1, "--x", SX);
  }
  */
}

void verse(void){
}

void refrain(void){
  cchord(4, W, instrument, octave-1, "xxx");
  //cchord(4, I, instrument, octave-1, "x--");
  //cchord(4, I, instrument, octave-1, "-x-");
  //cchord(4, Q, instrument, octave-1, "--x");
  cchord(5, W, instrument, octave-1, "xxx");
  //cchord(5, I, instrument, octave-1, "x--");
  //cchord(5, I, instrument, octave-1, "-x-");
  //cchord(5, Q, instrument, octave-1, "--x");
  cchord(6, W, instrument, octave-1, "xxx");
  //cchord(6, I, instrument, octave-1, "x--");
  //cchord(6, I, instrument, octave-1, "-x-");
  //cchord(6, Q, instrument, octave-1, "--x");
  cchord(1, W, instrument, octave,   "xxx");
  //cchord(1, I, instrument, octave,   "x--");
  //cchord(1, I, instrument, octave,   "-x-");
  //cchord(1, Q, instrument, octave,   "--x");
  cchord(6, W, instrument, octave-1, "xxx");
  //cchord(6, I, instrument, octave-1, "--x");
  //cchord(6, I, instrument, octave-1, "-x-");
  //cchord(6, Q, instrument, octave-1, "x--");
  cchord(5, W, instrument, octave-1, "xxx");
  //cchord(5, I, instrument, octave-1, "--x");
  //cchord(5, I, instrument, octave-1, "-x-");
  //cchord(5, Q, instrument, octave-1, "x--");
  cchord(4, W, instrument, octave-1, "xxx");
  //cchord(4, I, instrument, octave-1, "--x");
  //cchord(4, I, instrument, octave-1, "-x-");
  //cchord(4, Q, instrument, octave-1, "x--");
  rest(S);
}

void bridge(void){
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
