#include "Hooking.hpp"
#include "GlobalNamespace/BeatmapCharacteristicSO.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/MultiplayerModeSettings.hpp"
#include "GlobalNamespace/OverrideEnvironmentSettings.hpp"
#include "GlobalNamespace/PlayerAgreements.hpp"
#include "GlobalNamespace/PlayerAllOverallStatsData.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerLevelStatsData.hpp"
#include "GlobalNamespace/PlayerMissionStatsData.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/PracticeSettings.hpp"
#include "System/Collections/Generic/List_1.hpp"

MAKE_DLOPEN_HOOK_FIND_INSTANCE(PlayerData_ctor, classof(GlobalNamespace::PlayerData*), ".ctor", void, GlobalNamespace::PlayerData* self,
    StringW playerId,
    StringW playerName,
    bool shouldShowTutorialPrompt,
    bool shouldShow360Warning,
    bool agreedToEula,
    bool didSelectLanguage,
    bool agreedToMultiplayerDisclaimer,
    int32_t didSelectRegionVersion,
    StringW selectedAvatarSystemTypeId,
    GlobalNamespace::PlayerAgreements* playerAgreements,
    GlobalNamespace::BeatmapDifficulty lastSelectedBeatmapDifficulty,
    GlobalNamespace::BeatmapCharacteristicSO* lastSelectedBeatmapCharacteristic,
    GlobalNamespace::GameplayModifiers* gameplayModifiers,
    GlobalNamespace::PlayerSpecificSettings* playerSpecificSettings,
    GlobalNamespace::PracticeSettings* practiceSettings,
    GlobalNamespace::PlayerAllOverallStatsData* playerAllOverallStatsData,
    System::Collections::Generic::List_1<GlobalNamespace::PlayerLevelStatsData*>* levelsStatsData,
    System::Collections::Generic::List_1<GlobalNamespace::PlayerMissionStatsData*>* missionsStatsData,
    System::Collections::Generic::List_1<::StringW>* showedMissionHelpIds,
    System::Collections::Generic::List_1<::StringW>* guestPlayerNames,
    GlobalNamespace::ColorSchemesSettings* colorSchemesSettings,
    GlobalNamespace::OverrideEnvironmentSettings* overrideEnvironmentSettings,
    System::Collections::Generic::List_1<::StringW>* favoritesLevelIds,
    GlobalNamespace::MultiplayerModeSettings* multiplayerModeSettings,
    int32_t currentDlcPromoDisplayCount,
    StringW currentDlcPromoId,
    GlobalNamespace::UserAgeCategory userAgeCategory,
    GlobalNamespace::PlayerSensitivityFlag desiredSensitivityFlag) {
        // We're past the hook definition, call it with the age set to adult.
        PlayerData_ctor(
            self,
            playerId,
            playerName,
            shouldShowTutorialPrompt,
            shouldShow360Warning,
            agreedToEula,
            didSelectLanguage,
            agreedToMultiplayerDisclaimer,
            didSelectRegionVersion,
            selectedAvatarSystemTypeId,
            playerAgreements,
            lastSelectedBeatmapDifficulty,
            lastSelectedBeatmapCharacteristic,
            gameplayModifiers,
            playerSpecificSettings,
            practiceSettings,
            playerAllOverallStatsData,
            levelsStatsData,
            missionsStatsData,
            showedMissionHelpIds,
            guestPlayerNames,
            colorSchemesSettings,
            overrideEnvironmentSettings,
            favoritesLevelIds,
            multiplayerModeSettings,
            currentDlcPromoDisplayCount,
            currentDlcPromoId,
            GlobalNamespace::UserAgeCategory::Adult,
            desiredSensitivityFlag
        );
};
