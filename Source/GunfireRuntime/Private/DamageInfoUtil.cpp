#include "DamageInfoUtil.h"
#include "Templates/SubclassOf.h"

class UDamageType;

void UDamageInfoUtil::SetPower(FDamageInfo& Info, int32 Power) {
}

void UDamageInfoUtil::SetIsSecondaryDamage(FDamageInfo& Info, bool IsSecondaryDamage) {
}

void UDamageInfoUtil::SetDamageType(FDamageInfo& Info, TSubclassOf<UDamageType> DamageType) {
}

void UDamageInfoUtil::SetDamage(FDamageInfo& Info, int32 Damage) {
}

void UDamageInfoUtil::ModifyDamage(FDamageInfo& Info, float Damage, float DamageMod, float DamageScalar) {
}

void UDamageInfoUtil::ModifyCrit(FDamageInfo& Info, float CritChance, float CritDamageMod) {
}

UDamageInfoUtil::UDamageInfoUtil() {
}

