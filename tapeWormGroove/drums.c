#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/"
#define base "drums"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

int main() {
    int instrument;
    int octave = 4;
    int spot;
    int riftCnt;

    songInit();

    instrument = readScale(dir,base);

    setTempo(200);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.4);

    openOutput("drums.rra",0,0);

    riftCnt = 0;

    drumkitKick (1, 1, "x---x---x---x---", SX);
    goto rift1;

rift1:;
    int i;
    for(i=0; i<2; ++i) {
      drumkitSnare (1,1,"XXX-----g-------", SX);
      drumkitSnare (1,1,"xg", SX);
      drumkitSnare (1,1,"xg", SX);
      drumkitSnare (1,1,"xg", SX);
    }
    goto rift2;

rift2:;
    for(i=0; i<6; ++i) {
      spot = getLocation();
      if(i == 5) {
        drumkitHHOpen  (1, 1, "x---r---r---r---", SX); setLocation(spot);
        drumkitHHClosed(1, 1, "----r---r---r---", SX); setLocation(spot);
        drumkitKick    (1, 1, "----------------", SX);
        rest(Q);
        //drumkitHHOpen  (1, 1, "r-------r", SX); setLocation(spot);
        //drumkitHHClosed(1, 1, "G---x---G", SX); setLocation(spot);
        //drumkitKick    (1, 1, "x---x---x", SX);
      } else {
        drumkitHHOpen  (1, 1, "x---G---G---G---", SX); setLocation(spot);
        drumkitHHClosed(1, 1, "----x---x---x---", SX); setLocation(spot);
        drumkitKick    (1, 1, "----------------", SX);
        //drumkitHHOpen  (1, 1, "x-------x", SX); setLocation(spot);
        //drumkitHHClosed(1, 1, "----x----", SX); setLocation(spot);
        //drumkitKick    (1, 1, "x---x---x", SX);
      }
    }

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
