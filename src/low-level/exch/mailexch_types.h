/*
 * libEtPan! -- a mail stuff library
 *
 * exhange support: Copyright (C) 2012 Lysann Kessler
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the libEtPan! project nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef MAILEXCH_TYPES_H

#define MAILEXCH_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif


#include <curl/curl.h>

#include <libetpan/mailstream_types.h>


#define MAILEXCH_DEFAULT_RESPONSE_BUFFER_LENGTH 4096


enum {
  MAILEXCH_NO_ERROR = 0,
  MAILEXCH_ERROR_INVALID_PARAMETER,
  MAILEXCH_ERROR_INTERNAL,
  MAILEXCH_ERROR_CONNECT,
  MAILEXCH_ERROR_NO_EWS,
  MAILEXCH_ERROR_AUTODISCOVER_UNAVAILABLE,
  MAILEXCH_ERROR_CANT_LIST,
};

struct mailexch_connection_settings {
  char* as_url;
  char* oof_url;
  char* um_url;
  char* oab_url;
};
typedef struct mailexch_connection_settings mailexch_connection_settings;

struct mailexch {
  size_t exch_progr_rate;
  progress_function* exch_progr_fun;

  mailexch_connection_settings connection_settings;

  CURL* curl;

  char* response_buffer;
  size_t response_buffer_length;
  size_t response_buffer_length_used;
};
typedef struct mailexch mailexch;


#ifdef __cplusplus
}
#endif

#endif