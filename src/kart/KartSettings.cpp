#include "KartSettings.hpp"

#include <system/RaceConfig.hpp>

// https://decomp.me/scratch/xVuXe
extern "C" Kart::KartSettings* __ct__Q24Kart12KartSettingsFv(
    Kart::KartSettings* self,
    s8 playerIdx,
    System::VehicleId vehicle,
    System::CharacterId character,
    u32 isBike,
    Kart::KartParam* kartParam,
    void* arg6,
    KartDriverDispParams* kartDriverDispParams,
    KartPartsDispParams* kartPartsDispParams,
    BikePartsDispParams* bikePartsDispParams,
    DriverDispParams* driverDispParams) {
  self->isBike = isBike;
  self->vehicle = vehicle;
  self->character = character;
  self->playerIdx = playerIdx;
  self->kartParam = kartParam;
  self->_18 = arg6;
  self->kartDriverDispParams = kartDriverDispParams;
  self->kartPartsDispParams = kartPartsDispParams;
  self->bikePartsDispParams = bikePartsDispParams;
  self->driverDispParams = driverDispParams;
  self->gpStats = nullptr;
  self->raceStats = nullptr;

  if (System::RaceConfig::spInstance->mRaceScenario.mPlayers[(u8)playerIdx].mPlayerType == 0) {
    self->raceStats = (Kart::RaceStats*)operator new(0x14);
    if (System::RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode == 0) {
      self->gpStats = (Kart::GpStats*)operator new(0x1c);
    }
  }
  return self;
}
