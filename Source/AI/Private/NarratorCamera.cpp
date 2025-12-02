#include "NarratorCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"

ANarratorCamera::ANarratorCamera()
{
    PrimaryActorTick.bCanEverTick = true;
    RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
    RootComponent = RootComp;

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(RootComp);
    TurnRate = 45.f;
}

void ANarratorCamera::BeginPlay()
{
    Super::BeginPlay();
}

void ANarratorCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ANarratorCamera::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ANarratorCamera::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ANarratorCamera::Turn);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ANarratorCamera::LookUp);
}

void ANarratorCamera::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaSeconds);
        SetActorLocation(NewLocation);
    }
}

void ANarratorCamera::MoveForward(float Value)
{
    CurrentVelocity.X = FMath::Clamp(Value, -1.0f, 1.0f) * 600.f;
}

void ANarratorCamera::MoveRight(float Value)
{
    CurrentVelocity.Y = FMath::Clamp(Value, -1.0f, 1.0f) * 600.f;
}

void ANarratorCamera::Turn(float Value)
{
    AddControllerYawInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
}

void ANarratorCamera::LookUp(float Value)
{
    AddControllerPitchInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
}
