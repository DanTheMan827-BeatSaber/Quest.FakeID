#include "Hooking.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerDataFileModel.hpp"
#include "GlobalNamespace/PlayerSensitivityFlag.hpp"
#include "GlobalNamespace/PlayerAgreements.hpp"

MAKE_LATE_HOOK_MATCH(PlayerDataFileModel_Load, &GlobalNamespace::PlayerDataFileModel::LoadOrCreateFromJsonString, GlobalNamespace::PlayerData*, GlobalNamespace::PlayerDataFileModel* self, StringW jsonString) {
    auto value = PlayerDataFileModel_Load(self, jsonString);

    if (value->userAgeCategory != GlobalNamespace::UserAgeCategory::Adult) {
        value->userAgeCategory = GlobalNamespace::UserAgeCategory::Adult;
        value->desiredSensitivityFlag = GlobalNamespace::PlayerSensitivityFlag::Explicit;
        value->playerAgreements->playerSensitivityFlagVersion = 3;
    }

    return value;
}
