#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NarratorCamera.generated.h"

UCLASS()
class AI_API ANarratorCamera : public APawn
{
    GENERATED_BODY()

public:
    ANarratorCamera();
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void Tick(float DeltaSeconds) override;

protected:
    virtual void BeginPlay() override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);

    UPROPERTY(VisibleAnywhere)
    USceneComponent* RootComp;
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComp;

    FVector CurrentVelocity;
    float TurnRate;
};
