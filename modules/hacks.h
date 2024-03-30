#pragma once
#include "../includes.h"
#include "../kiero/minhook/include/MinHook.h"
#include "../il2cpp.h"
#include "../variables.h"
#include "stdio.h"

typedef void(__fastcall* setTargetRecoil_Orig)(void* __this, float recoil, void* method);
setTargetRecoil_Orig setTargetRecoil_Instance = nullptr;

void __fastcall setTargetRecoilDetour(CombatMaster_Battle_Gameplay_Player_PlayerMovement_o* __this, float recoil, void* method) {
    if (EnableNoRecoil) {
        recoil = recoilValue;
    }

    //Call the original function so it resumes/functions like normal.
    setTargetRecoil_Instance(__this, recoil, method);
}


void noRecoil() {                                                                        /*   Put the rva below   */
    void* targetFunction = reinterpret_cast<void*>(reinterpret_cast<char*>(GameAssembly) + setTargetRecoilRVA);

    if (!isSetTargetRecoilHooked) {
        if (MH_CreateHook(targetFunction, &setTargetRecoilDetour, reinterpret_cast<void**>(&setTargetRecoil_Instance)) == MH_OK) {
            MH_EnableHook(targetFunction);
            printf("Hook for PlayerCharacter$$Update enabled successfully.\n");
            isSetTargetRecoilHooked = true;
        }
        else {
            printf("Failed to create and enable the hook for PlayerCharacter$$Update.\n");
        }
    }
}
