// WeaponReloadSystem.cpp

#include "WeaponReloadSystem.h"

AWeaponReloadSystem::AWeaponReloadSystem()
{
    // Устанавливаем начальные значения
    bIsReloading = false;
}

void AWeaponReloadSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AWeaponReloadSystem::Reload()
{
    if (!bIsReloading)
    {
        // Запускаем процесс перезарядки
        PerformReload();
    }
}

void AWeaponReloadSystem::PerformReload()
{
    // Время перезарядки, можно настроить под свои нужды
    const float ReloadTime = 2.0f; // Пример: перезарядка занимает 2 секунды

    // Устанавливаем флаг перезарядки
    bIsReloading = true;

    // Устанавливаем таймер для имитации времени перезарядки
    GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &AWeaponReloadSystem::OnReloadComplete, ReloadTime, false);
}

void AWeaponReloadSystem::OnReloadComplete()
{
    // Сбрасываем флаг перезарядки
    bIsReloading = false;

    // Перезарядка завершена, выполняем действия после перезарядки
}

bool AWeaponReloadSystem::IsReloading() const
{
    return bIsReloading;
}
