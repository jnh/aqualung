/*                                                     -*- linux-c -*-
    Copyright (C) 2005 Tom Szilagyi

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id$
*/

#ifndef AQUALUNG_DEC_FLAC_H
#define AQUALUNG_DEC_FLAC_H

#include <FLAC/ordinals.h>
#include <FLAC/stream_decoder.h>

#include "../rb.h"
#include "file_decoder.h"


/* size of ringbuffer for decoded FLAC data (in frames) */
#define RB_FLAC_SIZE 262144


typedef struct _flac_pdata_t {
        FLAC__StreamDecoder * flac_decoder;
        rb_t * rb;
        int channels;
        int SR;
        unsigned bits_per_sample;
        FLAC__uint64 total_samples;
        int probing; /* whether we are reading for probing the file, or for real */
        int error;
        FLAC__StreamDecoderState state;
} flac_pdata_t;


decoder_t * flac_decoder_init(file_decoder_t * fdec);
void flac_decoder_destroy(decoder_t * dec);
int flac_decoder_open(decoder_t * dec, char * filename);
void flac_decoder_send_metadata(decoder_t * dec);
void flac_decoder_close(decoder_t * dec);
unsigned int flac_decoder_read(decoder_t * dec, float * dest, int num);
void flac_decoder_seek(decoder_t * dec, unsigned long long seek_to_pos);


#endif /* AQUALUNG_DEC_FLAC_H */

// vim: shiftwidth=8:tabstop=8:softtabstop=8 :  
