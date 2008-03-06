/*
 *  LibVortex:  A BEEP (RFC3080/RFC3081) implementation.
 *  Copyright (C) 2005 Advanced Software Production Line, S.L.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307 USA
 *  
 *  You may find a copy of the license under this software is released
 *  at COPYING file. This is LGPL software: you are welcome to
 *  develop proprietary applications using this library without any
 *  royalty or fee but returning back any change, improvement or
 *  addition in the form of source code, project image, documentation
 *  patches, etc. 
 *
 *  For commercial support on build BEEP enabled solutions contact us:
 *          
 *      Postal address:
 *         Advanced Software Production Line, S.L.
 *         C/ Antonio Suarez N� 10, 
 *         Edificio Alius A, Despacho 102
 *         Alcal� de Henares 28802 (Madrid)
 *         Spain
 *
 *      Email address:
 *         info@aspl.es - http://www.aspl.es/vortex
 */
#ifndef __VORTEX_FRAME_FACTORY_H__
#define __VORTEX_FRAME_FACTORY_H__

#include <vortex.h>

char  *        vortex_frame_build_up_from_params (VortexFrameType   type,
						  int               channel,
						  int               msgno,
						  bool              more,
						  unsigned int      seqno,
						  int               size,
						  int               ansno,
						  const void      * payload);

char  *        vortex_frame_build_up_from_params_s (VortexFrameType   type,
						    int               channel,
						    int               msgno,
						    bool              more,
						    unsigned int      seqno,
						    int               size,
						    int               ansno,
						    const char   *    content_type,
						    const char   *    transfer_encoding,
						    const void   *    payload,
						    int    *          frame_size);


char  *        vortex_frame_seq_build_up_from_params (int  channel_num,
						      int  ackno,
						      int  window_size);

VortexFrame * vortex_frame_create               (VortexCtx       * ctx,
						 VortexFrameType   type,
						 int               channel,
						 int               msgno,
						 bool              more,
						 unsigned int      seqno,
						 int               size,
						 int               ansno,
						 const void      * payload);

VortexFrame * vortex_frame_create_full          (VortexCtx       * ctx,
						 VortexFrameType   type,
						 int               channel,
						 int               msgno,
						 bool              more,
						 unsigned int      seqno,
						 int               size,
						 int               ansno,
						 const char      * content_type,
						 const char      * transfer_encoding,
						 const void      * payload);

VortexFrame * vortex_frame_create_full_ref      (VortexCtx       * ctx,
						 VortexFrameType   type,
						 int               channel,
						 int               msgno,
						 bool              more,
						 unsigned int      seqno,
						 int               size,
						 int               ansno,
						 const char      * content_type,
						 const char      * transfer_encoding,
						 void            * payload);

VortexFrame * vortex_frame_copy                 (VortexFrame      * frame);

char  *       vortex_frame_get_raw_frame         (VortexFrame * frame);

VortexFrame * vortex_frame_get_next              (VortexConnection * connection);

bool          vortex_frame_send_raw              (VortexConnection * connection, 
						  const char  * a_frame, 
						  int           frame_size);

int           vortex_frame_receive_raw           (VortexConnection * connection, 
						  char  * buffer, int  maxlen);

bool          vortex_frame_ref                   (VortexFrame * frame);

void          vortex_frame_unref                 (VortexFrame * frame);

void          vortex_frame_free                  (VortexFrame * frame);

VortexFrame * vortex_frame_join                  (VortexFrame * a, 
						  VortexFrame * b);

VortexFrame * vortex_frame_join_extending       (VortexFrame * a, 
						 VortexFrame * b);

bool          vortex_frame_are_joinable          (VortexFrame * a, 
						  VortexFrame * b);

bool          vortex_frame_are_equal             (VortexFrame * a, 
						  VortexFrame * b);

int           vortex_frame_get_id                (VortexFrame * frame);

VortexFrameType vortex_frame_get_type            (VortexFrame * frame);

const char  * vortex_frame_get_content_type      (VortexFrame * frame);

const char  * vortex_frame_get_transfer_encoding (VortexFrame * frame);

int           vortex_frame_get_mime_header_size  (VortexFrame * frame);

int           vortex_frame_get_channel           (VortexFrame * frame);

VortexChannel * vortex_frame_get_channel_ref     (VortexFrame * frame);

void          vortex_frame_set_channel_ref       (VortexFrame * frame, 
						  VortexChannel * channel);

int           vortex_frame_get_msgno             (VortexFrame * frame);

int           vortex_frame_get_more_flag         (VortexFrame * frame);

int           vortex_frame_get_seqno             (VortexFrame * frame);

int           vortex_frame_get_payload_size      (VortexFrame * frame);

int           vortex_frame_get_content_size      (VortexFrame * frame);

int           vortex_frame_get_ansno             (VortexFrame * frame);

const void *  vortex_frame_get_payload           (VortexFrame * frame);

VortexCtx   * vortex_frame_get_ctx               (VortexFrame * frame);

const char  * vortex_frame_get_ok_message        (void);

char        * vortex_frame_get_error_message     (const char  * code, 
						  const char  * error_content,
						  const char  * xml_lang);

bool          vortex_frame_is_error_message      (VortexFrame * frame,
						  char  ** code,
						  char  ** message);

char        * vortex_frame_get_start_message     (int              channel_num,
						  const char     * serverName, 
						  const char     * profile,  
						  VortexEncoding   encoding,
						  const char     * content_profile,
						  int              profile_content_size);

char        * vortex_frame_get_start_rpy_message (const char  * profile, 
						  const char  * profile_content);

char        * vortex_frame_get_close_message     (int           number,
						  const char  * code,
						  const char  * xml_lang,
						  const char  * close_content);
#endif
