// CustomCharacter.cpp

#include "CustomCharacter.h"

ACustomCharacter::ACustomCharacter()
{
    // Вызов этой функции позволит персонажу поворачиваться куда смотрит камера
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}

void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Привязываем функции управления к кнопкам клавиатуры/контроллера
    PlayerInputComponent->BindAxis("MoveForward", this, &ACustomCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACustomCharacter::MoveRight);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ACustomCharacter::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &ACustomCharacter::StopFire);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ACustomCharacter::Reload);
}

void ACustomCharacter::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ACustomCharacter::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ACustomCharacter::StartFire()
{
    // Действия при начале стрельбы
}

void ACustomCharacter::StopFire()
{
    // Действия при окончании стрельбы
}

void ACustomCharacter::Reload()
{
    // Действия при перезарядке
}
