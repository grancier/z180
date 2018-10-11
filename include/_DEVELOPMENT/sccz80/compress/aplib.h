
// automatically generated by m4 from headers in proto subdir


#ifndef _COMPRESS_APLIB_H
#define _COMPRESS_APLIB_H

//////////////////////////////////////////////////////////////////
//                      APLIB DECOMPRESSOR                      //
//////////////////////////////////////////////////////////////////
//                                                              //
// Z80 Decompressor by Maxim                                    //
// http://www.smspower.org/maxim/SMSSoftware/Compressors        //
//                                                              //
// Aplib Originally Created by Jorgen Ibsen                     //
// Copyright (C) 1998-2014 Jorgen Ibsen. All Rights Reserved.   //
// (no source code or binaries taken from this site)            //
// http://www.ibsensoftware.com/products_aPLib.html             //
//                                                              //
// Further information:                                         //
// http://z88dk.cvs.sourceforge.net/viewvc/z88dk/z88dk/libsrc/_DEVELOPMENT/compress/aplib/readme.txt
//                                                              //
//////////////////////////////////////////////////////////////////

extern void __LIB__ aplib_depack(void *dst,void *src);
extern void __LIB__ __CALLEE__ aplib_depack_callee(void *dst,void *src);
#define aplib_depack(a,b) aplib_depack_callee(a,b)



#ifdef __SMS

extern void __LIB__ sms_aplib_depack_vram(void *dst,void *src);
extern void __LIB__ __CALLEE__ sms_aplib_depack_vram_callee(void *dst,void *src);
#define sms_aplib_depack_vram(a,b) sms_aplib_depack_vram_callee(a,b)



#endif

#endif
