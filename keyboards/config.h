#pragma once

// Czyścimy domyślne piny przypisane przez promicro_rp2040
#undef I2C1_SDA_PIN
#undef I2C1_SCL_PIN

// Podajemy fizyczne piny procesora RP2040 dla Twojego Seeed XIAO (D4 i D5 na schemacie)
#define I2C1_SDA_PIN GP24
#define I2C1_SCL_PIN GP25