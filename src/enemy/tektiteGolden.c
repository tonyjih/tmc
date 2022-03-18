/**
 * @file tektiteGolden.c
 * @ingroup Enemies
 *
 * @brief Golden Tektite enemy
 */

#include "enemy.h"
#include "functions.h"

extern void sub_08038168(Entity*);

extern void (*const TektiteGolden_Functions)(Entity*);
extern void (*const gUnk_080CF4B8[])(Entity*);

void TektiteGolden(Entity* this) {
    EnemyFunctionHandler(this, &TektiteGolden_Functions);
    SetChildOffset(this, 0, 1, -0x10);
}

void TektiteGolden_OnTick(Entity* this) {
    gUnk_080CF4B8[this->action](this);
}

void TektiteGolden_OnCollision(Entity* this) {
    u32 uVar1;

    if (this->confusedTime != 0) {
        Create0x68FX(this, FX_STARS);
    }
    EnemyFunctionHandlerAfterCollision(this, &TektiteGolden_Functions);
    if (this->bitfield == 0x94) {
        this->action = 1;
        this->subAction = 0;
        this->actionDelay = 0x14;
        this->field_0xf = 0;
        this->field_0x80.HALF.LO = 0;
        if (this->z.HALF.HI != 0) {
            this->zVelocity >>= 2;
        } else {
            this->zVelocity = 0;
        }

        InitializeAnimation(this, 0);
    }
}

void TektiteGolden_OnDeath(Entity* this) {
    u32 uVar1;

    if ((this->field_0x3a & 2) == 0) {
        SetGlobalFlag(this->type2);
    }
    if (this->type != 0) {
        uVar1 = 0x59;
    } else {
        uVar1 = 0x58;
    }
    CreateDeathFx(this, 0xff, uVar1);
}

void TektiteGolden_OnConfused(Entity* this) {
    GenericConfused(this);
    if (this->z.HALF.HI != 0) {
        GravityUpdate(this, 0x3000);
    }
}

void sub_08037FA0(Entity* this) {

    if (CheckGlobalFlag(this->type2)) {
        DeleteThisEntity();
    }
    sub_0804A720(this);
    this->action = 1;
    this->subAction = 0;
    this->actionDelay = (Random() & 0x1f) + 0x20;
    this->field_0xf = 0;
    this->field_0x80.HALF.LO = 0;
    InitializeAnimation(this, 0);
}

void sub_08037Fe0(Entity* this) {
    UpdateAnimationVariableFrames(this, 2);
    if (this->actionDelay != 0) {
        this->actionDelay--;
    } else if (this->field_0xf != 0) {
        if (this->frame & ANIM_DONE) {
            this->action = 2;
            this->actionDelay = 6;
            this->field_0xf = 0;
            this->zVelocity = Q_16_16(3.5);
            sub_08038168(this);
            InitializeAnimation(this, 2);
        }
    } else if (this->frame & ANIM_DONE) {
        this->field_0xf = 0x40;
        InitializeAnimation(this, 1);
    }
}

void sub_08038048(Entity* this) {
    s32 temp;
    u32 rand;

    UpdateAnimationVariableFrames(this, 2);
    ProcessMovement0(this);
    temp = this->z.HALF.HI;
    rand = Random() & 0xf;

    if (sub_080044EC(this, 0x3000) == 1) {
        this->action = 3;
        this->subAction = 0;
        this->actionDelay = 0x14;
        InitializeAnimation(this, 3);
        return;
    } else if (this->collisions != 0) {
        sub_0800417E(this, this->collisions);
    } else if ((GetTileUnderEntity(this) & 0xf0) == 0x50) {
        this->direction = (this->direction + 0x10) & 0x1f;
    }

    if (--this->actionDelay == 0) {
        this->actionDelay = rand + 0x10;
        sub_08038168(this);
    }

    if ((this->subAction == 0) && (temp < this->z.HALF.HI)) {
        InitializeAnimation(this, 4);
        this->subAction = 1;
    }

    if (temp < -0xc) {
        this->spriteRendering.b3 = 1;
        this->spriteOrientation.flipY = 1;
    } else {
        this->spriteRendering.b3 = 2;
        this->spriteOrientation.flipY = 2;
    }
}

void sub_08038110(Entity* this) {
    UpdateAnimationVariableFrames(this, 2);
    if (this->frame & ANIM_DONE) {
        if (this->field_0x80.HALF.LO < 5) {
            this->action = 2;
            this->actionDelay = 8;
            this->zVelocity = Q_16_16(3.5);
            sub_08038168(this);
            InitializeAnimation(this, 2);
        } else {
            this->action = 1;
            this->field_0x80.HALF.LO = 0;
            this->actionDelay = 0xc0;
            InitializeAnimation(this, 0);
        }
    }
}

void sub_08038168(Entity* this) {
    u32 temp;

    if (sub_08049FA0(this) == 0) {
        this->direction = sub_08049EE4(this);
    } else if (sub_08049FDC(this, 1) != 0) {
        this->direction = sub_08049F84(this, 1);
    } else {
        temp = (Random() & 0xf) + 0x18;
        this->direction = (temp + this->direction) & 0x1f;
    }
}
