#include "mrubyc.h"

void c_button_a_pressed(mrb_vm *vm, mrb_value *v, int argc);
void c_button_b_pressed(mrb_vm *vm, mrb_value *v, int argc);
void buttonEvent(void *handler_arg, esp_event_base_t base, int32_t id, void *event_data);
