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

void preintro(void);
void intro(void);
void verse(void);
void refrain(void);
void bridge(void);
void outro(void);

int instrument;
int octave = 4;

int main() {
  songInit();

  instrument = readScale(dir,base);

  setStride(0.05);
  setSustain(0.99995);
  setAmplitude(0.4);

  openOutput("drums.rra",0,0);

  #include "song"

  closeOutput();
  return 0;
}

void preintro(void) {
  drumkitKick (1, 1, "x---x---x---x---", SX);
}

void intro(void) {
  goto here;
here:;
  int i;
  for(i=0; i<4; ++i) {
    drumkitSnare (1,1,"xxx-----g-------", SX);
    drumkitSnare (1,1,"xg", SX);
    drumkitSnare (1,1,"xg", SX);
    drumkitSnare (1,1,"xg", SX);
 }
  return;
}

void bridge(void){
  rest(H);
  rest(Q);
  rest(Q);
  rest(H);
  rest(Q);
  rest(H);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(H);
  rest(Q);
  rest(Q);
  rest(H);
  rest(Q);
  rest(Q);
  rest(H);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(Q);

  rest(H);
  return;
}

void verse(void) {
  rest(W);
  rest(H);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(Q);
  rest(H);
  rest(W);
  rest(W);
  rest(H);
  rest(H);
  rest(I);
  rest(I);
  rest(H);
  drumkitSnare (1,1,"x--X--x-xXxXxXxX", SX);
  rest(H);
  rest(Q);
  return;
}

void refrain(void){
  return;
}

void outro(void){
    rest(H);
  int spot;
  int i;
  for(i=0; i<6; ++i) {
    spot = getLocation();
    if(i == 5) {
      drumkitHHOpen  (1, 1, "x---r---r---r---", SX); setLocation(spot);
      drumkitHHClosed(1, 1, "----r---r---r---", SX); setLocation(spot);
      drumkitKick    (1, 1, "----------------", SX);
      rest(W);
      rest(W);
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
  return;
}

