#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Agent.generated.h"

UCLASS()
class AI_API AAgent : public AActor
{
    GENERATED_BODY()

public:
    AAgent();

    virtual void Tick(float DeltaSeconds) override;

    // Observations exposed to trainer (position, velocity)
    TArray<float> CollectObservations() const;

    // Apply action from the policy (continuous forces: x,y)
    void OnActionReceived(const TArray<float>& Action);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;
};
