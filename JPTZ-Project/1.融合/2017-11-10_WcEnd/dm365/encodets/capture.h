/*
 * capture.h
 *
 * This header file has the declarations for the capture environment implemented 
 * for the encode demo on DM365 platform.
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef _CAPTURE_H
#define _CAPTURE_H

#include <xdc/std.h>

#include <ti/sdo/dmai/Fifo.h>
#include <ti/sdo/dmai/Pause.h>
#include <ti/sdo/dmai/Rendezvous.h>
#include <ti/sdo/dmai/VideoStd.h>
#include <ti/sdo/dmai/Display.h> 

/* Environment passed when creating the thread */
typedef struct CaptureEnv 
{
    Rendezvous_Handle hRendezvousInit;
    Rendezvous_Handle hRendezvousCapStd;
    Rendezvous_Handle hRendezvousCleanup;
    Rendezvous_Handle hRendezvousPrime;
    Pause_Handle      hPauseProcess;
	Display_Handle    hdisplay;
    Fifo_Handle       hOutFifo;
    Fifo_Handle       hInFifo;
    VideoStd_Type     videoStd;
    Int32             imageWidth;
    Int32             imageHeight;
    Capture_Input     videoInput;
    Bool              previewDisabled;
} CaptureEnv;

/* Thread function prototype */
extern Void *captureThrFxn(Void *arg);
extern Display_Handle gl_hDisplay;


#endif /* _CAPTURE_H */
