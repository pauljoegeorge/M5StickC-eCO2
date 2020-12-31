#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_log.h"
#include "AXP192.h"
#include "m5stickc.h"
#include "mrubyc.h"

void c_tft_fill(mrb_vm *vm, mrb_value *v, int argc) {
  color_t bg_color;
  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int w = GET_INT_ARG(3);
  int h = GET_INT_ARG(4);
  unsigned char *read_color = GET_STRING_ARG(5);
  char* color = (char *) read_color;
  if(strcmp(color, "RED") == 0){
    bg_color = TFT_RED;
  }else if(strcmp(color, "GREEN") == 0){
    bg_color = TFT_GREEN;
  }else if(strcmp(color, "BLUE") == 0){
    bg_color = TFT_BLUE;
  }else{
    bg_color = TFT_BLACK;
  }
  // TODO: more colors to be added
  TFT_fillRect(x, y, w, h, bg_color);
}

void c_tft_print(mrb_vm *vm, mrb_value *v, int argc) {
  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  unsigned char *input = GET_STRING_ARG(3);
  char* str = (char *) input;
  TFT_print(str, x, y);
}
