/**
 * @file bladeTrap.c
 * @ingroup Enemies
 *
 * @brief Blade Trap enemy
 */

#include "sound.h"
#include "entity.h"
#include "room.h"
#include "functions.h"

void BladeTrap(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        this->child = GetCurrentRoomProperty(this->type);
        sub_080A2CC0(this, (u16**)&this->child, &this->field_0x74.HWORD);
    }
    if (!(this->direction & 0x80)) {
        LinearMoveUpdate(this);
    }

    if (!(--this->field_0x74.HWORD)) {
        if (!(this->direction & 0x80)) {
            EnqueueSFX(SFX_METAL_CLINK);
        }
        sub_080A2CC0(this, (u16**)&this->child, &this->field_0x74.HWORD);
    }
}
