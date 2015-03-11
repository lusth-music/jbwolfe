#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

//#define dir "/usr/local/share/samples/cello/"
//#define base "pluck_"
//
//#define dir "/usr/local/share/samples/guitar-electric/"
//#define base "SGM-dis_"
//#define base "lp_"
//#define base "fluid-harm_"
//
#define dir "/usr/local/share/samples/piano/"
#define base "bright_"
//

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano";
char *PROGRAM_VERSION = "0.01";

int main() {
    int instrument;
    int octave = 4;
    int riftCnt;

    songInit();

    instrument = readScale(dir,base);

    setTempo(200);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("piano.rra",0,0);

    setKey(C);
    setMode(IONIAN);

    riftCnt = 0;

goto rift1;
    /* A 50's Progression */
    c(1,H,instrument,octave);
    c(6,H,instrument,octave-1);
    c(4,H,instrument,octave-1);
    c(5,H,instrument,octave-1);
    /* Let's end it with a POWER CHORD! */
    cpower(1, H, instrument, octave);
    cpower2(1, H, instrument, octave);

rift1:;
    rest(W);
    int i;
    for(i=0; i<2; ++i) {
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
    goto rift2;

rift2:;
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

    ++riftCnt;
    if(riftCnt == 2) {
      goto end;
    } else if(riftCnt < 2) {
      goto rift1;
    }

end:;
    closeOutput();

    return 0;
  }
