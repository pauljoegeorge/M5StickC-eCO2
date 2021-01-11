#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_log.h"
#include "AXP192.h"
#include "m5stickc.h"
#include "mrubyc.h"


static int button_a_flag = 0;
static int button_b_flag = 0;

void c_button_a_pressed(mrb_vm *vm, mrb_value *v, int argc) {
  if(button_a_flag == 1) {
    button_a_flag = 0;
    SET_TRUE_RETURN();
    return;
  }
  SET_FALSE_RETURN();
}

void c_button_b_pressed(mrb_vm *vm, mrb_value *v, int argc) {
  if(button_b_flag == 1){
    button_b_flag = 0;
    SET_TRUE_RETURN();
    return;
  }
  SET_FALSE_RETURN();
}

void buttonEvent(void *handler_arg, esp_event_base_t base, int32_t id, void *event_data) {
  if ((base == button_a.esp_event_base) && (id == BUTTON_PRESSED_EVENT)) {
      button_a_flag = 1;
  }

  if ((base == button_b.esp_event_base) && (id == BUTTON_PRESSED_EVENT)) {
      button_b_flag = 1;
  }
}
