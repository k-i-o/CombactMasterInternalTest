#pragma once

//I recommend putting variables in sorted namespaces but for simplicity's sake I put them here like this.
bool debug = false;
bool tab = 0;
bool EnableNoRecoil = false;
bool isSetTargetRecoilHooked = false;
float recoilValue = 0.0f;

// Offsets
uintptr_t GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");
// Avoid using long names, but be descriptive for the best looking code | In this case for the tutorial I'll have it be really descriptive.
uintptr_t setTargetRecoilRVA = 0x46D22B0;