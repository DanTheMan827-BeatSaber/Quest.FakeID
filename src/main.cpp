#include "main.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "logger.hpp"
#include "modInfo.hpp"
#include "scotland2/shared/modloader.h"
#include "GlobalNamespace/PlayerAgreements.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataFileModel.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerSensitivityFlag.hpp"
#include "OculusStudios/Platform/Core/UserAgeCategory.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

MAKE_HOOK_MATCH(
    PlayerDataFileModel_Load,
    &GlobalNamespace::PlayerDataFileModel::LoadOrCreateFromJsonString,
    GlobalNamespace::PlayerData*,
    GlobalNamespace::PlayerDataFileModel* self,
    StringW jsonString
) {
    auto value = PlayerDataFileModel_Load(self, jsonString);
    if (value->userAgeCategory != OculusStudios::Platform::Core::UserAgeCategory::Adult) {
        value->userAgeCategory = OculusStudios::Platform::Core::UserAgeCategory::Adult;
        value->desiredSensitivityFlag = GlobalNamespace::PlayerSensitivityFlag::Explicit;
        value->playerAgreements->playerSensitivityFlagVersion = 3;
    }
    return value;
}

/// @brief Called at the early stages of game loading
/// @param info The mod info.  Update this with your mod's info.
/// @return
MOD_EXPORT_FUNC void setup(CModInfo& info) {
    // Convert the mod info to a C struct and set that as the modloader info.
    info = modInfo.to_c();
    Logger.info("Completed setup!");
}

/// @brief Called early on in the game loading
/// @return
MOD_EXPORT_FUNC void load() {
    // Initialize il2cpp functions
    il2cpp_functions::Init();
}

/// @brief Called later on in the game loading - a good time to install function hooks
/// @return
MOD_EXPORT_FUNC void late_load() {
    // Get the number of late hooks that will be installed.
    Logger.info("Installing 1 late hook");
    INSTALL_HOOK(Logger, PlayerDataFileModel_Load);
    Logger.info("Finished installing late hook");
}
