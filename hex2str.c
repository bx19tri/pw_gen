#include <stdio.h>

/*
00 NULL  20 SP   40 @    60 `   |   40 @    60 `
01 SOH   21 !    41 A    61 a   |   41 A    61 a
02 STX   22 "    42 B    62 b   |   42 B    62 b
03 ETX   23 #    43 C    63 c   |   43 C    63 c
04 EOT   24 $    44 D    64 d   |   44 D    64 d
05 ENG   25 %    45 E    65 e   |   45 E    65 e
06 ACK   26 &    46 F    66 f   |   46 F    66 f
07 BEL   27 '    47 G    67 g   |   47 G    67 g
08 BS    28 (    48 H    68 h   |   48 H    68 h
09 HT    29 )    49 I    69 i   |   49 I    69 i
0A LF    2A *    4A J    6A j   |   4A J    6A j
0B VT    2B +    4B K    6B k   |   4B K    6B k
0C FF    2C ,    4C L    6C l   |   4C L    6C l
0D CR    2D -    4D M    6D m   |   4D M    6D m
0E SO    2E .    4E N    6E n   |   4E N    6E n
0F SI    2F /    4F O    6F o   |   4F O    6F o
10 DLE   30 0    50 P    70 p   |   50 P    70 p
11 DC1   31 1    51 Q    71 q   |   51 Q    71 q
12 DC2   32 2    52 R    72 r   |   52 R    72 r
13 DC3   33 3    53 S    73 s   |   53 S    73 s
14 DC4   34 4    54 T    74 t   |   54 T    74 t
15 NAK   35 5    55 U    75 u   |   55 U    75 u
16 SYN   36 6    56 V    76 v   |   56 V    76 v
17 ETB   37 7    57 W    77 w   |   57 W    77 w
18 CAN   38 8    58 X    78 x   |   58 X    78 x
19 EM    39 9    59 Y    79 y   |   59 Y    79 y
1A SUB   3A :    5A Z    7A z   |   5A Z    7A z
1B ESC   3B ;    5B [    7B {   |   5B 0    7B 5
1C FS    3C <    5C \    7C |   |   5C 1    7C 6
1D GS    3D =    5D ]    7D }   |   5D 2    7D 7
1E RS    3E >    5E ^    7E ~   |   5E 3    7E 8
1F US    3F ?    5F _    7F DEL |   5F 4    7F 9
*/
void printc(int h)
{
  h &= 0x7f;
  if (h < 0x40) h += 0x40;
  if (0x5b <= h && h <= 0x5f) h -= (0x5b - 0x30);
  if (0x7b <= h && h <= 0x7f) h -= (0x7b - 0x35);

  if (h != 0x40 && h != 0x60) putchar(h);
}

int hex2dec(int h)
{
  if (0x30 <= h && h <= 0x39) return h - 0x30;
  if (0x41 <= h && h <= 0x5A) return h - 0x41 + 10;
  if (0x61 <= h && h <= 0x7A) return h - 0x61 + 10;
  return 0;
}

int main(int argc, char *argv[])
{
  int c;
  int eo = 0; // even or odd
  int h  = 0; // one byte hex
  while ((c = getchar()) != EOF) {
    if (eo) {
      h <<= 4;
      h  += hex2dec(c);
      //printf("%02x", h);
      printc(h);
      eo = 0;
    }
    else {
      h = hex2dec(c);
      eo = 1;
    }
  }
  putchar('\n');
  return 0;
}

