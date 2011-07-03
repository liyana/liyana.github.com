#ifndef _FMTHEADERS_H
#define _FMTHEADERS_H	1

#include <sys/types.h>

/* Definitions for .VOC files */

#define VOC_MAGIC	"Creative Voice File\032"

#define DATALEN(bp)	((u_long)(bp.BlockLen[0]) | \
                         ((u_long)(bp.BlockLen[1]) << 8) | \
                         ((u_long)(bp.BlockLen[2]) << 16) )

typedef struct vochead {
  u_char  Magic[20];	/* must be VOC_MAGIC */
  u_short BlockOffset;	/* Offset to first block from top of file */
  u_short Version;	/* VOC-file version */
  u_short IDCode;	/* complement of version + 0x1234 */
} vochead;

typedef struct blockTC {
  u_char  BlockID;
  u_char  BlockLen[3];	/* low, mid, high byte of length of rest of block */
} blockTC;

typedef struct blockT1 {
  u_char  TimeConstant;
  u_char  PackMethod;
} blockT1;

typedef struct blockT8 {
  u_short TimeConstant;
  u_char  PackMethod;
  u_char  VoiceMode;
} blockT8;

typedef struct blockT9 {
  u_int   SamplesPerSec;
  u_char  BitsPerSample;
  u_char  Channels;
  u_short Format;
  u_char   reserved[4];
} blockT9;
  


/* Definitions for Microsoft WAVE format */

/* it's in chunks like .voc and AMIGA iff, but my source say there
   are in only in this combination, so I combined them in one header;
   it works on all WAVE-file I have
*/
typedef struct wavhead {
  u_long	main_chunk;	/* 'RIFF' */
  u_long	length;		/* Length of rest of file */
  u_long	chunk_type;	/* 'WAVE' */

  u_long	sub_chunk;	/* 'fmt ' */
  u_long	sc_len;		/* length of sub_chunk, =16 (rest of chunk) */
  u_short	format;		/* should be 1 for PCM-code */
  u_short	modus;		/* 1 Mono, 2 Stereo */
  u_long	sample_fq;	/* frequence of sample */
  u_long	byte_p_sec;
  u_short	byte_p_spl;	/* samplesize; 1 or 2 bytes */
  u_short	bit_p_spl;	/* 8, 12 or 16 bit */ 

  u_long	data_chunk;	/* 'data' */
  u_long	data_length;	/* samplecount (lenth of rest of block?)*/
} wavhead;

#endif
