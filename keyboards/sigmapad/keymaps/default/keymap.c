#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1,    KC_2,    KC_3,
        KC_4,    KC_5,    KC_6,
        KC_MUTE, KC_8,    KC_9
    )
};

// Obsługa obracania enkodera
#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU); // Obrót w prawo = głośniej
        } else {
            tap_code(KC_VOLD); // Obrót w lewo = ciszej
        }
    }
    return true;
}
#endif

// Obsługa ekranu OLED 0.91"
#if defined(OLED_ENABLE)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180; // Obraca ekran o 180 stopni
}

bool oled_task_user(void) {
    oled_write_ln("  SIGMAPAD V1 ", false);
    
    led_t led_state = host_keyboard_led_state();
    oled_write_ln(led_state.caps_lock ? "CAPS: ON " : "CAPS: OFF", false);
    
    return false;
}
#endif