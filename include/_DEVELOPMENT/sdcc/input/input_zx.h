
// automatically generated by m4 from headers in proto subdir


#ifndef _INPUT_ZX_H
#define _INPUT_ZX_H

#include <stdint.h>

///////////
// keyboard
///////////

extern int in_inkey(void);

extern int in_key_pressed(uint16_t scancode) __preserves_regs(b,c,d,e);
extern int in_key_pressed_fastcall(uint16_t scancode) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define in_key_pressed(a) in_key_pressed_fastcall(a)


extern uint16_t in_key_scancode(int c);
extern uint16_t in_key_scancode_fastcall(int c) __z88dk_fastcall;
#define in_key_scancode(a) in_key_scancode_fastcall(a)



extern uint16_t in_pause(uint16_t dur_ms);
extern uint16_t in_pause_fastcall(uint16_t dur_ms) __z88dk_fastcall;
#define in_pause(a) in_pause_fastcall(a)


extern int in_test_key(void) __preserves_regs(b,c,d,e);

extern void in_wait_key(void) __preserves_regs(b,c,d,e,h,l);

extern void in_wait_nokey(void) __preserves_regs(b,c,d,e,h,l);


////////////
// joysticks
////////////

extern uint16_t in_stick_keyboard(udk_t *u) __preserves_regs(b,c);
extern uint16_t in_stick_keyboard_fastcall(udk_t *u) __preserves_regs(b,c) __z88dk_fastcall;
#define in_stick_keyboard(a) in_stick_keyboard_fastcall(a)



extern uint16_t in_stick_cursor(void) __preserves_regs(b,c);

extern uint16_t in_stick_fuller(void) __preserves_regs(b,c,d,e);

extern uint16_t in_stick_kempston(void) __preserves_regs(b,c);

extern uint16_t in_stick_sinclair1(void) __preserves_regs(b,c);

extern uint16_t in_stick_sinclair2(void) __preserves_regs(b,c);


////////
// mouse
////////

extern void in_mouse_amx_init(uint16_t x_vector,uint16_t y_vector);
extern void in_mouse_amx_init_callee(uint16_t x_vector,uint16_t y_vector) __z88dk_callee;
#define in_mouse_amx_init(a,b) in_mouse_amx_init_callee(a,b)


extern void in_mouse_amx_reset(void);

extern void in_mouse_amx_setpos(uint16_t x,uint16_t y) __preserves_regs(h,l);
extern void in_mouse_amx_setpos_callee(uint16_t x,uint16_t y) __preserves_regs(h,l) __z88dk_callee;
#define in_mouse_amx_setpos(a,b) in_mouse_amx_setpos_callee(a,b)


extern void in_mouse_amx(uint8_t *buttons,uint16_t *x,uint16_t *y);
extern void in_mouse_amx_callee(uint8_t *buttons,uint16_t *x,uint16_t *y) __z88dk_callee;
#define in_mouse_amx(a,b,c) in_mouse_amx_callee(a,b,c)


extern uint16_t in_mouse_amx_wheel(void);

extern int16_t in_mouse_amx_wheel_delta(void);


extern void in_mouse_kempston_init(void);

extern void in_mouse_kempston_reset(void);

extern void in_mouse_kempston_setpos(uint16_t x,uint16_t y) __preserves_regs(h,l);
extern void in_mouse_kempston_setpos_callee(uint16_t x,uint16_t y) __preserves_regs(h,l) __z88dk_callee;
#define in_mouse_kempston_setpos(a,b) in_mouse_kempston_setpos_callee(a,b)


extern void in_mouse_kempston(uint8_t *buttons,uint16_t *x,uint16_t *y);
extern void in_mouse_kempston_callee(uint8_t *buttons,uint16_t *x,uint16_t *y) __z88dk_callee;
#define in_mouse_kempston(a,b,c) in_mouse_kempston_callee(a,b,c)


extern uint16_t in_mouse_kempston_wheel(void);

extern int16_t in_mouse_kempston_wheel_delta(void);


#endif
